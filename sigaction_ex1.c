#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo, siginfo_t *sinfo, void *context) {
	printf("I was interrupted\n");
}

int main(void) {
	printf("[%d] starting up!\n", getpid());
	printf("\"kill -9 %d\" to end this program!\n", getpid());
	struct sigaction sig;
	memset(&sig, 0, sizeof(struct sigaction));
	sig.sa_sigaction = sigint_handler;
	sig.sa_flags = SA_SIGINFO;

	while (1) {
		if (sigaction(SIGINT, &sig, NULL) == -1) {
			perror("sigaction failed");
			return 1;
		}
	}

	return 0;
}
