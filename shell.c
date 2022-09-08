#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - a simple shell that runs commands with their full path without
 * and commandline argument
 *
 * Return: always zero
 */

int main(void)
{
	while (1)
	{
		ssize_t nread;
		char *lineptr, *token, *delim, *argv[2];
		char *envp[] = {NULL};

		size_t *n, m;
		pid_t childpid;

		int wstatus, exe_status;

		/*FILE *stream;*/
		printf("Zombi$ ");
		lineptr = malloc(*n);
		/**stream = stdin;*/
		n = &m;
		delim = " ";
		nread = getline(&lineptr, n, stdin);
		if (nread < 0)
		{
			puts("Getline error.");
			exit (EXIT_FAILURE);
		}
		token = strtok(lineptr, delim);
		if (token == NULL)
		{
			puts("strtok error.");
			continue;
		}

		argv[0] = token;
		printf("%s\n", token);
		argv[1] = NULL;
		childpid = fork();
		if (childpid < 0)
		{
			puts("No child process created");
			exit(EXIT_FAILURE);
		}
		if (childpid != 0)
		{
			exe_status = execve(argv[0], argv, envp);
			printf("execve status: %d\n", exe_status);
			/*_exit(EXIT_SUCCESS);*/
			sleep(.1);
		}
		else
			wait(&wstatus);
		free(lineptr);

	}

	return (0);
}
