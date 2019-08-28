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
			sleep(10);
			printf("Child Completed\n");
			exit(1);
		default: 
			sleep(5);
			printf("Parent Completed\n");
			break;
	}
}
