// Copyright(C) 2019 * Ltd.All rights reserved.
// author : SangHyeon Jo <josanghyeokn@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct _Node {
	int value;
	struct _Node* next;
}Node;

Node *head, *tail;

void push(int value)
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
		new_node->next = head;
		head = new_node;
	}
}

int pop()
{
	Node* temp = head;
	if (temp == NULL)
		return;

	int value = temp->value;
	head = head->next;

	free(temp);
	temp = NULL;
	
	return value;
}

int main()
{
	/*
	[i] push = 1
	[i] push = 2
	[i] push = 3
	[i] push = 4
	[i] push = 5
	[i] push = 6
	[i] push = 7
	[i] push = 8
	[i] push = 9
	[i] push = 10
	[i] pop = 10
	[i] pop = 9
	[i] pop = 8
	[i] pop = 7
	[i] pop = 6
	[i] pop = 5
	[i] pop = 4
	[i] pop = 3
	[i] pop = 2
	[i] pop = 1
	*/
	for (int i = 1; i <= MAX_SIZE; i++)
	{
		push(i);
		printf("[i] push = %d\n", i);
	}

	for (int i = 1; i <= MAX_SIZE; i++)
	{
		printf("[i] pop = %d\n", pop());
	}

	system("pause");
}