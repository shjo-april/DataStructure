// Copyright(C) 2019 * Ltd.All rights reserved.
// author : SangHyeon Jo <josanghyeokn@gmail.com>

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int value;
	struct _Node* next;
}Node;

Node *head, *tail;

void insert_node(int value)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
		return;

	new_node->value = value;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}
}

void print_nodes()
{
	Node* temp = head;
	do {
		printf("%d ", temp->value);
		temp = temp->next;
	} while (temp != NULL);
	printf("\n");
}

void delete_nodes()
{
	Node* temp = NULL;

	do {
		temp = head;
		head = head->next;

		free(temp);
		temp = NULL;
	} while (head != NULL);

	head = tail = NULL;
}

int main()
{
	for (int i = 1; i <= 5; i++)
		insert_node(i);

	// 1 2 3 4 5
	print_nodes();

	delete_nodes();

	system("pause");
}