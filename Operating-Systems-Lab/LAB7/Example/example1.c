#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int main(int argc, char const *argv[])
// {
// 	int n;
// 	int fd[2];
// 	char buf[256];
// 	char *data = "hello...this is sample data";
// 	pipe(fd);
// 	write(fd[1], data, strlen(data));
// 	if (n = read(fd[0], buf, 1024) >= 0)
// 	{
// 		buf[n] = 0;
// 		printf("read %d bytes from the pipe:\"%s\"\n",n,buf);
// 	}else{
// 		perror("read");
// 	}
// 	exit(0);
// }

#include <sys/wait.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	
	int pfd[2];
	pid_t cpid;
	char buf;
	assert(argc == 2);
	if (pipe(pfd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		close(pfd[1]);
		while(read(pfd[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pfd[0]);
		exit(EXIT_SUCCESS);
	}else{
		close(pfd[0]);
		write(pfd[1], argv[1], strlen(argv[1]));
		close(pfd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
