#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int status;
	pid_t pid;
	pid = fork();
	switch(pid){
		case -1:
			perror("Fork Failed\n");
			exit(1);
		case 0:
			printf("Inside Child\n");
			printf("The child pid is: %d\n", getpid());
			printf("The parent pid is: %d\n", getppid());
			printf("The process id is: %d\n", pid);
			printf("\n");
			exit(1);
		default: 
			wait(&status);
			printf("Inside Parent\n");
			printf("The child pid is: %d\n", getpid());
			printf("The parent pid is: %d\n", getppid());
			printf("The process id is: %d\n", pid);
			printf("\n");
			break;
	}
}