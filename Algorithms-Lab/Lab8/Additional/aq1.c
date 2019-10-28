#include<stdio.h>
int heapcheck(int h[],int n)
{
	for(int i=2;i<=n;i++)
	{
		if(h[i]>=h[i/2])
			return 0;
	}
	return 1;
}
void main()
{
	int h[20],i,n;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	if(heapcheck(h,n))
		printf("Heap\n");
	else
		printf("Not a Heap\n");
}