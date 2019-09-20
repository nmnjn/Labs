#include"shm_com.h"
int main()
{
	int running=1;
	void *memory=(void *)0;
	st *stuff;
	char buffer[100];
	int shmid;
	shmid=shmget((key_t)1234,sizeof(st),0666|IPC_CREAT);
	if(shmid==-1)
		exit(0);
	memory=shmat(shmid,(void *)0,0);
	if(memory==(void *)-1)
		exit(0);
	printf("Memory attached at %x\n",(int)memory);
	stuff=(st *)memory;
	while(running)
	{
		while(stuff->wr==1)
		{
			sleep(1);
			printf("waiting for client\n");
		}

		printf("Enter some text: ");
		fgets(buffer,100,stdin);
		strncpy(stuff->buf,buffer,100);
		stuff->wr=1;
		if(strncmp(buffer,"end",3)==0) {
			running=0;
		}
	}
	if(shmdt(memory)==-1) 
		exit(0);
	exit(EXIT_SUCCESS);
}