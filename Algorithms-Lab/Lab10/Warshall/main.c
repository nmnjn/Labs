#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of vertices: \n");
	scanf("%d", &n);
	int mat[20][20], r[20][20];
	printf("Enter the adjacency matrix\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &mat[i][j]);
			r[i][j] = mat[i][j];
		}
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				r[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);

		for (int a = 0; a < n; ++a)
			for (int b = 0; b < n; ++b)
				mat[a][b] = r[a][b];
	}


	printf("Transitive Closure is: \n");

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d\t", r[i][j]);
		}
		printf("\n");
	}


	return 0;
}