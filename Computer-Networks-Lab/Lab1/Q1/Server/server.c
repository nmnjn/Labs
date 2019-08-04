#include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"

int CreateServerSocket(){
	int sockfd, status;
	struct sockaddr_in serverAddress;
	sockfd = createSocketFileDescriptor();
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

void PerformServerTask(int sockfd){
	int newsockfd, clilen, n=1;
	struct sockaddr_in seraddr, clientAddress;

	while(1){
		char buf[256];
		printf("\n%s", "server waiting for connection\n");

		clilen = sizeof(clientAddress);
		newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, &clilen);
		n = read(newsockfd, buf, sizeof(buf));
		printf("\nMessage From Client: %s", buf);
		n = write(newsockfd, buf, sizeof(buf));
		memset(buf, 0, 255);
	}
}

int main(){
	int sockfd;
	sockfd = CreateServerSocket();
	PerformServerTask(sockfd);
}



