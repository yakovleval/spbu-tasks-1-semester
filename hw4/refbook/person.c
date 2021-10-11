#include <stdio.h>
#include "person.h"

int listLen(Person* iterator)
{
	int listLen = 0;
	while (iterator != NULL)
	{
		listLen++;
		iterator = iterator->next;
	}
	return listLen;
}

void loadList(Person* iterator, const FILE* file)
{
	int length = 0;
	fscanf(file, "%d", &length);
	char personName[100] = {0};
	char phoneNumber[100] = {0};
	for (int i = 0; i < length; i++)
	{
		fscanf(file, "%[^\n]\n", personName);
		fscanf(file, "%[^\n]\n", phoneNumber);
		iterator = (Person*)malloc(sizeof(Person));
		strcmp(iterator->personName, personName);
		strcmp(iterator->phoneNumber, phoneNumber);
		iterator = iterator->next;
		iterator = NULL;
	}
}

Person* addPerson(Person* iterator, const char* phoneNumber, const char* personName)
{
	while (iterator != NULL)
	{
		iterator = iterator->next;
	}
	iterator = (Person*)malloc(sizeof(Person));
	strcpy(iterator->phoneNumber, phoneNumber);
	strcpy(iterator->personName, personName);
	iterator->next = NULL;
	return iterator;
}

void printList(Person* iterator)
{
	while (iterator != NULL)
	{
		printf("Имя: %s\n", iterator->personName);
		printf("Номер: %s\n\n", iterator->phoneNumber);
		iterator = iterator->next;
	}
}

Person* findByNumber(Person* iterator, const char* phoneNumber)
{
	while (iterator != NULL && strcmp(iterator->phoneNumber, phoneNumber) != 0)
	{
		iterator = iterator->next;
	}
	return iterator;
}

Person* findByName(Person* iterator, const char* name)
{
	while (iterator != NULL && strcmp(iterator->personName, name) != 0)
	{
		iterator = iterator->next;
	}
	return iterator;
}

void saveList(Person* iterator, const FILE* file)
{
	int length = listLen(iterator);
	printf("%d\n", listLen);
	while (iterator != NULL)
	{
		printf("%s\n", iterator->personName);
		printf("%s\n", iterator->phoneNumber);
		iterator = iterator->next;
	}
}

void freeList(Person* iterator)
{
	while (iterator != NULL)
	{
		Person* next = iterator->next;
		free(iterator);
		iterator = next;
	}
}