// Copyright(C) 2019 * Ltd.All rights reserved.
// author : SangHyeon Jo <josanghyeokn@gmail.com>

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int value;
	struct _Node* front;
	struct _Node* next;
}Node;

Node *head, *tail;

void insert_node(int value)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
		return;

	new_node->value = value;
	new_node->front = NULL;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = tail = new_node;
	}
	else
	{
		tail->next = new_node;
		new_node->front = tail;

		tail = new_node;
	}
}

void print_nodes_ascending()
{
	Node* temp = head;
	printf("# Ascending : ");

	do {
		printf("%d ", temp->value);
		temp = temp->next;
	} while (temp != NULL);

	printf("\n");
}

void print_nodes_descending()
{
	Node* temp = tail;
	printf("# Descending : ");

	do {
		printf("%d ", temp->value);
		temp = temp->front;
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

	/*
	# Ascending : 1 2 3 4 5
	# Descending : 5 4 3 2 1
	*/
	print_nodes_ascending();
	print_nodes_descending();

	delete_nodes();

	system("pause");
}