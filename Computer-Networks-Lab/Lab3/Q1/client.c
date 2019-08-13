#include "../../ServerHeader.h"

void PerformClientTask(int sockfd){
    int len;
	struct sockaddr_in addr;
	addr = createSocketWithAddress();
	int arr[10],m,n;
	len=sizeof(addr);
	printf("Enter m and n:\n");
	scanf("%d %d",&m,&n);
	sendto(sockfd,&m,sizeof(m),0,(struct sockaddr *)&addr,len);					
	sendto(sockfd,&n,sizeof(n),0,(struct sockaddr *)&addr,len);
	for(int i=0;i<m;i++)
	{
		printf("Enter row %d: \n", i+1);
		for(int j=0;j<n;j++)
			scanf("%d",&arr[j]);
		sendto(sockfd,arr,sizeof(arr),0,(struct sockaddr *)&addr,len);
	}
}

int main(){
	int sockfd;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	PerformClientTask(sockfd);
	return 0;
}
