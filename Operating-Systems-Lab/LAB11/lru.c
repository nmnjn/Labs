// Page Replacement Algorithm - LRU

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *ref;
int cnt;

int *frames;
int nf;

int pfs;

int ref

int indexOf (int arr[], int n, int key) 
{
	int i;
	for (i = 0; i < n; ++i) {
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int minindex (int arr[], int n) 
{
	int min = INT_MAX;
	int mi = -1;
	int i;
	for (i = 0; i < n; ++i) {
		if (arr[i] < min) {
			min = arr[i];
			mi = i;
		}
	}
	return mi;
}

void printFrames (int pf) 
{
	int i;
	for (i = 0; i < nf; ++i) {
		printf("%d\t", frames[i]);
	}

	if (pf) {
		printf("#\n");
	} 
	else {
		printf("\n");
	}
}

void lru() 
{
	int i = 0, k = 0;
	for (; i < nf; ++i) {
		frames[i] = -1;
	}
	pfs = 0;
	int *mi = (int *)calloc(nf, sizeof(int));
	for (i = 0; i < nf; ++i) {
		mi[i] = -1;
	}
	while (k < cnt) {
		int value = ref[k];
		int ci = indexOf(frames, nf, value);
		if (ci != -1) {
			frames[ci] = value;
			mi[ci] = k;
			printFrames(0);
		} 
		else {
			int ind = minindex(mi, nf);
			frames[ind] = value;
			mi[ind] = k;
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
	for (i = 0; i < cnt; ++i) {
		scanf(" %d", ref+i);
	}

	printf("\nEnter # frames: ");
	scanf(" %d", &nf);
	frames = (int *)calloc(nf, sizeof(int));

	lru();
	return 0;
}
