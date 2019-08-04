// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
// #include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"
#include "../../ServerHeader.h"

void PerformServerTask(int sockfd){
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

int main(){
	int sockfd;
	sockfd = CreateServerSocket();
	PerformServerTask(sockfd);
}
