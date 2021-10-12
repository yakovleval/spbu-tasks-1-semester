#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

int listLen(Person** iterator)
{
	int listLen = 0;
	while (*iterator != NULL)
	{
		listLen++;
		iterator = &(*iterator)->next;
	}
	return listLen;
}

void loadList(Person** iterator)
{
	FILE* in = fopen("data.txt", "r");
	if (in == NULL)
	{
		return;
	}
	int length = 0;
	fscanf(in, " %d", &length);
	char personName[101] = {0};
	char phoneNumber[101] = {0};
	for (int i = 0; i < length; i++)
	{
		fscanf(in, "%*d");
		fscanf(in, " %[^\n]", personName);
		fscanf(in, " %[^\n]", phoneNumber);
		*iterator = (Person*)malloc(sizeof(Person));
		strcpy((*iterator)->personName, personName);
		strcpy((*iterator)->phoneNumber, phoneNumber);
		(*iterator)->next = NULL;
		iterator = &(*iterator)->next;
	}
	fclose(in);
}

void addPerson(Person** iterator, const char* personName, const char* phoneNumber)
{
	while (*iterator != NULL)
	{
		iterator = &(*iterator)->next;
	}
	*iterator = (Person*)malloc(sizeof(Person));
	strcpy((*iterator)->personName, personName);
	strcpy((*iterator)->phoneNumber, phoneNumber);
	(*iterator)->next = NULL;
}

void printList(Person** iterator)
{
	int index = 1;
	while (*iterator != NULL)
	{
		printf("%d\n", index);
		index++;
		printf("Имя: %s\n", (*iterator)->personName);
		printf("Номер: %s\n", (*iterator)->phoneNumber);
		iterator = &(*iterator)->next;
	}
}

Person* findByNumber(Person** iterator, const char* phoneNumber)
{
	while (*iterator != NULL && strcmp((*iterator)->phoneNumber, phoneNumber) != 0)
	{
		iterator = &(*iterator)->next;
	}
	return *iterator;
}

Person* findByName(Person** iterator, const char* name)
{
	while (*iterator != NULL && strcmp((*iterator)->personName, name) != 0)
	{
		iterator = &(*iterator)->next;
	}
	return *iterator;
}

void saveList(Person** iterator)
{
	FILE* out = fopen("data.txt", "w");
	fprintf(out, "%d\n", listLen(iterator));
	int index = 1;
	while (*iterator != NULL)
	{
		fprintf(out, "%d\n", index);
		index++;
		fprintf(out, "%s\n", (*iterator)->personName);
		fprintf(out, "%s\n", (*iterator)->phoneNumber);
		iterator = &(*iterator)->next;
	}
	fclose(out);
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