#include"heap.h"
int searchAndDestroy(int h[],int n,int ch)
{
	for(int i=1;i<=n;i++)
	{
		if(h[i]==ch)
		{
			swap(&h[i],&h[n]);
			return 1;
		}
	}
	return 0;
}
void main()
{
	int h[20],i,n;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	heapify(h,n);
	printf("Enter value to find: ");
	scanf("%d",&i);
	if(!searchAndDestroy(h,n,i))
	{
		printf("Not found\n");
		exit(0);
	}
	n--;
	heapify(h,n);
	printf("Heap:\n");
	for(int i=1;i<=n;i++)
		printf("%d ",h[i]);
	printf("\n");
}