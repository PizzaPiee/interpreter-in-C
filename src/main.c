#include <stdio.h>
#include "../lib/sds/sds.h"

int main() {
	sds welcome_msg = sdsnew("Hello, World!");

	printf("%s\n", welcome_msg);
	sdsfree(welcome_msg);

	return 0;
}
