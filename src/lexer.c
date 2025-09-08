#include "../lib/sds/sds.h"
#include "../include/lexer.h"
#include "../include/tokens.h"

Lexer NewLexer(sds text) {
  Lexer l = { .Text=text };
  LexerReadChar(&l);
  return l;
}

Token NextToken(Lexer* l) {
  Token t;
  SkipWhitespace(l);

  switch (l->c) {
    case 0:
      t = NewToken(TOKEN_ILLEGAL, sdsempty());
    case '+':
      t = NewToken(TOKEN_PLUS, sdsnew("+"));
    case '-':
      t = NewToken(TOKEN_MINUS, sdsnew("-"));
    case '*':
      t = NewToken(TOKEN_ASTERISK, sdsnew("*"));
    case '/':
      t = NewToken(TOKEN_SLASH, sdsnew("/"));
    case '!':
      t = NewToken(TOKEN_BANG, "!");
    case '{':
      t = NewToken(TOKEN_LBRACE, "{");
    case '}':
      t = NewToken(TOKEN_RBRACE, "}");
    case '(':
      t = NewToken(TOKEN_LPAREN, "(");
    case ')':
      t = NewToken(TOKEN_RPAREN, ")");
    default:
      t = NewToken(TOKEN_ILLEGAL, sdsempty());
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
