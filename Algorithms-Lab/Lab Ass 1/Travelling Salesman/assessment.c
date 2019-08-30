#include <stdio.h>
#include <stdlib.h>

int minimum = 10000000;
int mat[10][10];
int sol[10];
int n;

void computeCost(int arr[]) {
	int cost = 0,i;
	for(i=0; i<n; i++) {
		cost = cost + mat[arr[i]-1][arr[i+1]-1];
	}
	printf("  Cost: %d\n", cost);
	if(cost < minimum){
		minimum = cost;
		for(i=0; i<n; i++) {
			sol[i] = arr[i];
		}
	}
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int arr[], int start, int end)
{
	int costArray[10];
    if(start==end) {
	    if (arr[n-1] != 1)
		{
			return;
		}
    	costArray[0] = 1;
    	for (int i = 0; i < n; ++i)
    	{
    		costArray[i+1] = arr[i];
    	}

    	for (int i = 0; i <= n; ++i)
    	{
    		printf("--> %d", costArray[i]);
    	}
        computeCost(costArray);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap(&arr[i], &arr[start]);
        permutation(arr, start+1, end);
        swap(&arr[i], &arr[start]);
    }
}

int main() {
	int i,j;
	printf("Enter number of cities: \n");
	scanf("%d",&n);

	printf("Enter the cost matrix: \n");

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	int arr[n];
	for(i=0; i<n; i++) {
		arr[i] = i+1;
	}

	permutation(arr,0,n-1);

	printf("\nThe minimum cost is: %d\n", minimum );
}