// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
// #include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"
#include "../../ServerHeader.h"

void PerformClientTask(int* sockfd){
	int n = 1;
	int ch;
    int array[1000];
    int size = 5;
    int buf[256];
        printf("Enter Size: ");
        scanf("%d", &size);
        write(*sockfd, &size, sizeof(size));
        for(int i = 0; i < size; i++){
            printf("Enter Value %d: ", i+1);
            scanf("%d", &ch);
            array[i] = ch;
        }
        write(*sockfd, array, sizeof(array));
		n = read(*sockfd, buf, sizeof(buf));
        for(int i = 0; i < size; i++){
            printf("%d ", buf[i]);
        }
		puts(buf);
}

int main(){
	int sockfd;
	sockfd = CreateClientSocket();
	PerformClientTask(&sockfd);
}



