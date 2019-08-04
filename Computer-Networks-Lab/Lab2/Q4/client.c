// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
// #include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"
#include "../../ServerHeader.h"

void PerformClientTask(int* sockfd){
	int n = 1;
	char ch;
    int val1, val2;
    char buf[256];
        printf("Enter Value 1: ");
        scanf("%d", &val1);
        printf("Enter Value 2: ");
        scanf("%d", &val2);
        while ((getchar()) != '\n'); 
		printf("Enter Operand (+ - * / ) : ");
        scanf("%c", &ch);
        int convertedVal1 = htonl(val1);
        int convertedVal2 = htonl(val2);
        write(*sockfd, &convertedVal1, sizeof(convertedVal1));
		write(*sockfd, &convertedVal2, sizeof(convertedVal2));
        write(*sockfd, &ch, sizeof(ch));
		n = read(*sockfd, buf, sizeof(buf));
		puts(buf);
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(&sockfd);
}



