// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
#include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"

void PerformClientTask(int sockfd){
	char ch[256];
	char time[4] = "Time";
	while (1)
	{
		printf("Enter \"Time\" to get time, anything else to exit");
		gets(ch);
		if (strcmp(ch, "Time") == 0)
		{
			char buf[256];
			write(sockfd, buf, sizeof(buf));
			read(sockfd, buf, sizeof(buf));
			puts(buf);
		}else{
			exit(1);
		}
		
	}
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(sockfd);
	return 0;
}



