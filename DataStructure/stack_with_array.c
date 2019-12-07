// Copyright(C) 2019 * Ltd.All rights reserved.
// author : SangHyeon Jo <josanghyeokn@gmail.com>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

#define TRUE 1
#define FALSE 0

int top = -1;
int stack[MAX_SIZE];

int push(int value)
{
	if (top >= MAX_SIZE - 1)
	{
		printf("[!] Stack overflow\n");
		return FALSE;
	}

	stack[++top] = value;
	return TRUE;
}

int pop()
{
	if (top < 0)
	{
		printf("[!] Stack underflow\n");
		return FALSE;
	}

	return stack[top--];
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
	[!] Stack overflow
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
	[!] Stack underflow
	*/
	for (int i = 1; i <= (MAX_SIZE + 1); i++)
	{
		if (push(i))
			printf("[i] push = %d\n", i);
	}

	for (int i = 1; i <= (MAX_SIZE + 1); i++)
	{
		int ret = pop();
		if (ret != FALSE)
			printf("[i] pop = %d\n", ret);
	}

	system("pause");

	return 0;
}