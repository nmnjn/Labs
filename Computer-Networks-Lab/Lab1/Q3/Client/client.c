// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
#include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"

void PerformClientTask(int sockfd){
	int n = 1;
	char buf[256];
	n = read(sockfd, buf, sizeof(buf));
	puts(buf);
	exit(1);
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(sockfd);
	return 0;
}



