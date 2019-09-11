#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) ((A > B) ? A : B)

typedef enum { NO, YES } BOOL;

typedef struct TNode {
	int data;
	int height;
	struct TNode *left;
	struct TNode *right;
} TNODE_t, *NODE;

NODE initNode (int data) {
	NODE node = (NODE)malloc(sizeof(TNODE_t));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

int height (NODE tree) {
	if (tree == NULL)
		return 0;
	return tree->height;
}

#pragma mark - Rotate

NODE rotateRight (NODE tree) {

	NODE left = tree->left;
	NODE lr = left->right;

	left->right = tree;
	tree->left = lr;

	tree->height = MAX(height(tree->left), height(tree->right)) + 1;
	left->height = MAX(height(left->left), height(left->right)) + 1;

	return left;

}

NODE rotateLeft (NODE tree) {

	NODE right = tree->right;
	NODE rl = right->left;

	right->left = tree;
	tree->right = rl;

	tree->height = MAX(height(tree->left), height(tree->right)) + 1;
	right->height = MAX(height(right->left), height(right->right)) + 1;

	return right;

}

int differenceHeights (NODE tree) {
	if (tree == NULL)
		return 0;
	return height(tree->left) - height(tree->right);
}


NODE insertItem (NODE tree, int item) {

	if (tree == NULL) {
		return initNode(item);
	}

	if (item < tree->data) {
		tree->left = insertItem(tree->left, item);
	} else {
		tree->right = insertItem(tree->right, item);
	}

	tree->height = MAX(height(tree->left), height(tree->right)) + 1;

	int dh = differenceHeights(tree);

	if (dh > 1) {
		if (item > tree->left->data) {
			tree->left = rotateLeft(tree->left);
		}
		return rotateRight(tree);
	}

	if (dh < -1) {
		if (item < tree->right->data) {
			tree->right = rotateRight(tree->right);
		}
		return rotateLeft(tree);
	} 

	return tree;

}

NODE buildTree () {
	
	int data;
	NODE root = NULL;
	
	do {
		printf("Enter data (-1 for break): ");
		scanf(" %d", &data);
		
		if (data != -1) {
			root = insertItem(root, data);
		}

	} while (data != -1);
	
	return root;
}


void preorderTransversal (NODE root) {
	if (root != NULL) {
		printf(" %d", root->data);
		preorderTransversal(root->left);
		preorderTransversal(root->right);
	}
}

void inorderTransversal (NODE root) {
	if (root != NULL) {
		inorderTransversal(root->left);
		printf(" %d", root->data);
		inorderTransversal(root->right);
	}
}

void postorderTransversal (NODE root) {
	if (root != NULL) {
		postorderTransversal(root->left);
		postorderTransversal(root->right);
		printf(" %d", root->data);
	}
}



int main (int argc, const char * argv []) {
	
	NODE tree = buildTree();
	
	int choice;
	BOOL displayOptions = YES;
	do {

		if (displayOptions) {
			printf("\n 1. Preorder traversal.");
			printf("\n 2. Inorder traversal.");
			printf("\n 3. Postorder traversal.");
		}
		displayOptions = NO;
		printf("\nChoice: ");
		scanf(" %d", &choice);
		
		if (choice == 1) {
			printf("\n   Preorder: ");
			preorderTransversal(tree);
		}
		
		else if (choice == 2) {
			printf("\n    Inorder: ");
			inorderTransversal(tree);
		}
		
		else if (choice == 3) {
			printf("\n  Postorder: ");
			postorderTransversal(tree);
		}
		
	} while (choice >= 1 && choice <= 4);
	
}




