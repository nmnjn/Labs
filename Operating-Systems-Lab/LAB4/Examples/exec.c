#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	int status;
	//forl another process here
	pid = fork();
	if (pid < 0)
	{
		perror("Fork Failed");
		exit(-1);
	}else if (pid == 0)
	{
		//child process
		execlp("/bin/ls", "ls", NULL);
	}else{
		//parent will wait for the child
		wait(&status);
		printf("Child Complete\n");
		exit(0);
	}
}