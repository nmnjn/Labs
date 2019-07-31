#include <stdio.h>
#include <stdlib.h>

int GCD(int m, int n){
	int min;
	int opcount = 0;
	if (m < n)
		min = m;
	else
		min = n;
	while(min > 0){
		opcount++;
		if (m%min==0 && n%min==0){
			printf("Operation Count: %d\n", opcount);
			return min;	
		}
		--min;
	}
}

int main(){
	int a = GCD(66, 96);
	printf("%d\n", a);
	return 0;
}