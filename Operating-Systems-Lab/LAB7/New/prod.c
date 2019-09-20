#include"header.h"
#define FIFO_NAME "/tmp/my_fifo"
#define SIZE PIPE_BUF
#define MEG (1024*1024*10)
int main()
{
	int pfd;
	int res;
	int open_mode=O_WRONLY;
	int sent=0;
	char buffer[SIZE+1];
	if(access(FIFO_NAME,F_OK)==-1)
	{
		res=mkfifo(FIFO_NAME,0777);
		if(res!=0)
			exit(0);
	}
	printf("Process %d opening FIFO O_WRONLY\n",getpid());
	pfd=open(FIFO_NAME,open_mode);
	printf("Process %d result %d\n",getpid(),pfd);
	if(pfd!=-1)
	{
		while(sent<MEG){
			res=write(pfd,buffer,SIZE);
			if(res==-1)
				exit(0);
			sent+=res;
		}
		(void)close(pfd);
	}
	else 
		exit(0);
	printf("Process %d finished\n",getpid());
	exit(EXIT_SUCCESS);
}