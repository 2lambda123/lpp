//
// Created by 4c3y (acey) on 06.09.22.
//

#include <gtest/gtest.h>
#include "test_utils.h"

#include "log++.h"

//TODO fix
TEST(LPP_LogEveryN, lpp_syntax) {
  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDOUT(LOG_EVERY(I, 3, "Test"));

    if (i % 3 == 0) {
      ASSERT_TRUE(isSubstring(output, "Test"));
    } else {
      ASSERT_EQ(output, "");
    }
  }
}

TEST(LPP_LogEveryN, glog_syntax) {
  for (int i = 0; i < 5; i++) {
    std::string output = LPP_CAPTURE_STDOUT(LOG_EVERY_N(INFO, 3) << "Test");

    if (i % 3 == 0) {
      ASSERT_TRUE(isSubstring(output, "Test"));
    } else {
      ASSERT_EQ(output, "");
    }
  }
}