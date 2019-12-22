#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
}Node;

Node* init_node(int key)
{
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->key = key;
	newNode->left = 0;
	newNode->right = 0;

	return newNode;
}

void postorder_traverse(struct Node* root)
{
	// 1. left
	if (root->left != NULL)
		postorder_traverse(root->left);

	// 2. right
	if (root->right != NULL)
		postorder_traverse(root->right);

	// 3. print
	printf("%d ", root->key);
}

void preorder_traverse(struct Node* root)
{
	// 1. print
	printf("%d ", root->key);

	// 2. left
	if (root->left != NULL)
		preorder_traverse(root->left);

	// 3. right
	if (root->right != NULL)
		preorder_traverse(root->right);
}

void inorder_traverse(struct Node* root)
{
	// 1. left
	if (root->left != NULL)
		inorder_traverse(root->left);

	// 2. print
	printf("%d ", root->key);

	// 3. right
	if (root->right != NULL)
		inorder_traverse(root->right);
}

void main()
{
	// * : a -> v
	// & : v -> a

	Node* node_a = init_node(1);
	Node* node_b = init_node(2);
	Node* node_c = init_node(3);
	Node* node_d = init_node(4);
	Node* node_e = init_node(5);

	node_b->left = node_d;
	node_b->right = node_e;

	node_a->left = node_b;
	node_a->right = node_c;

	// Àç±ÍÇÔ¼ö
	preorder_traverse(node_a); printf("\n");
	inorder_traverse(node_a); printf("\n");
	postorder_traverse(node_a); printf("\n");
}