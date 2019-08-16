#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
	//copies from temp to temp2
	//the files should exist in the same directory
	int filePointer1 = open("temp.txt", O_RDONLY);
	int filePointer2 = open("temp2.txt", O_WRONLY);
	//add error handling here
	char buffer[256];
	read(filePointer1, buffer, sizeof(buffer));
	write(filePointer2, buffer, strlen(buffer));
}