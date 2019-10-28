#include <stdio.h>
#include <string.h>

int findIndex(int qp[], int c[]){
	int max = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (qp[i] == -1)
		{
			return i;
		}
		if (c[qp[i]] > c[qp[max]])
		{
			max = i;
		}
	}

	return max;
}

void printTable(int c[]){
	for (int i = 0; i < 10; ++i)
	{
		if (c[i] == -1)
		{
			continue;
		}
		printf("%d\t", c[i]);
	}
	printf("\n");
}


int mfu(int arr[], int n, int qp[], int q, int c[]){
	int flag = 0; 
	int miss = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			if (arr[i] == qp[j])
			{
				flag = 1;
				c[arr[i]]++;
				printTable(c);
				break;
			}
		}

		if (flag){
			flag = 0;
			continue;
		}

		miss++;

		int indexToReplace = findIndex(qp, c);
		c[arr[i]]++;
		qp[indexToReplace] = arr[i];
		printTable(c);
		//print table here
	}

	return miss;
}



int main(int argc, char const *argv[])
{
	int size;
	printf("Enter the length of the input: \n");
	scanf("%d", &size);
	int page[4] = {1, 3, -1, -1};
	int arr[30];
	int c[10] = {0};
	memset(c, -1, sizeof(c));
	printf("Enter the sequence: \n");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < size; ++i)
	{
		c[arr[i]] = 0;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (c[i] == -1)
		{
			continue;
		}
		printf("%d\t", i);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	int pageMisses = mfu(arr, size, page, 4, c);
	printf("\n");
	printf("\n");
	printf("The number of page faults are : %d\n", pageMisses);
	printf("The number of page replacements are : %d\n", pageMisses-2);
	return 0;
}