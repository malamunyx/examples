#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_LEN (128)

int main(void) {
	
	char buf[BUF_LEN];

	while (fgets(buf, BUF_LEN, stdin) != NULL) {
		char *start, *parse, *tok;

		buf[strcspn(buf, "\n")] = 0;
		start = parse = strdup(buf);

		while ((tok = strsep(&parse, " ")) != NULL) {
			/* Consecutive delimiters return empty string "" */
			if (tok[0] != 0)
				printf("token: %s\n", tok);
		}

		free(start);
	}

	return 0;
}
