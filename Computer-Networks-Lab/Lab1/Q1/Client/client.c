#include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"

int CreateClientSocket(){
	int len, sockfd, result;
	struct sockaddr_in serverAddress;
	sockfd = createSocketFileDescriptor();
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
	char ch[256], buf[256];

	while(1){
		n = 1;
		printf("Enter String: ");
		gets(ch);
		ch[strlen(ch)] = '\0';
		write(*sockfd, ch, strlen(ch));
		printf("Respone from the server is... ");
		while(n){
			n = read(*sockfd, buf, sizeof(buf));
			puts(buf);
		}
	}
}

int main(){
	int len, result, sockfd, n=1;
	struct sockaddr_in address;
	char ch[256],buf[256];

	sockfd = CreateClientSocket();
	PerformClientTask(&sockfd);
}



