#include <stdio.h>
#include<stdlib.h>
int counter = 0;

void swap (int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int h[], int n){
	int i,k,v,heapify,j;
	for (int i = (n/2); i >= 1; i--)
	{
		k = i;
		v = h[k];
		heapify = 0;
		while(heapify==0 && 2*k<=n){
			j = 2*k;
			if (j<n)
			{
				if (h[j]<h[j+1])
				{
					j=j+1;
				}
			}
			if (v>=h[j])
			{
				heapify=1;
			}else{
				h[k] = h[j];
				k=j;
			}
			counter++;
		}
		h[k] = v;
	}


	return;
}

void heapSort(int arr[], int n) 
{ 
    heapify(arr, n);
    for (int i=n; i>1; i--) 
    { 
        swap(&arr[1], &arr[i]); 
  
        heapify(arr, i-1); 
    } 
} 


int main(int argc, char const *argv[])
{
	// int h[20], i, n;
	// printf("\nEnter the number of Elements\n");
	// scanf("%d",&n);
	// printf("Enter the elements\n");
	// for (int i = 1; i <= n; ++i)
	// {
	// 	scanf("%d", &h[i]);
	// }
	// printf("\nArray enterred: ");
	// for (int i = 1; i <= n; ++i)
	// {
	// 	printf("%d\t", h[i]);
	// }
	// heapSort(h,n);
	// printf("\nThe heap created: ");
	// for (int i = 1; i <= n; ++i)
	// {
	// 	printf("%d\t", h[i]);
	// }
	// printf("\n");

	// return 0;

	    int n;
    int i;
    int m; 
    FILE *input;
    input = fopen("numbers.txt", "r");

    FILE *output;
    output = fopen("buildheap.csv", "w+");
    fprintf(output, "inputsize, counts\n");

    while (fscanf(input, " %d", &n)) {

        int *arr = (int *)calloc(n, sizeof(int));
        for (i = 0; i < n; ++i) {
            fscanf(input, " %d", &m);
            *(arr + i) = m;
        }
        heapSort(arr, n);
        printf("Building Heap for size %d with counts: %d\n", n, counter);
  
        fprintf(output, "%d, %d\n", n, counter);
        counter = 0;

        if (n == 1000)
            break;
    }

    fclose(input);
    fclose(output);
}