#include "../../ServerHeader.h"
#include <ctype.h>

void PerformServerTask(int sockfd){
	int newsockfd, clilen, n=1;
	struct sockaddr_in clientAddress;

	while(1){
		char buf[256];
		memset(buf, 0, 255);
		printf("\n%s", "server waiting for connection\n");
		clilen = sizeof(clientAddress);
		newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, &clilen);
		printf("The Client IP is %u\n", clientAddress.sin_addr.s_addr);
		printf("The Client Port is %u\n", clientAddress.sin_port);
		n = read(newsockfd, buf, sizeof(buf));
		if (strcmp(buf, "quit") == 0)
	    {
	         printf("\nQuiting Server\n");
	         close(newsockfd);
	         close(sockfd);
	         exit(1);
	    }

		printf("\nMessage From Client: %s", buf);
		for(int i=0;i<strlen(buf);i++)
        	buf[i] = toupper(buf[i]);
		n = write(newsockfd, buf, sizeof(buf));
	}
}

int main(){
	int sockfd;
	sockfd = CreateServerSocket();
	PerformServerTask(sockfd);
}



