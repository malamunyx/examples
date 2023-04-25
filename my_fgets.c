#include <stdio.h>
#include <unistd.h>

void read_msg(int fd, char *buf, int buflen, char delim) {
	int idx = 0;
	char c;
	do {
		read(fd, &c, 1);

		if (idx < buflen - 1)
			buf[idx++] = c;

	} while (c != delim);

	buf[idx] = '\0';
}

int main(void) {

	char buf[10];

	read_msg(STDIN_FILENO, buf, 10, '\n');

	printf("Got: [%s]\n", buf);
	

	return 0;
}
