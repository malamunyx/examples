#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

int get_argc(char *buf);
void get_argv(char ***argv, char *buf);
void free_argv(char ***argv, int argc);

int main(void) {
	char buf[BUFSIZ];

	while (1) {
		printf("> ");
		char *res = fgets(buf, BUFSIZ, stdin);

		if (res == NULL) {
			printf("\n");
			break;
		}

		buf[strcspn(buf, "\n")] = 0;
		
		int argc = get_argc(buf);
		char **argv = malloc((argc + 1) * sizeof(char *));
		argv[argc] = NULL;
        get_argv(&argv, buf);

		int pid = fork();

		if (pid == 0) {
			int res = execvp(argv[0], argv);
			if (-1 == res) {
				perror("Failed to run program");
				free_argv(&argv, argc);
				return 1;
			}
		} else if (pid > 0) {
			int status;
			int res = waitpid(pid, &status, 0); // Zero bc wait() is also same
			if (-1 == res) {
				perror("Could not wait for program\n");
			} else {
				(0 == status) ?
					printf("Child was successful!\n") :
					printf("Child failed to do task\n");
			}
		} else {
			printf("Failed to fork child process\n");
		}

		free_argv(&argv, argc);
	}

	return 0;
}

int get_argc(char *buf) {
	int cnt = 0;
	int arglen = 0;
	for (int i = 0; buf[i]; i++) {
		if (!isspace(buf[i])) {
			++arglen;
		} else if (arglen > 0 && isspace(buf[i])) {
			++cnt;
			arglen = 0;
		}
	}
	return (arglen > 0) ? cnt + 1 : cnt;
}

void get_argv(char ***argv, char *buf) {
	int arg_idx = 0;
	char *start, *parse, *tok; 
	start = parse = strdup(buf);

	while ((tok = strsep(&parse, " ")) != NULL) {
		if (tok[0] != 0) {
			size_t len = strlen(tok);
			(*argv)[arg_idx] = malloc((len + 1) * sizeof(char));
			memcpy((*argv)[arg_idx++], tok, len + 1);
		}
	}
	free(start);
}
void free_argv(char ***argv, int argc) {
	for (int i = 0; i < argc; i++) {
		free((*argv)[i]);
	}
	free(*argv);
}
