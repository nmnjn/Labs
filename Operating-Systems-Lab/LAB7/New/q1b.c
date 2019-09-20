#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX_TEXT 512
struct my_msg_st
{
	long int my_msg_type;
	int num;
};
int main()
{
	int running=1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_recv=0;
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid==-1)
	{
		fprintf(stderr, "msgget failed with error:%d\n",errno );
		exit(EXIT_FAILURE);
	}
	while(running)
	{
		if(msgrcv(msgid,(void*)&some_data,MAX_TEXT,msg_to_recv,0)==-1)
		{

			fprintf(stderr, "msgrcv failed with error:%d\n",errno);
			exit(EXIT_FAILURE);
		}
		int tmp=some_data.num;
		int n=some_data.num;
		int res=0;
		while(tmp!=0)
		{
			int dig=tmp%10;
			res=res*10+dig;
			tmp=tmp/10;
		}
		if(n==res)
			printf("%d is palindrome\n",n );
		else
			printf("%d is not palindrome\n",n);
		running =0;
	}
	if(msgctl(msgid,IPC_RMID,0)==-1)

	{

		fprintf(stderr, "msgctl failed" );
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}