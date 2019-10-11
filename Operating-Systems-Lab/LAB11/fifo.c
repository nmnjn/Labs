// Page Replacement Algorithm - FIFO

#include <stdio.h>
#include <stdlib.h>

int *ref;
int cnt;

int *frames;
int nf;

int pfs;

void printFrames(int pf) 
{
	int i;
	for (i = 0; i < nf; ++i)
		printf("%d\t", frames[i]);

	if (pf)
		printf("#\n");
	else
		printf("\n");
}

int indexOf(int arr[], int n, int key) 
{
	int i;
	for (i = 0; i < n; ++i)
		if (arr[i] == key)
			return i;

	return -1;
}

void fifo()
{
	int i = 0, k = 0;
	for (; i < nf; ++i)
		frames[i] = -1;

	pfs = 0;
	int fifo = 0;
	while (k < cnt) 
	{
		int value = ref[k];
		int ci = indexOf(frames, nf, value);
		if (ci != -1) 
		{
			frames[ci] = value;
			printFrames(0);
		} 
		else 
		{
			frames[fifo] = value;
			fifo = (fifo + 1) % nf;
			pfs += 1;
			printFrames(1);
		}
		k += 1;
	}
	printf("# page faults = %d\n", pfs);
}

int main()
{
	printf("Enter length of input: ");
	scanf(" %d", &cnt);
	ref = (int *)calloc(cnt, sizeof(int));
	int i;
	printf("Enter page ref string: ");
	for (i = 0; i < cnt; ++i)
		scanf(" %d", ref+i);

	printf("Enter # frames: ");
	scanf(" %d", &nf);
	frames = (int *)calloc(nf, sizeof(int));

	fifo();
	return 0;
}