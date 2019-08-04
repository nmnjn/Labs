// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
// #include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"
#include "../../ServerHeader.h"

void PerformClientTask(int sockfd){
	int n = 1;
	char ch[256], buf[256];

	while(1){
		n = 1;
		printf("Enter String: ");
		gets(ch);
		ch[strlen(ch)] = '\0';
		write(sockfd, ch, strlen(ch));
		printf("Respone from the server is... ");
		while(n){
			n = read(sockfd, buf, sizeof(buf));
			puts(buf);
		}
	}
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(sockfd);
}



