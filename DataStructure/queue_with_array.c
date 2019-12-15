#include<stdio.h>

#define QUEUE_SIZE 10
int queue[QUEUE_SIZE];
int e = 0;
int f = 0;

int push(int value)
{
	// f = 0, e = 4
	// 5 % QUEUE_SIZE => 0
	if ((e + 1) % QUEUE_SIZE == f)
		return 0;

	// f = 0, e = 0
	queue[e] = value;
	// e = 1 % 5
	e = (e + 1) % QUEUE_SIZE;

	return 1;
}

int pop()
{
	if (f == e)
		return 0;

	int value = queue[f];
	f = (f + 1) % QUEUE_SIZE;

	return value;
}

// 0 ->10 ->20 ->30 ->40 ->50 ->60 ->70 ->80 ->90 ->
// 0 -> 10 -> 20 -> 30 -> ... -> 80 -> 90
void print()
{
	if (e == 0)
		return;

	// queue -> -> -> -> -> ...
	for (int i = f; i != e; i = (i + 1) % QUEUE_SIZE)
	{
		// 0 ~ 9
		// printf("i = %d : %d\n", i, queue[i]);
		printf(" %d ", queue[i]);

		if (i != (e - 1))
			printf("->");
	}
	printf("\n");
}

void main()
{
	for (int i = 0; i < 5; i++)
	{
		push(i * 10);
	}

	print();

	for (int i = 5; i < 10; i++)
	{
		push(i * 10);
	}

	/*for (int i = 0; i < 5; i++)
	{
	printf("pop() = %d\n", pop());
	}*/

	print();

	for (int i = 0; i < 5; i++)
	{
		printf("pop() = %d\n", pop());
	}

	print();

	for (int i = 5; i < 10; i++)
	{
		push(i * 10);
	}

	print();

}