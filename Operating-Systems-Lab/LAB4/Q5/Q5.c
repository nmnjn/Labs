#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
	int filePointer = creat("temp.txt", S_IRWXU);
	//S_IRWXU gives read, write and executable prev to the user.
	char buffer[500];
	printf("Enter String\n");
	gets(buffer);
	write(filePointer, buffer, strlen(buffer));
}