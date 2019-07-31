#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

typedef struct node *NODE;

struct head{
    NODE head;
};

typedef struct head *HEAD;

struct graph{
    int vertices;
    HEAD values;
};

typedef struct graph *GRAPH;

NODE newNode(int value){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

GRAPH createGraph(int vertices){
    GRAPH graph = (GRAPH)malloc(sizeof(struct graph));
    graph->vertices = vertices;
    graph->values = (HEAD)malloc(vertices*sizeof(struct head));
    for (int i = 0; i < vertices; i++)
    {
        ((graph->values)+i)->head = NULL;
    }
    return graph;
}

void printMatrix(GRAPH graph, int vertices){
    int i, j;
    int a[vertices][vertices];
    NODE temp = (NODE)malloc(sizeof(struct node));
    for ( i = 0; i < vertices; i++)
    {
        temp = ((graph->values)+i)->head;
        while (temp->next != NULL)
        {
			a[i][temp->val] = 1;
			temp = temp->next;  
        }
        for (j = 0; j < vertices; j++) {
			if (a[i][j] != 1) {
				a[i][j] = 0;
			}
		}
    }

    for (i = 0; i < vertices; i++) {
		printf("[");
		for(j=0; j<vertices; j++) {
			printf("%d ", a[i][j]);
		}
		printf("]\n");
	}
}

void printGraph(GRAPH graph, int vertices) {

	int v;
	for (v = 0; v < vertices; v++) {

		printf("\nAdjacency list of vertex %d\n", v);
		NODE temp = ((graph->values)+v)->head;
		while(temp!=NULL) {
			printf("-> %d", temp->val);
			temp = temp->next;
		}
		printf("\n");
	}

	printMatrix(graph, vertices);

}

void addEdge(GRAPH graph, int src, int dest) {

	NODE temp = newNode(dest);

	if(((graph->values)+src)->head == NULL) {
		((graph->values)+src)->head = temp;
	}
	else {
		NODE lastNode = ((graph->values)+src)->head;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = temp;
	}

	temp = newNode(src);

	if(((graph->values)+dest)->head == NULL) {
		((graph->values)+dest)->head = temp;
	}
	else {
		NODE lastNode = ((graph->values)+dest)->head;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = temp;
	}

}

int main() {

	int V = 5; 
    GRAPH graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
    printGraph(graph, 5); 
    return 0; 

}