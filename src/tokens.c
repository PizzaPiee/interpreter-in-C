#include "../include/tokens.h"

const char* TokenTypeToString(TokenType type) {
  switch (type) {
    case TOKEN_EOF: return "EOF";
    case TOKEN_ILLEGAL: return "ILLEGAL";
  }
}
