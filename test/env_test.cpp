//
// Created by mojiajun on 2020/1/6.
//

#include "../src/env.h"

#include <cstdint>
#include <string>
#include <sys/fcntl.h>
#include "gtest/gtest.h"
#include "glog/logging.h"

using namespace tinykvdb;

class EnvTest : public ::testing::Test {
 public:
  EnvTest() {
  }

 protected:
  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(EnvTest, GetCurrentDir) {
    std::string res;
    env::GetCurrentDir(res);
    //LOG(INFO) << res;
}

TEST_F(EnvTest, FileExist) {
    ASSERT_EQ(true, env::IsFileOrDirExist("/tmp/testfile-01"));
}

TEST_F(EnvTest, DirExist) {
    ASSERT_EQ(true, env::IsFileOrDirExist("/tmp/testdir-01"));
}

TEST_F(EnvTest, CreateDir) {
    std::string dir = "/tmp/tempdir_for_test_2";
    env::CreateDir(dir);
    ASSERT_EQ(true, env::IsFileOrDirExist(dir));
}
