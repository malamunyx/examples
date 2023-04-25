#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int num) {
	char *msg = "I won't stop! HAHAHA!\n";
	write(STDOUT_FILENO, msg, strlen(msg));
}

/* Most obnoxious program... 
 * If you want to kill it, do "kill -9 <pid>"
 * */

int main(void) {
	struct sigaction sa;
	sa.sa_handler = handler; // fn pointer to a signal handler
	
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);

	while (1) {
		printf("Wasting your cycles. [%d]\n", getpid());
		sleep(1);
	}

	return 0;
}
