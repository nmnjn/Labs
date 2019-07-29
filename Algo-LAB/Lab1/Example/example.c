#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE head = NULL;

struct node *makeNewNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// function to create the list

void CreateList(int val){
	NODE newNode;
	if (head == NULL){
		newNode = makeNewNode(val);
		head = newNode;
	}else{
		printf("%s\n", "List is already created...");
	}
}

// function to insert a node into the existing list before a given value

void insertIntoList(int before, int val){
	NODE traverseNode, newNode;
	traverseNode = head;
	while(traverseNode != NULL && traverseNode->val != before)
		traverseNode = traverseNode->rlink;
	if (traverseNode != NULL)
	{
		newNode = (NODE)malloc(sizeof(struct node));
		newNode->rlink = newNode->llink = NULL;
		newNode->val = val;
		if (traverseNode->llink != NULL)
		{
			traverseNode->llink->rlink = newNode;
			newNode->llink = traverseNode->llink;
			newNode->rlink = traverseNode;
			traverseNode->llink = newNode;
		}else{
			newNode->rlink = traverseNode;
			traverseNode->llink = newNode;
			head = newNode;
		}
	}else{
		printf("Unable to insert, node with value %d not found\n", val);
	}
}

// function to delete a node for a given value

void deleteAll(int delVal){
	NODE traverseNode, nextNode;
	traverseNode = head;

	while(traverseNode != NULL){
		if (traverseNode->val == delVal){
			if (traverseNode->llink != NULL)
			{
				//Node is not the first node
				traverseNode->llink->rlink = traverseNode->rlink;
				if (traverseNode->rlink != NULL)
				{
					//Node is not the last node
					traverseNode->rlink->llink = traverseNode->llink;
					nextNode = traverseNode->rlink;
					free(traverseNode);
					traverseNode = nextNode;
				}else{
					//Node is the last node
					traverseNode->llink->rlink = NULL;
					free(traverseNode);
					traverseNode = NULL;
				}
			}else{
				//Node is the first node
				if (traverseNode->rlink != NULL){
					//Node is not the last node
					traverseNode->rlink->llink = NULL;
					head = traverseNode->rlink;
					free(traverseNode);
					traverseNode = head;
				}else{
					//Node is the last node
					free(traverseNode);
					head = traverseNode = NULL;
				}
			}
		}else{
			traverseNode = traverseNode->rlink;
		}
	}
}

//fucntion to search for a given value in the list

void searchNode(int searchVal){
	NODE traverseNode;
	traverseNode = head;

	while(traverseNode != NULL){
		if (traverseNode->val == searchVal)
		{
			printf("Node is found with the key %d\n", searchVal);
		}
		traverseNode = traverseNode->rlink;
	}
}

// function to print the entire list
void displayAll(){
	NODE traverseNode;
	traverseNode = head;

	while(traverseNode != NULL){
		printf("Node with value %d\n", traverseNode->val);
		traverseNode = traverseNode->rlink;
	}
}

int main(){
	int choice, value, before;

	do{
		printf("\n\n\n********************\n");
		printf("1. Create List\n");
		printf("2. Insert into List\n");
		printf("3. Delete all by value\n");
		printf("4. Search by value\n");
		printf("5. Display all\n");
		printf("6. Exit\n");
		printf("Enter your choice ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Please enter the node value ");
				scanf("%d", &value);
				CreateList(value);
				break;
			case 2:
				printf("Please enter the node value to insert ");
				scanf("%d", &value);
				printf("Please enter the value before which the new node has to be insterted ");
				scanf("%d", &before);
				insertIntoList(before, value);
				break;
			case 3:
				printf("Enter the node to be deleted ");
				scanf("%d", &value);
				deleteAll(value);
				break;
			case 4:
				printf("Enter the node value to be searched ");
				scanf("%d", &value);
				searchNode(value);
				break;
			case 5:
				displayAll();
				break;
			case 6:
				break;
			default:
				printf("Invalid Choice\n");
				break;
		}
	}while(choice != 6);
	return 0;
}




