#include <stdio.h>

int main(){
	int denom, d[100], use[100], i, n;
	printf("Enter the number of denominations: ");
	scanf("%d", &denom);

	printf("Enter the denominations in the descending order: \n");
	for (int i = 0; i < denom; ++i)
	{
		scanf("%d", &d[i]);
	}

	printf("Enter the amount owed: ");
	scanf("%d", &n);

	for (int i = 0; i < denom; ++i)
	{
		use[i] = n / d[i];
		n %= d[i];
	}

	printf("\nSolution: \n");
	for (int i = 0; i < denom; ++i)
	{
		if (use[i] == 0)
		{
			continue;
		}
		printf("%d coins of %d\n", use[i], d[i]);
	}
}