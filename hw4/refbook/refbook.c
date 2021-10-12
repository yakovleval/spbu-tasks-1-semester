#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "person.h"
#define _CRT_SECURE_NO_WARNINGS

bool testAddPerson()
{
	const int testsNumber = 3;
	Person* list = NULL;
	const char* names[3] = {"testname", "testname2", "testname3"};
	const char* numbers[3] = {"+79000000000", "1234", "239"};
	for (int i = 0; i < testsNumber; i++)
	{
		addPerson(&list, names[i], numbers[i]);
	}
	bool result = true;
	int i = 0;
	for (Person** iterator = &list; *iterator != NULL; iterator = &(*iterator)->next, i++)
	{
		result &= strcmp((*iterator)->name, names[i]) == 0;
		result &= strcmp((*iterator)->number, numbers[i]) == 0;
	}
	return result;
}

bool testFindByNumber()
{
	const int testsNumber = 3;
	Person* list = NULL;
	const char* names[3] = { "testname", "testname2", "testname3" };
	const char* numbers[3] = { "+79000000000", "1234", "239" };
	for (int i = 0; i < testsNumber; i++)
	{
		addPerson(&list, names[i], numbers[i]);
	}
	bool result = true;
	for (int i = 0; i < testsNumber; i++)
	{
		Person* node = findByNumber(&list, numbers[i]);
		result &= strcmp(node->number, numbers[i]) == 0;
	}
	return result;
}

bool testFindByName()
{
	const int testsNumber = 3;
	Person* list = NULL;
	const char* names[3] = { "testname", "testname2", "testname3" };
	const char* numbers[3] = { "+79000000000", "1234", "239" };
	for (int i = 0; i < testsNumber; i++)
	{
		addPerson(&list, names[i], numbers[i]);
	}
	bool result = true;
	for (int i = 0; i < testsNumber; i++)
	{
		Person* node = findByName(&list, names[i]);
		result &= strcmp(node->name, names[i]) == 0;
	}
	return result;
}

bool isPassed()
{
	return testAddPerson() &&
		testFindByName() &&
		testFindByNumber();
}

void main()
{
	setlocale(LC_ALL, "Russian");
	if (!isPassed())
	{
		printf("тесты не пройдены\n");
		return;
	}
	printf("тесты пройдены\n");
	const int bufSize = 101;
	Person* list = NULL;
	char name[101] = {0};
	char number[101] = {0};
	loadList(&list);
	while (true)
	{
		printf("Введите номер действия:\n");
		int action = 0;
		Person* node = NULL;
		scanf(" %d", &action);
		if (action == 0)
		{
			freeList(list);
			return;
		}
		else if (action == 1)
		{
			printf("Введите имя и номер:\n");
			scanf(" %[^\n]", name);
			scanf(" %[^\n]", number);
			addPerson(&list, name, number);
		}
		else if (action == 2)
		{
			printList(&list);
		}
		else if (action == 3)
		{
			printf("Введите имя:\n");
			scanf(" %[^\n]", name);
			node = findByName(&list, name);
			if (node == NULL)
			{
				printf("Запись не найдена\n");
			}
			else
			{
				printf("Номер телефона: %s\n", node->number);
			}
		}
		else if (action == 4)
		{
			printf("Введите номер:\n");
			scanf(" %[^\n]", number);
			node = findByNumber(&list, number);
			if (node == NULL)
			{
				printf("Запись не найдена\n");
			}
			else
			{
				printf("Имя: %s\n", node->name);
			}
		}
		else if (action == 5)
		{
			saveList(&list);
			printf("Список сохранён в файл\n");
		}
	}
}