#include"header.h"
int mkfifo(const char* filename,mode_t mode);
int main() {
	int res=mkfifo("/tmp/my_fifo",0777);
	if(res==0)printf("FIFO created\n");
	exit(EXIT_SUCCESS);
}