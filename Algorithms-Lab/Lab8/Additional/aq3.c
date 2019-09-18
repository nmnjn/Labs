#include"heap.h"
void delsmol(int h[],int n)
{
	int start=(n/2)+1;
	int min=n;
	for(int i=start;i<n;i++)
	{
		if(h[min]>h[i])
			min=i;
	}
	swap(&h[min],&h[n]);
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
	printf("Heap:\n");
	for(int i=1;i<=n;i++)
		printf("%d ",h[i]);
	delsmol(h,n--);
	heapify(h,n);
	printf("\nHeap:\n");
	for(int i=1;i<=n;i++)
		printf("%d ",h[i]);
	printf("\n");
}