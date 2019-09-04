#include <stdio.h>
#include <stdlib.h>

int g[101][101];

int V,E;

int visited[101];

int order[101],len=0;

void dfsv (int v) {
	//printf("Visiting %d\n", v);
	visited[v] = 1;
	int i;
	for (i = 1; i <= V; ++i) {
		if (!(visited[i]) && (g[v][i] == 1) && (i != v)) {
			dfsv(i);
		}
	}
	order[len++] = v;
}

void dfs () {
	int i;
	for (i = 1; i <= V; ++i) {
		if (!visited[i]) {
			dfsv(i);
		}
	}
}

int main () {
	printf("Enter no of vertices: ");
	scanf("%d", &V);
	int i, j, a, b;
	printf("Enter number of edges: ");
	scanf("%d",&E);
	printf("Enter the edges: \n");
	for(i=0; i<E; i++) {
		scanf("%d%d",&a,&b);
		g[a][b] = 1;
	}
	dfs();

	for(i=len-1; i>=0; i--)
		printf("%d\t", order[i]);
	printf("\n");
	return 0;
}