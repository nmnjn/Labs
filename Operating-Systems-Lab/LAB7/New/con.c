#include"header.h"
#define FIFO_NAME "/tmp/my_fifo"
#define SIZE PIPE_BUF
int main()
{
	int pfd;
	int res;
	int open_mode=O_RDONLY;
	char buffer[SIZE+1];
	int bread=0;
	memset(buffer,'\0',sizeof(buffer));
	printf("Process %d opening \n",getpid());
	pfd=open(FIFO_NAME,open_mode);
	printf("Process %d result %d\n",getpid(),pfd);
	if(pfd!=-1) {
		do {
			res=read(pfd,buffer,SIZE);
			bread+=res;
		}while(res>0);
		(void)close(pfd);
	}
	else
		exit(0);
	printf("Process %d finished, %d bytes read\n",getpid(),bread);
	exit(EXIT_SUCCESS);
}