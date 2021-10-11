#pragma once
#include <string.h>

typedef struct
{
	char personName[100];
	char phoneNumber[100];
	struct Person *next;
} Person;

Person *head = NULL;

int listLen(Person* iterator);
void loadList(Person* iterator, const FILE* file);
Person* addPerson(Person* iterator, const char* phoneNumber, const char* personName);
void printList(Person* iterator);
Person* findByNumber(Person* iterator, const char* phoneNumber);
Person* findByName(Person* iterator, const char* name);
void saveList(Person* iterator, const FILE* file);
void freeList(Person* iterator);




