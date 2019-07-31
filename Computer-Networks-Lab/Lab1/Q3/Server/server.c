#include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
#include <time.h>

int CreateServerSocket(){
	int sockfd, status;
	struct sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
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

void terminateSocket(int sockfd){
	int status;
	status = close(sockfd);
	if (status == 0){
		printf("%s\n", "Socket Terminated");
	}else{
		printf("%s\n", "Failed to terminate socket");
	}
}

void PerformServerTask(int* sockfd){
	int newsockfd, clilen, n = 1;
	char buf[256];
	struct sockaddr_in cliaddr;
	time_t rawtime;
  	struct tm * timeinfo;

  	listen(*sockfd, 5);


	while(1) {
		clilen = sizeof(cliaddr);
		newsockfd = accept(*sockfd, (struct sockaddr *)&cliaddr, &clilen);
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
	int sockfd, newsockfd, portno, clilen, n=1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;

	sockfd = CreateServerSocket();
	PerformServerTask(&sockfd);
	return 0;
}