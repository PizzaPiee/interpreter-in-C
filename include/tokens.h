#pragma once

#include "../lib/sds/sds.h"

typedef enum {
	TOKEN_EOF = 0,
	TOKEN_ILLEGAL,

	IDENT,
	INT,
	STRING,

	ASSIGN,
	PLUS,
	MINUS,
	ASTERISK,
	SLASH,
	BANG,

	SEMICOLON,
	COMMA,

	LBRACE,
	RBRACE,
	LPAREN,
	RPAREN,

	EQ,
	NEQ,
	GT,
	GTEQ,
	LT,
	LTEQ,

	LET,
	RETURN,
	IF,
	ELSE,
	FUNCTION,
	TRUE,
	FALSE,
} TokenType;

typedef struct {
	TokenType Type;
	sds Literal;
} Token ;

const char* TokenTypeToString(TokenType type);
