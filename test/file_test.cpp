//
// Created by mojiajun on 2020/1/7.
//

#include "../src/file.h"

#include <string>
#include "glog/logging.h"
#include "gtest/gtest.h"

using namespace tinykvdb;

class FileTest : public ::testing::Test {
 public:
  FileTest() { }

 protected:
  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(FileTest, AppendData) {
    const std::string key = "test_key";
    const std::string value = "test_value";
    std::unique_ptr<File> file = tinykvdb::File::Newfile("/tmp/file_test");
    uint64_t file_offset;
    bool status = file->AppendData(key, value, &file_offset);
    LOG(INFO) << "current file_offset is " << file_offset;
    LOG(INFO) << "file->AppendData(key, value, &file_offset) return " << status;
}
