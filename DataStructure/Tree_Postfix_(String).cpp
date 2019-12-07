/* Java
// 2 3 4 + * 2 3 + 2 / /
int str[] = "12+7*";
char c;

Stack<Tree> stack = new Stack<Tree>();

for(int a = 0; a < str.length(); a++)
{
char c = str[a];
if(c >= '0' && c <= '9')
{
stack.push(new Tree(c));
}
else
{
Tree newNode = new Tree(c);

Tree first = stack.pop();
Tree second = stack.pop();

newNode.makeLeftSubTree(second);
newNode.makeRightSubTree(first);
stack.push(newNode);
}
}
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

// 2 3 4 + *

// '0', '1', '2', '+', '*'
typedef struct _tree_node {
	char key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct _node {
	TreeNode* tree_node;
	struct Node* front;
	struct Node* next;
}Node;

Node *head, *tail;

TreeNode* pop() {
	Node* n = tail;
	TreeNode *t = n->tree_node;

	tail = tail->front;
	free(n);

	return t;
}

void push(char v) {
	Node *n = (Node*)malloc(sizeof(Node));
	TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));

	t->key = v;

	if (v >= '0' && v <= '9')
	{
		// printf("v >= 0 && v <= 9\n");
		t->left = NULL;
		t->right = NULL;
	}
	else
	{
		// printf("v = +, -, *, /\n");
		t->right = pop();
		t->left = pop();
	}

	n->tree_node = t;
	n->front = NULL;
	n->next = NULL;

	// printf("node = %c\n", v);

	if (tail == NULL)
	{
		head = tail = n;
	}
	else
	{
		tail->next = n;
		n->front = tail;
		tail = n;
	}
}

void print_tree_node(TreeNode* root, int depth)
{
	if (depth != 1)
		if (root->key == '+' || root->key == '-' || root->key == '/')
			printf("(");

	if (root->left != NULL)
		print_tree_node(root->left, depth + 1);

	printf("%c ", root->key);

	if (root->right != NULL)
		print_tree_node(root->right, depth + 1);

	if (depth != 1)
		if (root->key == '+' || root->key == '-' || root->key == '/')
			printf(")");
}

int main(void) {

	while (1)
	{
		printf("> 후위 표기법 식을 입력하시오. (종료: x)\n");

		char input[256] = { 0, };
		gets(input);

		if (input[0] == 'x')
			break;

		////////////////////////////////////////////////
		int length = strlen(input);

		for (int i = 0; i < length; i++) {
			// printf("input[%d] = %c\n", i, );
			if (input[i] == ' ')
				continue;

			push(input[i]);
		}

		TreeNode* root = pop();
		printf("-> ");
		print_tree_node(root, 1);
		printf("\n");
		////////////////////////////////////////////////
	}

	printf("Bye~\n");

	//system("pause");

	return 0;
}
