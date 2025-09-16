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
    "ciao false"
  );
  Lexer lexer = NewLexer(input);

  Token t;

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("+", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("+", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("(", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("(", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING(")", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING(")", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("-", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("-", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("*", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("*", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("/", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("/", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("!", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("!", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("{", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("{", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("}", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("}", t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("INT", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("10", t.Literal);
  sdsfree(t.Literal);

  t = NextToken(&lexer);
  TEST_ASSERT_EQUAL_STRING("IDENT", TokenTypeToString(t.Type));
  TEST_ASSERT_EQUAL_STRING("ciao", t.Literal);
  sdsfree(t.Literal);

  sdsfree(input);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_Lexer_NextToken);
  return UNITY_END();
}
