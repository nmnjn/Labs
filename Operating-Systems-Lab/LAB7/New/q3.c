#include"shm_com.h"
int main()
{
	void *memory=(void *)0;
	st *stuff;
	char buffer;
	int shmid;
	int pid=fork();
	shmid=shmget((key_t)1234,sizeof(st),0666|IPC_CREAT);
	if(shmid==-1)
		exit(0);
	memory=shmat(shmid,(void *)0,0);
	if(memory==(void *)-1)
		exit(0);
	printf("Memory attached at %x\n",(int)memory);
	stuff=(st *)memory;
	stuff->wr=0;
	int running=1;
	if(pid==0)
	{
		while(running) {
			if(stuff->wr==1)
			{
				printf("In child\n");
				stuff->buf++;
				stuff->wr=2;
				running=0;
			}
		}
	}
	else {
		while(running) {
			if(stuff->wr==0){
				printf("Enter character: ");
				scanf("%c",&buffer);
				stuff->buf=buffer;
				stuff->wr=1;
			}
			if(stuff->wr==2)
			{
				printf("From child:%c\n",stuff->buf);
				running=0;
			}
		}
	}
	if(shmdt(memory)==-1)
		exit(0);
	if(shmdt(memory)==-1) 
		exit(0);
	exit(EXIT_SUCCESS);
}