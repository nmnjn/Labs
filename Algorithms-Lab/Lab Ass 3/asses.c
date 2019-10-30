#include <stdio.h>
#include <string.h>

int max(int a, int b){
	if (a>b)
		return a;
	else
		return b;
}

int collect(int d[10][10], int n, int m){

	int a[n][m];
	a[1][1] = d[1][1];
	for (int k = 2; k <= m; k++)
	{
		a[1][k] = d[1][k-1] + d[1][k];
	}
	for (int i=2;i<=n;i++)
	{
		a[i][1] = a[i-1][1] + d[i][1];
		for (int j=2;j<=m;j++)
		{
			a[i][j] = max(a[i-1][j], a[i][j-1])+d[i][j];
		}
	}

		for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
		printf("\n");

				for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}

	return a[n][m];
}

void main(){
	int n, m, C[10][10];
	memset(C, 0, sizeof(C));
	printf("Enter n\n");
	scanf("%d", &n);
	printf("Enter m\n");
	scanf("%d", &m);
	printf("Enter the board\n");
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &C[n][m]);
		}
	}
	int val = collect(C, n, m);
	printf("The number of coins collected are : %d\n", val);

}