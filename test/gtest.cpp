#include <gtest/gtest.h>
#include "../BigInteger.h"

TEST(BigIntegerTest, Plus) {
  BigInteger a[] = {"0", "0", "0", "9", "999", "100", "111111"};
  BigInteger b[] = {"0", "1", "9999", "1", "1", "100000", "90"};
  BigInteger expected_res[] = {"0", "1", "9999", "10", "1000", "100100",
      "111201"};
  
  for (int i = 0; i < sizeof(expected_res)/sizeof(BigInteger); ++i) {
    EXPECT_EQ(expected_res[i], a[i]+b[i]);
    EXPECT_EQ(expected_res[i], b[i]+a[i]);
  }
}

TEST(BigIntegerTest, Substract) {
  BigInteger a[] = {"0", "1", "1", "9", "100", "999", "100000000000000000000"};
  BigInteger b[] = {"0", "0", "1", "1", "1", "9", "11"};
  BigInteger expected_res[] = {"0", "1", "0", "8", "99", "990",
      "99999999999999999989"};
  
  for (int i = 0; i < sizeof(expected_res)/sizeof(BigInteger); ++i) {
    EXPECT_EQ(expected_res[i], a[i]-b[i]);
  }
}

TEST(BigIntegerTest, Multiply) {
  BigInteger a[] = {"0", "1111", "1", "9", "100", "999",
      "100000000000000000000", "99999999999999999999"};
  BigInteger b[] = {"0", "0", "1", "1", "9", "9", "11",
      "99999999999999999999"};
  BigInteger expected_res[] = {"0", "0", "1", "9", "900", "8991",
      "1100000000000000000000", "9999999999999999999800000000000000000001"};
  
  for (int i = 0; i < sizeof(expected_res)/sizeof(BigInteger); ++i) {
    EXPECT_EQ(expected_res[i], a[i]*b[i]);
    EXPECT_EQ(expected_res[i], b[i]*a[i]);
  }
}

TEST(BigIntegerTest, Divide) {
  BigInteger a[] = {"0", "3", "1111", "4", "99", "99", "9",
      "1100000000000000000000", "9999999999999999999800000000000000000001"};
  BigInteger b[] = {"1", "10", "1", "2", "99", "11", "2",
      "10000000000000000000", "99999999999999999999"};
  BigInteger expected_res[] = {"0", "0", "1111", "2", "1", "9", "4",
      "110", "99999999999999999999"};
  
  for (int i = 0; i < sizeof(expected_res)/sizeof(BigInteger); ++i) {
    EXPECT_EQ(expected_res[i], a[i]/b[i]);
  }
}
