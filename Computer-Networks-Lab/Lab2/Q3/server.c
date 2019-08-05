// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
// #include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"
#include "../../ServerHeader.h"

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

void PerformServerTask(int sockfd){
	int array[1000];
	int newsockfd, clientLength, size, n = 1;
	struct sockaddr_in clientAddress;
	while(1){
		//accept the connection
		clientLength = sizeof(clientAddress);
		newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, &clientLength);
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

int main(){
	int sockfd;
	sockfd = CreateServerSocket();
	PerformServerTask(sockfd);
}
