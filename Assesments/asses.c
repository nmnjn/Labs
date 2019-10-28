#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st {
	long int my_msg_type;
	float temp;
};

int main(){
	int msgid;
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid == -1){
		fprintf(stderr, "msgget failed with error= %d\n", errno);
		exit(EXIT_FAILURE);
	}
	int pid = fork();

	if (pid == 0)
	{
		struct my_msg_st some_data_child;
		long int msg_to_receive = 0;
		if(msgid == -1){
			fprintf(stderr, "msgget failed with error: %d\n", errno);
			exit(EXIT_FAILURE);
		}
		if (msgrcv(msgid, (void *)&some_data_child, sizeof(float), msg_to_receive, 0) == -1) {
			fprintf(stderr, "msgrcv failed with error %d\n", errno);
			exit(EXIT_FAILURE);
		}
		printf("The temperature in Centigrade is %f\n", some_data_child.temp);
		float fara = some_data_child.temp*9/5 + 32;	
		printf("The temperature in Farenheit is %f\n", fara);
	}else{
		struct my_msg_st some_data_parent;
		printf("Enter some temp: ");
		float temp;
		scanf("%f", &temp);
		some_data_parent.my_msg_type = 1;
		some_data_parent.temp = temp;
		if (msgsnd(msgid, (void *)&some_data_parent, sizeof(float), 0) == - 1){
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
	}

	if (msgctl(msgid, IPC_RMID, 0) == -1) {
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}


