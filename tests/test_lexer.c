#include "../lib/unity/src/unity.h"
#include "../lib/sds/sds.h"
#include "../src/lexer.c"
#include "tokens.h"

void setUp(void) {}

void tearDown(void) {}

void test_Lexer_NextToken(void) {
  sds input = sdsnew(
    "+   ()\n-*/!\t{\r}"
    "10"
  );
  Lexer lexer = NewLexer(input);

  Token t;

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("+"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("+"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("("), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("("), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew(")"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew(")"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("-"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("-"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("*"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("*"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("/"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("/"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("!"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("!"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("{"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("{"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("}"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("}"), t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(sdsnew("INT"), TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(sdsnew("10"), t.Literal);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_Lexer_NextToken);
  return UNITY_END();
}
