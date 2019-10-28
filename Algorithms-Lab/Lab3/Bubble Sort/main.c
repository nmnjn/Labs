#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
	int temp;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n-i; ++j)
		{
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(){
   int array[100];
   int n;
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
   printf("Enter %d elements\n", n);
   for (int c = 0; c < n; c++)
      scanf("%d", &array[c]);
  bubbleSort(array, n);
   for(int i = 0; i< n; i++)
	printf("%d  ", array[i]);
	
	getchar();
	return 0;
}