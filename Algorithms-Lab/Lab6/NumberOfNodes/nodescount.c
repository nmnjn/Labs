#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *left, *right;
};

typedef struct node * NODE;

int max(int a, int b) {
	return (a > b) ? a : b;
}

NODE newNode(int x) {
	NODE root = (NODE)malloc(sizeof(struct node));
	root->value = x;
	root->left = root->right = NULL;
	return root;
}

NODE insert(NODE node, int value) 
{ 
    if (node == NULL) return newNode(value); 
    if (value < node->value) 
        node->left  = insert(node->left, value); 
    else if (value > node->value) 
        node->right = insert(node->right, value);
    return node;
}
int count = 0;

void counter(NODE root)
{
    if (root == NULL)
        return;
    counter(root->left);
    count++;
    counter(root->right);
}

void main() {

	NODE root = NULL;
	printf("Enter Values to insert into BST, enter -1 to stop\n");
	int val = 0;
	while(val != -1){
		scanf("%d", &val);
		if (val != -1)
		{
			root = insert(root, val);
		}
	}
	counter(root);
	printf("The number of nodes are: %d\n", count);
}