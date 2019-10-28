#include <stdio.h>
#include <stdlib.h>

int findRoot(int n){
	for(int i=0; i<n; i++){
		if(i*i == n){
			return i;
		}
	}
	return -1;
}

int main(){
    printf("%d\n", findRoot(16));
}
