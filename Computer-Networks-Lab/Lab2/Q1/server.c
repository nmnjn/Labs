#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

#define PORTNO 8000

struct sockaddr_in createSocketWithAddress(){
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORTNO);
	return address;
}

int CreateServerSocket(){
	int sockfd, status;
	struct sockaddr_in serverAddress;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//check of socket error
	if (sockfd == -1){
		printf("%s", "failed to create socket");
		exit(1);
	}
	serverAddress = createSocketWithAddress();
	status = bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
	
	if (status == -1){
		printf("%s", "failed to bind socket");
		exit(1);
	}

	status = listen(sockfd, 5);

	if (status == -1){
		printf("%s", "failed to listen");
		exit(1);
	}
	return sockfd;
}

void PerformServerTask(int* sockfd){

}

int main(){
	int sockfd, newsockfd, portno, clilen, n=1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;
	char buf[256];

	sockfd = CreateServerSocket();

	while(1){
		//accept the connection
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
		//fork to create a process for this client and perform a test to see whether
		//you're the parent or the child:
		if (fork() == 0){
			n = read(newsockfd, buf, sizeof(buf));
			printf("\nMessage From Client: %s", buf);
			n = write(newsockfd, buf, sizeof(buf));
			memset(buf, 0, 255);
			close(newsockfd);
			exit(0);
		}else{
			close(newsockfd);
		}
	}
}
