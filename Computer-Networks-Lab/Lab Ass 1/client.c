//Write a client program to connect to a server on a given address
//and print the message from the server. Send one character to get a response

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

#define PORTNO 9734

int main(){
	int sockfd, length, n=1;
	struct sockaddr_in serverAddress;
	char ch = 'A';
	char buf[256];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd <= 0)
	{
		perror("socket error");
	}
	printf("%d\n", sockfd);

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("172.16.58.36");
	serverAddress.sin_port = htons(PORTNO);

	length = sizeof(serverAddress);
	int result = connect(sockfd, (struct sockaddr *)&serverAddress, length);
	if (result == -1){
		perror("CLIENT ERROR - Unable to connect");
		exit(1);
	}
	write(sockfd, &ch, sizeof(ch));
	printf("%d\n", result);
	printf("The Response from the server is: \n");
	read(sockfd, buf, sizeof(buf));
	puts(buf);
	close(sockfd);
}