#include <stdio.h>

typedef struct Person
{
	int id;
	char name[10];
}Person;

///////////////////////////////////////////////////
// Hash
///////////////////////////////////////////////////
#define MAX_SIZE 10
Person table[MAX_SIZE];

int hash_function(int value)
{
	int key = value % MAX_SIZE;
	return key;
}

void insert(Person user)
{
	int key = hash_function(user.id);
	table[key] = user;
}

Person search(int id)
{
	int key = hash_function(id);
	return table[key];
}

/*
key = 0 : [name, id]
key = 1 : [name, id]
key = 2 : [name, id]
...
key = 9 : [name, id]
*/
void get_info()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("key = %d : [%s, %d]\n", i, table[i].name, table[i].id);
	}
}

int main()
{
	while (1)
	{
		int select;
		printf("1. insert, 2. search, 3. info\n");
		printf("=> "); scanf("%d", &select);

		if (select == 1)
		{
			Person user;
			printf("id : "); scanf("%d", &user.id);
			printf("name : "); scanf("%s", user.name);

			insert(user);
		}

		else if (select == 2)
		{
			Person user;
			printf("id : "); scanf("%d", &user.id);

			user = search(user.id);

			if (user.id != 0)
				printf("[%s %d]\n", user.name, user.id);
		}

		else
		{
			get_info();
		}
	}

	return 0;
}