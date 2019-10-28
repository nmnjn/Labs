#include <stdio.h>

int countNumberOfTiles(int n){
	int countArray [n+1];
	countArray [0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		//reccurence relation
		if(i>2)
			countArray [i] = countArray [i-1] + countArray [i-2];
		//base case
		else if(i < 2)
			countArray [i] = 1;
		else
			countArray [i] = 2;
	}

	return countArray [n];
}


int main(int argc, char const *argv[])
{
	int n = 0;
	printf("Enter N\n");
	scanf("%d", &n);
	printf("%d\n", countNumberOfTiles(n));
	return 0;
}
