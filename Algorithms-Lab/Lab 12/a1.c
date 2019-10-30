#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int V;
int g[MAX][MAX];

int path[MAX];
int pi;

int existsInPath (int v) 
{
	int i;
	for (i = 0; i < V; ++i) {
		if (path[i] == v) return 1;
		if (path[i] == -1) break;
	}
	return 0;
}

int addToPath (int v) 
{
	if (!existsInPath(v)) {
		path[pi++] = v;
		return 1;
	}
	return 0;
}

int findHamilton () 
{
	addToPath(0);
	int i, v;
	do {
		int last = path[pi-1];
		int addedany = 0;
		for (v = 0; v < V; ++v) {
			if (g[last][v]) {
				addedany = addedany || addToPath(v);
			}
		}
		if (!addedany)
			return 0;
	} while (pi < V);
	if (pi == V)
		path[pi++] = path[0];
	return 1;
}

int main () 
{	
	int i, j;
	for (i = 0; i < MAX; ++i) {
		path[i] = -1;
	}
	pi = 0;

	printf("Enter # vertices: ");
	scanf(" %d", &V);
	
	printf("Enter adj matrix: ");
	for (i = 0; i < V; ++i) {
		for (j = 0; j < V; ++j) {
			scanf(" %d", &g[i][j]);
		}
	}

	if (findHamilton()) {
		printf("Hamilton circuit exists: ");
		for (i = 0; i < pi; ++i)
			printf("%d ", path[i]);
	} else {
		printf("Hamilton circuit does not exist.\n");
	}

	printf("\n");
 
	return 0;
}