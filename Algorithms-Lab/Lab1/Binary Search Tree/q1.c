#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE makeNewNode(int item){ 
    NODE newNode =   (struct node *)malloc(sizeof(struct node)); 
    newNode->val = item; 
    newNode->llink = newNode->rlink = NULL; 
    return newNode; 
} 

//recursive function to insert a node in BST
NODE insertIntoBST(NODE node, int value){ 

	// if the tree is empty or it has come to leaf node
    if (node == NULL)
    	return makeNewNode(value); 
  
    if (value < node->val) 
        node->llink  = insertIntoBST(node->llink, value); 
    else if (value > node->val) 
        node->rlink = insertIntoBST(node->rlink, value);

    return node; 
} 

//function to search a value in BST

void searchBST(NODE root, int value){
	NODE backupRoot = root;
	while(root != NULL){
		if (root->val > value){
			root = root->llink;
		}else if (root->val < value)
		{
			root = root->rlink;
		}else{
			printf("\n\n\n********************\n");
			printf("Found a node with value %d", root->val);
			return;
		}
	}
	printf("\n\n\n********************\n");
	printf("Coudn't find a node with value %d\n", value);
	printf("...Inserting %d into tree\n", value);
	insertIntoBST(backupRoot, value);
	return;
}

void inorder(NODE root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->llink); 
        printf("%d ", root->val); 
        inorder(root->rlink); 
    } 
} 

void preorder(NODE root) 
{ 
    if (root != NULL) 
    { 
    	printf("%d \n", root->val); 
        inorder(root->llink); 
        inorder(root->rlink); 
    } 
} 

void postorder(NODE root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->llink); 
        inorder(root->rlink); 
        printf("%d \n", root->val); 
    } 
}

int main(){
	NODE root = NULL;
	int val;
	printf("Please create a BST by entering 10 values\n");
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &val);
		if (root == NULL)
		{
			root = insertIntoBST(root, val);
		}else{
			insertIntoBST(root, val);
		}
	}
	int choice, value;
	do{
		printf("\n\n\n********************\n");
		printf("1. Search for a value\n");
		printf("2. Pre Order Traversal\n");
		printf("3. In Order Traversal\n");
		printf("4. Post Order Traversal\n");
		printf("5. Exit\n");
		printf("Enter your choice ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Please enter the value ");
				scanf("%d", &value);
				searchBST(root, value);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				break;
			default:
				printf("Invalid Choice\n");
				break;
		}
	}while(choice != 5);
	return 0;
}

 