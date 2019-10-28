#include"heap.h"
void heapsort(int h[],int n)
{
	for(int i=n;i>0;i--)
	{
		swap(&h[i],&h[1]);
		printf("%d ",h[i]);
		heapify(h,--n);
	}
}
void main()
{
	int h[100],i,n;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=1;i<=n;i++)
		scanf("%d,",&h[i]);
	heapify(h,n);
	printf("Heap:\n");
	for(int i=1;i<=n;i++)
		printf("%d ",h[i]);
	printf("\n");
	printf("Heapsort:\n");
	heapsort(h,n);
	printf("\n");
	printf("%d\n",count);
}