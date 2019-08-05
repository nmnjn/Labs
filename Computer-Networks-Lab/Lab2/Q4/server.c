// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
// #include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"
#include "../../ServerHeader.h"

void PerformServerTask(int sockfd){
	int newsockfd, clilen, n=1;
	struct sockaddr_in clientAddress;
    int val1, val2, convertedVal1, convertedVal2;
    float result;
    char ch;
    printf("REMOTE MATH SERVER STARTED\n");
	while(1){
		//accept the connection
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, &clilen);
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
            char buffer[256];
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
                sprintf(buffer, "Invalid Operand");
		        n = write(newsockfd, buffer, sizeof(buffer));
                close(newsockfd);
                printf("\n***CLIENT TERMINATED***\n");
			    exit(0);
            }
  		    sprintf(buffer, "Result is %f", result);
		    n = write(newsockfd, buffer, sizeof(buffer));
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
