#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 8000

int main(){
	int sockfd, newsockfd, portno, clilen, n=1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//check of socket error
	if (sockfd == -1){
		printf("%s", "failed to create socket");
		return 0;
	}
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);
	int status = bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	
	if (status == -1){
		printf("%s", "failed to bind socket");
		return 0;
	}

	status = listen(sockfd, 5);

	if (status == -1){
		printf("%s", "failed to listen");
		return 0;
	}

	while(1){
		char buf[256];
		printf("%s", "server waiting for connection");

		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen
	);
		n = read(newsockfd, buf, sizeof(buf));
		printf("\nMessage From Client: %s", buf);
		n = write(newsockfd, buf, sizeof(buf));
	}
}



