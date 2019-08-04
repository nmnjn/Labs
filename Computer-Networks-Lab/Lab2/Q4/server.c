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

int main(){
	int sockfd, newsockfd, portno, clilen, n=1;
	struct sockaddr_in seraddr, cliaddr;
	int i, value;
    int val1, val2, convertedVal1, convertedVal2;
    float result;
    char ch;
	sockfd = CreateServerSocket();
    printf("REMOTE MATH SERVER STARTED\n");
	while(1){
		//accept the connection
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
		//fork to create a process for this client and perform a test to see whether
		//you're the parent or the child:
		if (fork() == 0){
            printf("\n***NEW CLIENT ATTACHED***\n");
			n = read(newsockfd, &convertedVal1, sizeof(convertedVal1));
            val1 = ntohl(convertedVal1);
			printf("\nValue 1 Received from Client is: %d\n", val1);
            n = read(newsockfd, &convertedVal2, sizeof(convertedVal2));
            val2= ntohl(convertedVal2);
			printf("\nValue 2 Received from Client is: %d\n", val2);
            n = read(newsockfd, &ch, sizeof(ch));
			printf("\nOperand Received from Client is: %c\n", ch);
            switch (ch)
            {
            case '+':
                printf("\nPerforming Addition\n");
                result = val1 + val2;
                break;
            case '-':
                printf("\nPerforming Subtraction\n");
                result = val1 - val2;
                break;
            case '*':
                printf("\nPerforming Multiplication\n");
                result = val1 * val2;
                break;
            case '/':
                printf("\nPerforming Division\n");
                if(val2 == 0){
                    printf("\nDivide By Zero Exception\n");
                    result = 0;
                    break;
                }
                result = val1 / val2;
                break;
            default:
                printf("\nInvalid Operand\n");
                result = -1;
                break;
            }
            char buffer[256];
  		    sprintf(buffer, "Result is %f", result);
		    n = write(newsockfd, buffer, sizeof(buffer));
			// memset(buffer, 0, 256);
			close(newsockfd);
            printf("\n***CLIENT TERMINATED***\n");
			exit(0);
		}else{
			close(newsockfd);
		}
	}
}
