#include <stdio.h>
#include <string.h>

void swap(char a[], char b[]){
	char temp[100];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void bubbleSort(char arr[][30], int n){
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n-i; ++j)
		{
			if(strcmp(arr[j],arr[j+1])>0){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main(){
   char array[10][30];
   int n;
   printf("Enter number of string in array\n");
   scanf("%d", &n);
   printf("Enter %d strings\n", n);
   for (int c = 0; c <= n; c++)
      gets(array[c]);
  	bubbleSort(array, n);
   for(int i = 0; i <= n; i++)
		printf("%s\n", array[i]);
	return 0;
}