// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
#include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"

#include <time.h>

void PerformServerTask(int sockfd){
	int newsockfd, clilen, n = 1;
	struct sockaddr_in clientAddress;
	time_t rawtime;
  	struct tm * timeinfo;

  	listen(sockfd, 5);

	while(1) {
		clilen = sizeof(clientAddress);
		newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, &clilen);
		time(&rawtime);
  		timeinfo = localtime(&rawtime);
  		int pid = getpid();
  		char buffer[256];
  		sprintf(buffer, "Time is %sPID is %d", asctime(timeinfo), pid);
		n = write(newsockfd, buffer, sizeof(buffer));
		terminateSocket(newsockfd);
	}
}

int main(){
	int sockfd;
	sockfd = CreateServerSocket();
	PerformServerTask(sockfd);
	return 0;
}