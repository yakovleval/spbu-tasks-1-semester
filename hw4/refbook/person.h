#pragma once

typedef struct
{
	char personName[101];
	char phoneNumber[101];
	struct Person *next;
} Person;

int listLen(Person** iterator);
void loadList(Person** iterator);
void addPerson(Person** iterator, const char* personName, const char* phoneNumber);
void printList(Person** iterator);
Person* findByNumber(Person** iterator, const char* phoneNumber);
Person* findByName(Person** iterator, const char* name);
void saveList(Person** iterator);
void freeList(Person* iterator);




