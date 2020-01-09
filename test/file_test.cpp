//
// Created by mojiajun on 2020/1/7.
//

#include "../src/file.h"

#include <string>
#include "glog/logging.h"
#include "gtest/gtest.h"

#include "../src/coding.h"

using namespace tinykvdb;

class FileTest : public ::testing::Test {
 public:
  // 路径设置为./test_file_01这种, 使得生产的临时文件产生于和file_test可执行文件同级目录下
  FileTest() : db_(tinykvdb::File::Newfile("./test_file_01")) {}

 public:

  std::unique_ptr<tinykvdb::File> db_;

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(FileTest, AppendData) {
    const std::string key = "test_key";
    const std::string value = "test_value";
    uint64_t file_offset;
    bool status = db_->AppendData(key, value, &file_offset);
    LOG(INFO) << "current file_offset is " << file_offset;
    LOG(INFO) << "file->AppendData(key, value, &file_offset) return " << status;
}

TEST_F(FileTest, Read) {
    const std::string key = "test_key_02";  // size 11
    const std::string value = "test_value_02";  // size 13
    uint64_t file_offset;
    bool status = db_->AppendData(key, value, &file_offset);
    LOG(INFO) << "current file_offset is " << file_offset;
    LOG(INFO) << "file->AppendData(key, value, &file_offset) return " << status;

    uint32_t datasize = key.size() + value.size();
    LOG(INFO) << "datasize " << datasize;
    //uint32_t datasize = 24;
    char buf[datasize];
    uint64_t file_offset_after = db_->FileOffset();
    LOG(INFO) << "current file_offset_after is " << file_offset_after;
    bool readStatus = db_->Read(buf, file_offset_after - datasize, datasize);
    ASSERT_EQ(readStatus, true);

    std::string decode_str;
    DecodeData(buf, key.size(), value.size(), &decode_str);
    LOG(INFO) << "the content of Read() (decode) is " << decode_str;
}
