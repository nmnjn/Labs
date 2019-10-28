#include <stdio.h>
#include <stdlib.h>


int Weights[10], Values[10];
int F[10][10];


int max(int a, int b){
	return a > b ? a : b;
}

int MFKnapsack(int i, int j){
	int value;
	if (F[i][j] < 0)
	{
		if (j < Weights[i])
		{
			value = MFKnapsack(i-1, j);
		}else{
			value = max(MFKnapsack(i-1, j), Values[i] + MFKnapsack(i-1, j-Weights[i]));
		}
		F[i][j] = value;
	}

	return F[i][j];
}



int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of items: \n");
	scanf("%d", &n);
	int W;
	printf("Enter the maximum knapsack capacity\n");
	scanf("%d", &W);

	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=W; ++j)
		{
			if (i == 0 || j == 0)
			{
				F[i][j] = 0;
			}else{
				F[i][j] = -1;
			}
		}
	}

	printf("Enter information\n");
	for (int i = 1; i <= n; ++i)
	{
		printf("Enter weight for item %d:", i);
		scanf("%d", &Weights[i]);
		printf("Enter value for item %d:", i);
		scanf("%d", &Values[i]);
		printf("\n");
	}

	printf("The Optimal Cost is %d\n", MFKnapsack(n, W));

	return 0;
}