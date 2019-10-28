#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int h[],int n)
{
	int temp=n/2;
	while(temp>0)
	{
		if(h[n]>h[temp])
			swap(&h[n],&h[temp]);
		n=temp;
		temp/=2;
	}
}
int main()
{
	int arr[20];
	int n=1;
	int ch=1;
	printf("Enter elements(0 to quit):\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
		arr[n]=ch;
		heapify(arr,n++);
		scanf("%d",&ch);
	}
	printf("Heap:\n");
	for(int i=1;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}