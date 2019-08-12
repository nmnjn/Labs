// #include "/home/170905079/Desktop/Labs/CN-LAB/ServerHeader.h"
// #include "/Users/namanjain/Developer/Labs/Computer-Networks-Lab/ServerHeader.h"
#include "../../ServerHeader.h"
#include<sys/ioctl.h>

void PerformServerTask(int sockfd){
	int newsockfd, clientLength, size, n = 1;
	struct sockaddr_in clientAddress;
	char buf[256];
	while(1){
		//accept the connection
		clientLength = sizeof(clientAddress);
		newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, &clientLength);
		//fork to create a process for this client and perform a test to see whether
		//you're the parent or the child:
		if (fork() == 0){
			n = read(newsockfd, buf, sizeof(buf));
			printf("\nMessage From Client: %s", buf);
			n = write(newsockfd, buf, sizeof(buf));
			memset(buf, 0, 255);
			close(newsockfd);
			exit(0);
		}else{
			close(newsockfd);
		}
	}
}

int main(){
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address, client_address;
	int result;
	fd_set readfds, testfds;

	//create ans name a socket for the server

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(PORTNO);

	server_len = sizeof(server_address);

	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	// create a connection queue and initialize readfds to handle input from server_sockfd
	listen(server_sockfd, 5);
	FD_ZERO(&readfds);
	FD_SET(server_sockfd, &readfds);

	//Now wait for client and requests. Because you have passed a null pointer as the timeout
	//parameter, no timout will occur. The program will exit and report an error if select returns
	//a value less than 1

	while(1){
		char ch[256];
		int fd, nread;
		testfds = readfds;
		printf("Server Waiting\n");
		//select function provides syncrhronous IO

		//every time we call select it destroys the fdse, thats why we copy it and use it
		//result = select(FD_SETSIZE, &testfds, nullptr, nullptr, nullptr);
		result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0);
		//after this time test result. If there has been an error t he program exists
		if(result<1){
			perror("Server Error");
			exit(1);
		}
		//once you know you;ve got activity, you can find which descriptor its on by checking
		//each in turn using FD_ISSET
		for ( fd = 0; fd < FD_SETSIZE; fd++)
		{
			if (FD_ISSET(fd, &testfds))
			{
				if (fd == server_sockfd)
				{
					//accept new connection
					//add the new connection to the list of connected clients

					client_len = sizeof(client_address);
					client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
					//important part to select and multiple clients

					FD_SET(client_sockfd, &readfds);
					printf("Adding client on fd %d\n", client_sockfd);
				}

				//if it isnt the server, it must be client activity
				//if close is received, the client has gone away
				//and you remove it from the descriptor set.
				//other wise you serve the client 
				//ass in the previous examples
				else{
					ioctl(fd, FIONREAD, &nread);
					if(nread == 0){
						//drop the client and remove it from the set
						close(fd);
						FD_CLR(fd, &readfds);
						printf("removing client from fd %d\n", fd);
					}else{
						read(fd, ch, sizeof(ch));
						// sleep(5);
						printf("Serving client on fd %d\n", fd);
						write(fd, ch, sizeof(ch));
					}
				}
			}
		}
	}
}
