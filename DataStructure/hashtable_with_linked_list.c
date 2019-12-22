//
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct Person
{
	int id;
	char name[10];

	struct Person* next;
}Person;

#define MAX_SIZE 10
Person* table[MAX_SIZE];

Person* init_user(int id, char* name)
{
	Person* p = (Person*)malloc(sizeof(Person));

	p->id = id;
	strcpy(p->name, name);
	p->next = NULL;

	return p;
}

int hash_function(int value)
{
	// int key = value % MAX_SIZE;
	int key = value / 10;

	return key;
}

void insert(Person* user)
{
	int key = hash_function(user->id);

	if (table[key] == NULL)
		table[key] = user;
	else
	{
		Person* temp = table[key];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = user;
	}
}

void get_info()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("[key = %d]", i);

		Person* temp = table[i];
		while (temp != NULL)
		{
			printf(" - [id=%d, name=%s]", temp->id, temp->name);
			temp = temp->next;
		}

		printf("\n");
	}
}

void main()
{
	char user1_name[10] = "AAA";
	char user2_name[10] = "BBB";
	char user3_name[10] = "CCC";

	Person* user1 = init_user(1, user1_name);
	Person* user2 = init_user(11, user2_name);
	Person* user3 = init_user(21, user3_name);

	insert(user1);
	insert(user2);
	insert(user3);

	get_info();
}