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
			printf("I am the child\n"); 
			exit(0);
		default: 
			printf("Wait Invoked\n");
			wait(&status);
			printf("I am the parent\n");
			printf("Child Returned: %d\n", status);
			break;
	}
}


//wait(&status) causes the parent to sleep until the child
//process has finished execution. The exit status of the child is returned to the parent
