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

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

int main(){
    int array[1000];
	int sockfd, newsockfd, clientLength, size, n = 1;
	struct sockaddr_in clientAddress;
	sockfd = CreateServerSocket();
	while(1){
		//accept the connection
		clientLength = sizeof(clientAddress);
		newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, clientLength);
		//fork to create a process for this client and perform a test to see whether
		//you're the parent or the child:
		if (fork() == 0){
            printf("\n***NEW CLIENT ATTACHED***\n");
            n = read(newsockfd, &size, sizeof(size));
			n = read(newsockfd, array, sizeof(array));
            printf("\n***PERFORMING SORT***\n");
            selectionSort(array, size);
		    n = write(newsockfd, array, sizeof(array));
			close(newsockfd);
            printf("\n***CLIENT TERMINATED***\n");
			exit(0);
		}else{
			close(newsockfd);
		}
	}
}
