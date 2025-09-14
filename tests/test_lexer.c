#include "../lib/unity/src/unity.h"
#include "../lib/sds/sds.h"
#include "../src/lexer.c"
#include "tokens.h"
#include <stdio.h>

void setUp(void) {}

void tearDown(void) {}

void test_Lexer_NextToken(void) {
  sds input = sdsnew("+=-{}");
  Lexer lexer = NewLexer(input);

  Token t;
  t = NextToken(&lexer);

  printf("%s\n", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("+"), TokenTypeToString(t.Type));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_Lexer_NextToken);
  return UNITY_END();
}
