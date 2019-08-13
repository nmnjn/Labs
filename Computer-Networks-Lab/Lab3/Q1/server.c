#include "../../ServerHeader.h"

void PerformServerTask(int sockfd){
    int r,c;
	int arr[10][10];
	struct sockaddr_in cliaddr;
	int len=sizeof(cliaddr);
	while(1){
		recvfrom(sockfd,&r,sizeof(r),0,(struct sockaddr *)&cliaddr,&len);
		recvfrom(sockfd,&c,sizeof(c),0,(struct sockaddr *)&cliaddr,&len);
		for(int i=0;i<r;i++)
			recvfrom(sockfd,arr[i],sizeof(arr[i]),0,(struct sockaddr *)&cliaddr,&len);
		printf("\nThe matrix received from client is:\n");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				printf("%d ",arr[i][j]);
			printf("\n");
		}
	}
}


int main(){
	int sockfd;
	sockfd = CreateUDPServerSocket();
	PerformServerTask(sockfd);
	return 0;
}