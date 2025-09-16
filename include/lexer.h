#include "../lib/sds/sds.h"

typedef struct {
	sds Text;
	int Pos;
	int ReadPos;
	char c;
} Lexer;

Lexer NewLexer(sds text);
void LexerReadChar(Lexer* l);
char LexerPeekChar(Lexer* l);

static void SkipWhitespace(Lexer *l);
static bool IsDigit(char c);
static char* ReadInteger(Lexer* l);
static bool IsLetter(char c);
static char* ReadText(Lexer* l);
