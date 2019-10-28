#include<stdio.h>
#include<stdlib.h>
int count=0;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int h[],int n)
{
	int i,k,v,heapify,j;
	for(i=n/2;i>=1;i--)
	{
		k=i;v=h[k];heapify=0;
		while(heapify==0 && 2*k<=n)
		{
			count++;
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j++;
			if(v>=h[j])
				heapify=1;
			else
			{
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	}
	return;
}