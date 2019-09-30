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

int main()
{
	int running = 1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid == -1){
		fprintf(stderr, "msgget failed with error= %d\n", errno);
		exit(EXIT_FAILURE);
	}
	while(running) {
		printf("Enter some temperatures: ");
		float temp;
		scanf("%f", &temp);
		some_data.my_msg_type = 1;
		some_data.temp = temp;
		if (msgsnd(msgid, (void *)&some_data, sizeof(float), 0) == - 1){
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}