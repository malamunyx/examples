#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/* SIGTSTP is CTRL Z */

void handle_sigtstp(int sig) {
	printf("Stop not allowed\n");
}

void handle_sigcont(int sig) {
	printf("Input Number: ");
	fflush(stdout);
}

int main(int argc, char **argv) {
	struct sigaction sa;
	sa.sa_handler = &handle_sigcont; // fn pointer to a signal hander function
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL); // Null for oact: oact holds another sigaction set beforehand.

	//sigaction(SIGTSTP, &sa, NULL); 
	
	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
}
