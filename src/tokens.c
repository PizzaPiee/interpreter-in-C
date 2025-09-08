#include "../include/tokens.h"

const char* TokenTypeToString(TokenType type) {
  switch (type) {
    case TOKEN_EOF: return "EOF";
    case TOKEN_ILLEGAL: return "ILLEGAL";

    case IDENT: return "IDENT";
    case INT: return "INT";
    case STRING: return "STRING";

    case ASSIGN: return "=";
    case PLUS: return "+";
    case MINUS: return "-";
    case ASTERISK: return "*";
    case SLASH: return "/";
    case BANG: return "!";

    case SEMICOLON: return ";";
    case COMMA: return ",";

    case LBRACE: return "{";
    case RBRACE: return "}";
    case LPAREN: return "(";
    case RPAREN: return ")";

    case EQ: return "==";
    case NEQ: return "!=";
    case GT: return ">";
    case GTEQ: return ">=";
    case LT: return "<";
    case LTEQ: return "<=";

    case LET: return "LET";
    case RETURN: return "RETURN";
    case IF: return "IF";
    case ELSE: return "ELSE";
    case FUNCTION: return "FUNCTION";
    case TRUE: return "TRUE";
    case FALSE: return "FALSE";
    }
}
