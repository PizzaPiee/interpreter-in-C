#include "../lib/unity/src/unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_function_doBlahAndBlah(void) {
  TEST_ASSERT_EQUAL(1, 1);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_function_doBlahAndBlah);
  return UNITY_END();
}
