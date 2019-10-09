#include <stdio.h>
#include <stdlib.h>


int min(int a, int b){
	return a > b ? b : a;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of vertices: \n");
	scanf("%d", &n);
	int W[20][20], D[20][20];
	printf("Enter the weight matrix\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &W[i][j]);
			D[i][j] = W[i][j];
		}
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
	}


	printf("Distance Matrix is: \n");

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d\t", D[i][j]);
		}
		printf("\n");
	}


	return 0;
}