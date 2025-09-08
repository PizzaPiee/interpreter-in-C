#pragma once

#include "../lib/sds/sds.h"

typedef enum {
	TOKEN_EOF = 0,
	TOKEN_ILLEGAL,
} TokenType;

typedef struct {
	TokenType Type;
	sds Literal;
} Token ;

const char* TokenTypeToString(TokenType type);
