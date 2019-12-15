/*
h, t

push
pop
print

push(1)
push(2)
push(3)
print() # 1 -> 2 -> 3

pop()
pop()
print() # 3

push(4)
push(5)
push(6)
print() # 3 -> 4 -> 5 -> 6

pop()
pop()
pop()
pop()
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int key;
	struct Node* next;
};
typedef struct Node* NodePtr;

NodePtr h = NULL;
NodePtr t = NULL;

int push(int key)
{
	NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
	newNode->key = key;
	newNode->next = NULL;

	if (h == NULL)
	{
		h = t = newNode;
	}
	else
	{
		t->next = newNode; // tail다음에 newNode연결
		t = newNode; // (아직 tail이 맨 마지막에 있는 상태가 아니므로) tail을 newNode, 즉 맨 마지막 node를 가리키게 해줌
	}

	return 1;
}

int pop()
{
	NodePtr temp = h; // temp가 head를 가리키고 있음
	int value = temp->key;

	h = h->next;
	free(temp);

	return value;
}

void print()
{
	NodePtr temp = h;
	if (temp == NULL)
		return;

	do {
		printf("%d ", temp->key);
		temp = temp->next;
	} while (temp != NULL);
	printf("\n");
}

void main()
{
	for (int i = 1; i <= 3; i++)
	{
		push(i); // 1, 2, 3
	}
	print();

	for (int i = 0; i < 2; i++)
	{
		printf("%d\n", pop()); // 3
	}

	for (int i = 1; i <= 3; i++)
	{
		push(i); // 3, 1, 2, 3
	}
	print();

	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", pop());
	}

}