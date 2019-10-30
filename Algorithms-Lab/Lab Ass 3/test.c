#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}

int collect(int d[10][10],int n,int m)
{
	int a[n][m];
	a[1][1]=d[1][1];
	for(int k=2;k<=m;k++)
	{
		a[1][k]=d[1][k-1]+d[1][k];
	}
	for(int i=2;i<=n;i++)
	{
		a[i][1]=a[i-1][1]+d[i][1];
		for(int j=2;j<=m;j++)
		{
			a[i][j]=max(a[i-1][j],a[i][j-1])+d[i][j];
		}

	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return a[n][m];
}

int main()
{
	int n,m;
	int d[10][10];
	printf("enter row and colums");
	scanf("%d\n%d",&n,&m);
	printf("enter matrix");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&d[i][j]);

	int val=collect(d,n,m);
	printf("%d",val);

}