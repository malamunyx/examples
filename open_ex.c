#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* 
 * In unix, the default file descriptors:
 * 0: stdin		<READ ONLY>
 * 1: stdout	<WRITE ONLY>
 * 2: stderr	<WRITE ONLY>
 *
 * There are 3 different types of file permissions:
 * - read
 * - write
 * - execute
 * */

int main(void) {
	const char *hw = "Hello World!\n";

	// When we open a new file, that file will get fd = 1
	
	int fd = open("out.txt", O_CREAT | O_WRONLY, 0666);
	write (fd, hw, 13);

	close (fd);


	return 0;
}

