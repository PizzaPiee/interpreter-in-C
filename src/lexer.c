#include <stdbool.h>
#include "../lib/sds/sds.h"
#include "../include/lexer.h"
#include "../include/tokens.h"

Lexer NewLexer(char* text) {
  Lexer l = { .Text=text };
  LexerReadChar(&l);
  return l;
}

Token NextToken(Lexer* l) {
  Token t;
  SkipWhitespace(l);

  switch (l->c) {
    case 0:
      t = NewToken(TOKEN_ILLEGAL, "");
      break;
    case '+':
      t = NewToken(TOKEN_PLUS, "+");
      break;
    case '-':
      t = NewToken(TOKEN_MINUS, "-");
      break;
    case '*':
      t = NewToken(TOKEN_ASTERISK, "*");
      break;
    case '/':
      t = NewToken(TOKEN_SLASH, "/");
      break;
    case '!':
      t = NewToken(TOKEN_BANG, "!");
      break;
    case '{':
      t = NewToken(TOKEN_LBRACE, "{");
      break;
    case '}':
      t = NewToken(TOKEN_RBRACE, "}");
      break;
    case '(':
      t = NewToken(TOKEN_LPAREN, "(");
      break;
    case ')':
      t = NewToken(TOKEN_RPAREN, ")");
      break;
    default:
      if (IsDigit(l->c)) {
        t = NewToken(TOKEN_INT, ReadInteger(l));
      }
      break;
  }

  LexerReadChar(l);
  return t;
}

void LexerReadChar(Lexer* l) {
  if (l->ReadPos >= sdslen(l->Text)) {
    l->c = 0;
  } else {
    l->c = l->Text[l->ReadPos];
  }

  l->Pos = l->ReadPos;
  l->ReadPos++;
}

char LexerPeekChar(Lexer* l) {
  if (l->ReadPos >= sdslen(l->Text)) {
    return 0;
  }

  return l->Text[l->ReadPos];
}

static void SkipWhitespace(Lexer *l) {
  while (l->c == ' ' || l->c == '\t' || l->c == '\n' || l->c == '\r') {
    LexerReadChar(l);
  }
}

static bool IsDigit(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  }

  return false;
}

static char* ReadInteger(Lexer* l) {
  char* integer = sdsempty();

  while (IsDigit(l->c)) {
    integer = sdscat(integer, &l->c);
    LexerReadChar(l);
  }

  return integer;
}
