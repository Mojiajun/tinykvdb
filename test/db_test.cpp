//
// Created by mojiajun on 2020/1/3.
//

#include "../src/db.h"

#include <memory>
#include "gtest/gtest.h"

using tinykvdb::Kvdb;
using namespace tinykvdb;

class DbTest : public ::testing::Test {
 public:
  DbTest() : db_() { }

 protected:
  Kvdb *db_;

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };

  //bool Put(const std::string &key, const std::string &value) {
  //    db_->Put(key, value);
  //    return true;
  //}

  //bool Delete(const std::string &key) {
  //    db_->Delete(key);
  //    return true;
  //}

  //std::string Get(const std::string &key) {
  //    return db_->Get(key);
  //}
};

//TEST_F(DbTest, Empty) {
//    //ASSERT_EQ(db_ != nullptr);
//    ASSERT_EQ("NOT_FOUND", Get("key"));
//}
//
//TEST_F(DbTest, ReadWrite) {
//    //ASSERT_EQ(db_ != nullptr);
//    ASSERT_EQ(true, Put("key_01", "value_01"));
//    ASSERT_EQ("value_01", Get("key_01"));
//    ASSERT_EQ(true, Put("key_02", "value_02"));
//    ASSERT_EQ(true, Put("key_03", "value_03"));
//    ASSERT_EQ("value_03", Get("key_03"));
//    ASSERT_EQ("value_02", Get("key_02"));
//}
//
//TEST_F(DbTest, WriteDelete) {
//    ASSERT_EQ(true, Put("key_01", "value_01"));
//    ASSERT_EQ("value_01", Get("key_01"));
//    ASSERT_EQ(true, Put("key_01", "value_02"));
//    ASSERT_EQ("value_02", Get("key_01"));
//    ASSERT_EQ(true, Delete("key_01"));
//    ASSERT_EQ("NOT_FOUND", Get("key_01"));
//}

TEST_F(DbTest, Open) {
    const std::string dbname = "testdb";
    bool status;
    std::unique_ptr<Kvdb> kvdb_ptr = tinykvdb::Kvdb::Open(dbname, &status);
}
