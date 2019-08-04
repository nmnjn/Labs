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
	int ch;
    int array[1000];
    int size = 5;
    int buf[256];
        printf("Enter Size: ");
        scanf("%d", &size);
        write(*sockfd, &size, sizeof(size));
        for(int i = 0; i < size; i++){
            printf("Enter Value %d: ", i+1);
            scanf("%d", &ch);
            array[i] = ch;
        }
        write(*sockfd, array, sizeof(array));
		n = read(*sockfd, buf, sizeof(buf));
        for(int i = 0; i < size; i++){
            printf("%d ", buf[i]);
        }
		puts(buf);
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(&sockfd);
}



