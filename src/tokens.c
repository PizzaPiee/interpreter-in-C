#include "../include/tokens.h"
#include "../lib/sds/sds.h"

Token NewToken(TokenType type, char* literal) {
  Token t = {.Type=type, .Literal=literal};
  return t;
}

const char* TokenTypeToString(TokenType type) {
  switch (type) {
    case TOKEN_EOF: return "EOF";
    case TOKEN_ILLEGAL: return "ILLEGAL";

    case TOKEN_IDENT: return "IDENT";
    case TOKEN_INT: return "INT";
    case TOKEN_STRING: return "STRING";

    case TOKEN_ASSIGN: return "=";
    case TOKEN_PLUS: return "+";
    case TOKEN_MINUS: return "-";
    case TOKEN_ASTERISK: return "*";
    case TOKEN_SLASH: return "/";
    case TOKEN_BANG: return "!";

    case TOKEN_SEMICOLON: return ";";
    case TOKEN_COMMA: return ",";

    case TOKEN_LBRACE: return "{";
    case TOKEN_RBRACE: return "}";
    case TOKEN_LPAREN: return "(";
    case TOKEN_RPAREN: return ")";

    case TOKEN_EQ: return "==";
    case TOKEN_NEQ: return "!=";
    case TOKEN_GT: return ">";
    case TOKEN_GTEQ: return ">=";
    case TOKEN_LT: return "<";
    case TOKEN_LTEQ: return "<=";

    case TOKEN_LET: return "LET";
    case TOKEN_RETURN: return "RETURN";
    case TOKEN_IF: return "IF";
    case TOKEN_ELSE: return "ELSE";
    case TOKEN_FUNCTION: return "FUNCTION";
    case TOKEN_TRUE: return "TRUE";
    case TOKEN_FALSE: return "FALSE";

    default: return "UNEXPECTED_TOKEN";
    }
}

TokenType LookupKeyword(char* text) {
  typedef struct Map {
    char* key;
    TokenType value;
  } Map;

  Map stringTokenType[7] = {
    {"let", TOKEN_LET},
    {"return", TOKEN_RETURN},
    {"if", TOKEN_IF},
    {"else", TOKEN_ELSE},
    {"function", TOKEN_FUNCTION},
    {"true", TOKEN_TRUE},
    {"false", TOKEN_FALSE},
  };

  for (int i=0; i < 7; i++) {
    if (sdscmp(text, stringTokenType[i].key) == 0) {
      return stringTokenType[i].value;
    }
  }

  return TOKEN_ILLEGAL;
}
