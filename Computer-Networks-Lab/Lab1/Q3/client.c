#include "../../ServerHeader.h"

void PerformClientTask(int sockfd){
	int n = 1;
	char ch[256], buf[256];

	while(1){
		n = 1;
		printf("Enter String: ");
		gets(ch);
		ch[strlen(ch)] = '\0';
		write(sockfd, ch, sizeof(ch));
		if (strcmp(ch, "quit") == 0)
	    {
	         printf("Quiting..");
	         close(sockfd);
	         exit(1);
	    }
		printf("Respone from the server is... ");
		n = read(sockfd, buf, sizeof(buf));
		puts(buf);
	}
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(sockfd);
}



