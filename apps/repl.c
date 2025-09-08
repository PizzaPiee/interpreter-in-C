#include <stdio.h>
#include <stdbool.h>

#include "../lib/sds/sds.h"
#include "../include/lexer.h"
#include "../include/tokens.h"

int main() {
	Lexer lexer = NewLexer(sdsnew("Hello, World!"));

	Token t;
	while (true) {
		sds n = sdsempty();

		printf(">> ");
		scanf("%s", n);

		do {
			
		} while (t.Type != TOKEN_ILLEGAL || t.Type != TOKEN_EOF);

	}

	return 0;
}
