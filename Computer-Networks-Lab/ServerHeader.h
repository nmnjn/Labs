#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

#define PORTNO 8000

//for select 
#include<sys/ioctl.h>

//for UDP
#include<fcntl.h>


int createUDPSocketFileDescriptor(){
	int socketID = socket(AF_INET, SOCK_DGRAM, 0);
	if (socketID<0){
		perror("SOCKET CREATION ERROR");
		exit(0);
	}
	return socketID;
}


int createSocketFileDescriptor(){
	int socketID = socket(AF_INET, SOCK_STREAM, 0);
	if (socketID<0){
		perror("SOCKET CREATION ERROR");
		exit(0);
	}
	return socketID;
}

struct sockaddr_in createSocketWithAddress(){
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORTNO);
	return address;
}

int CreateClientSocket(){
	int len, sockfd, result;
	struct sockaddr_in serverAddress;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	serverAddress = createSocketWithAddress();
	len = sizeof(serverAddress);
	result = connect(sockfd, (struct sockaddr *)&serverAddress, len);
	if (result == -1){
		perror("CLIENT ERROR");
		exit(1);
	}
	return sockfd;
}

int CreateUDPClientSocket(){
	int len, sockfd, result;
	struct sockaddr_in serverAddress;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	serverAddress = createSocketWithAddress();
	len = sizeof(serverAddress);
	result = connect(sockfd, (struct sockaddr *)&serverAddress, len);
	if (result == -1){
		perror("CLIENT ERROR");
		exit(1);
	}
	return sockfd;
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

int CreateUDPServerSocket(){
	int sockfd, status;
	struct sockaddr_in serverAddress;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
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

void terminateSocket(int sockfd){
	int status;
	status = close(sockfd);
	if (status == 0){
		printf("%s\n", "Socket Terminated");
	}else{
		printf("%s\n", "Failed to terminate socket");
	}
}