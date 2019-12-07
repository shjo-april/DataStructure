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
		printf("v >= 0 && v <= 9\n");
		t->left = NULL;
		t->right = NULL;
	}
	else
	{
		printf("v = +, -, *, /\n");
		t->left = pop();
		t->right = pop();
	}

	n->tree_node = t;
	n->front = NULL;
	n->next = NULL;

	printf("node = %c\n", v);

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

int print_tree_node(TreeNode* root)
{
	if (root->key >= '0' && root->key <= '9')
	{
		return root->key - '0'; // '1' - '0' = 1
	}
	else
	{
		char c = root->key;

		int data1 = print_tree_node(root->left);
		int data2 = print_tree_node(root->right);

		if (c == '+')
			return data1 + data2;
		else if (c == '-')
			return data1 - data2;
		else if (c == '*')
			return data1 * data2;
		else if (c == '/')
			return data1 / data2;
	}
}

int main(void) {

	while (1)
	{
		printf("> 후위 표기법 식을 입력하시오. (종료: x)\n");

		char input[256] = { 0, };
		scanf("%s", input);

		if (input[0] == 'x')
			break;

		////////////////////////////////////////////////
		for (int i = 0; i < strlen(input); i++)
		{
			push(input[i]);
		}

		TreeNode* root = pop();

		int result = print_tree_node(root);
		printf("result = %d\n", result);
		////////////////////////////////////////////////
	}

	system("pause");

	return 0;
}
