#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main(){
	char dirname[100];
	DIR *p; //pointer to directory
	struct dirent *d; // pointer to directory entry structure
	printf("Enter directory name\n");
	scanf("%s", dirname);
	p=opendir(dirname);
	if(p==NULL){
		printf("Cannot find directory\n");
		exit(-1);
	}
	while(d=readdir(p))
		printf("%s\n", d->d_name);
	return 0;
}