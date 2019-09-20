#include"header.h"
#define FIFO_NAME "/tmp/my_fifo"
int main()
{
	int pfd;
	int res;
	int open_mode=O_WRONLY;
	int sent=0;
	int buffer[]={1,2,3,4};
	if(access(FIFO_NAME,F_OK)==-1)
	{
		res=mkfifo(FIFO_NAME,0777);
		if(res!=0)
			exit(0);
	}
	printf("Process %d opening\n",getpid());
	pfd=open(FIFO_NAME,open_mode);
	printf("Process %d result %d\n",getpid(),pfd);
	if(pfd!=-1)
	{
		res=write(pfd,buffer,sizeof(buffer));
		(void)close(pfd);
	}
	else 
		exit(0);
	printf("Process %d finished\n",getpid());
	exit(EXIT_SUCCESS);
}