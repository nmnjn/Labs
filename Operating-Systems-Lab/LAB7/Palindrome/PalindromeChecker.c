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
	char some_text[BUFSIZ];
};

int checkPalindrome( char* data){
	int size = strlen(data) - 1;
	if (size == -1)
	{
		return 0;
	}

	for (int i = 0; i < size/2; ++i)
	{
		if (data[i] != data[size-i-1])
		{
			return 0;
		}
	}

	return 1;
}

int main(){
	int running = 1;
	int msgid;
	struct my_msg_st some_data;	
	long int msg_to_receive = 0;
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid == -1){
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}
	while(running) {
		if (msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1) {
			fprintf(stderr, "msgrcv failed with error %d\n", errno);
		exit(EXIT_FAILURE);
	}
	printf("You wrote: %s..", some_data.some_text);
	char* data = some_data.some_text;
	if (checkPalindrome(data))
	{
		printf("is a palindrome\n");
	}else{
		printf("is not a palindrome\n");
	}
	if (strncmp(some_data.some_text, "end", 3) == 0) {
		running = 0;
	}
}
if (msgctl(msgid, IPC_RMID, 0) == -1) {
	fprintf(stderr, "msgctl(IPC_RMID) failed\n");
	exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}


