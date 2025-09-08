#pragma once

#include "../lib/sds/sds.h"

typedef enum {
	TOKEN_EOF = 0,
	TOKEN_ILLEGAL,

	TOKEN_IDENT,
	TOKEN_INT,
	TOKEN_STRING,

	TOKEN_ASSIGN,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_ASTERISK,
	TOKEN_SLASH,
	TOKEN_BANG,

	TOKEN_SEMICOLON,
	TOKEN_COMMA,

	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_LPAREN,
	TOKEN_RPAREN,

	TOKEN_EQ,
	TOKEN_NEQ,
	TOKEN_GT,
	TOKEN_GTEQ,
	TOKEN_LT,
	TOKEN_LTEQ,

	TOKEN_LET,
	TOKEN_RETURN,
	TOKEN_IF,
	TOKEN_ELSE,
	TOKEN_FUNCTION,
	TOKEN_TRUE,
	TOKEN_FALSE,
} TokenType;

typedef struct {
	TokenType Type;
	sds Literal;
} Token ;

const char* TokenTypeToString(TokenType type);
Token NewToken(TokenType type, sds literal);
