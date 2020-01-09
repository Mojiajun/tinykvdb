//
// Created by mojiajun on 2020/1/9.
//

#include "../src/coding.h"

#include <string>
#include "glog/logging.h"
#include "gtest/gtest.h"

using namespace tinykvdb;

class CodingTest : public ::testing::Test {
 public:

  virtual void SetUp() {
  };

  virtual void TearDown() {
  };
};

TEST_F(CodingTest, DecodeData) {
    std::string test_string = "keydataValuedata";
    const char *buf = test_string.c_str();
    std::string res;
    DecodeData(const_cast<char *>(buf), 7, 9, &res);
    LOG(INFO) << "DecodeData result is " << res;
    ASSERT_EQ("Valuedata", res);
};
