#include <stdio.h>
#include "../lib/sds/sds.h"
#include "../include/tokens.h"

int main() {
	sds welcome_msg = sdsnew("Hello, World!");

	printf("%s\n", welcome_msg);
	sdsfree(welcome_msg);

	TokenType v = TOKEN_EOF;
	printf("%s\n", TokenTypeToString(v));

	return 0;
}
