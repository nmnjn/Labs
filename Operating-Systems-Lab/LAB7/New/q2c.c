#include"header.h"
#define FIFO_NAME "/tmp/my_fifo"
int main()
{
	int pfd;
	int res;
	int open_mode=O_RDONLY;
	int buffer[4];
	int bread=0;
	printf("Process %d opening \n",getpid());
	pfd=open(FIFO_NAME,open_mode);
	printf("Process %d result %d\n",getpid(),pfd);
	if(pfd!=-1) {
		res=read(pfd,buffer,sizeof(buffer));
		(void)close(pfd);
	}
	else
		exit(0);
	for(int i=0;i<4;i++)
		printf("%d ",buffer[i]);
	printf("\nProcess %d finished\n",getpid());
	exit(EXIT_SUCCESS);
}