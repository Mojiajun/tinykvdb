//
// Created by mojiajun on 2020/1/3.
//

#include "../src/db.h"

#include <memory>
#include "glog/logging.h"
#include "gtest/gtest.h"

using namespace tinykvdb;

class DbTest : public ::testing::Test {
 public:

  DbTest() : db_() {
      bool status = false;
      // 这里是不是得用个std::move()?
      db_ = tinykvdb::Kvdb::Open("testdb", &status);
      if (!status) {
          LOG(FATAL) << "Kvdb::Open() fail in DbTest()";
      }
      LOG(INFO) << "DbTest() 构造成功";
  }

 public:
  std::unique_ptr<Kvdb> db_;

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };

  bool Put(const std::string &key, const std::string &value) {
      bool status = db_->Put(key, value);
      return status;
  }

  //bool Delete(const std::string &key) {
  //    db_->Delete(key);
  //    return true;
  //}

  bool Get(const std::string &key, std::string *value) {
      return db_->Get(key, value);
  }
};

//TEST_F(DbTest, Empty) {
//    ASSERT_TRUE(!db_);
//    ASSERT_EQ("NOT_FOUND", Get("key"));
//}
//
TEST_F(DbTest, Write) {
    ASSERT_TRUE(db_);
    ASSERT_EQ(true, Put("key_01", "value_01"));
}

TEST_F(DbTest, WriteAndRead) {
    ASSERT_TRUE(db_);
    const std::string key = "key_02";
    ASSERT_EQ(true, Put(key, "value_02"));
    std::string value;
    bool readStatus = Get(key, &value);
    ASSERT_EQ(readStatus, true);
    LOG(INFO) << "value is " << value;
    ASSERT_EQ(value, "value_02");
}
//
//TEST_F(DbTest, ReadWrite) {
//    ASSERT_TRUE(!db_);
//    ASSERT_EQ(true, Put("key_01", "value_01"));
//    ASSERT_EQ("value_01", Get("key_01"));
//    ASSERT_EQ(true, Put("key_02", "value_02"));
//    ASSERT_EQ(true, Put("key_03", "value_03"));
//    ASSERT_EQ("value_03", Get("key_03"));
//    ASSERT_EQ("value_02", Get("key_02"));
//}
//
//TEST_F(DbTest, WriteDelete) {
//    ASSERT_TRUE(!db_);
//    ASSERT_EQ(true, Put("key_01", "value_01"));
//    ASSERT_EQ("value_01", Get("key_01"));
//    ASSERT_EQ(true, Put("key_01", "value_02"));
//    ASSERT_EQ("value_02", Get("key_01"));
//    ASSERT_EQ(true, Delete("key_01"));
//    ASSERT_EQ("NOT_FOUND", Get("key_01"));
//}
//
//TEST_F(DbTest, Open) {
//    const std::string dbname = "testdb";
//    bool status;
//    std::unique_ptr<Kvdb> kvdb_ptr = tinykvdb::Kvdb::Open(dbname, &status);
//}
