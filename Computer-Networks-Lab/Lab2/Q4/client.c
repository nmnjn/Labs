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

void PerformClientTask(int* sockfd){
	int n = 1;
	char ch;
    int val1, val2;
    char buf[256];
        printf("Enter Value 1: ");
        scanf("%d", &val1);
        printf("Enter Value 2: ");
        scanf("%d", &val2);
        while ((getchar()) != '\n'); 
		printf("Enter Operand (+ - * / ) : ");
        scanf("%c", &ch);
        int convertedVal1 = htonl(val1);
        int convertedVal2 = htonl(val2);
        write(*sockfd, &convertedVal1, sizeof(convertedVal1));
		write(*sockfd, &convertedVal2, sizeof(convertedVal2));
        write(*sockfd, &ch, sizeof(ch));
		n = read(*sockfd, buf, sizeof(buf));
		puts(buf);
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(&sockfd);
}



