// Copyright(C) 2019 * Ltd.All rights reserved.
// author : SangHyeon Jo <josanghyeokn@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct _Node {
	int value[MAX_SIZE];
	struct _Node* next;
}Node;

typedef struct _Stack {
	int count;
	Node* head;
}Stack;

Stack *stack;

void init_stack()
{
	stack = (Stack*)malloc(sizeof(Stack));

	stack->count = 0;
	stack->head = NULL;
}

void push(int value)
{
	if (stack->count % MAX_SIZE == 0)
	{
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->value[0] = value;
		new_node->next = NULL;
		
		if (stack->head == NULL)
			stack->head = new_node;
		else
		{
			new_node->next = stack->head;
			stack->head = new_node;
		}
	}
	else
	{
		int index = stack->count % MAX_SIZE;
		stack->head->value[index] = value;
	}
	
	stack->count++;
}

int pop()
{
	int index = (stack->count - 1) % MAX_SIZE;
	int value = stack->head->value[index];

	stack->count--;
	// printf("stack_count = %d, index = %d\n", stack->count, index);

	if (index == 0)
	{
		Node* temp = stack->head;
		stack->head = stack->head->next;

		free(temp);
		temp = NULL;
	}

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
	[i] pop = 10, stack->count = 10
	[i] pop = 9, stack->count = 9
	[i] pop = 8, stack->count = 8
	[i] pop = 7, stack->count = 7
	[i] pop = 6, stack->count = 6
	[i] pop = 5, stack->count = 5
	[i] pop = 4, stack->count = 4
	[i] pop = 3, stack->count = 3
	[i] pop = 2, stack->count = 2
	[i] pop = 1, stack->count = 1
	*/
	init_stack();

	for (int i = 1; i <= MAX_SIZE * 2; i++)
	{
		push(i);
		printf("[i] push = %d\n", i);
	}

	for (int i = 1; i <= MAX_SIZE * 2; i++)
	{
		printf("[i] pop = %d, stack->count = %d\n", pop(), stack->count);
	}

	system("pause");
}