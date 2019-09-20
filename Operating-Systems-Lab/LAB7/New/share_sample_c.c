#include"shm_com.h"
int main()
{
	int running=1;
	void *memory=(void *)0;
	st *stuff;
	int shmid;
	srand((unsigned int)getpid());
	shmid=shmget((key_t)1234,sizeof(st),0666|IPC_CREAT);
	if(shmid==-1)
		exit(0);
	memory=shmat(shmid,(void *)0,0);
	if(memory==(void *)-1)
		exit(0);
	printf("Memory attached at %x\n",(int)memory);
	stuff=(st *)memory;
	stuff->wr=0;
	while(running)
	{
		if(stuff->wr) {
			printf("%s\n",stuff->buf);
			sleep(rand()%4);
			stuff->wr=0;
			if(strncmp(stuff->buf,"end",3)==0)
				running=0;
		}
	}
	if(shmdt(memory)==-1)
		exit(0);
	if(shmctl(shmid,IPC_RMID,0)==-1)
		exit(0);
	exit(EXIT_SUCCESS);
}