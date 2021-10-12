#pragma once

typedef struct
{
	char name[101];
	char number[101];
	struct Person *next;
} Person;

int listLen(Person** iterator);
void loadList(Person** iterator);
void addPerson(Person** iterator, const char* name, const char* number);
void printList(Person** iterator);
Person* findByNumber(Person** iterator, const char* number);
Person* findByName(Person** iterator, const char* name);
void saveList(Person** iterator);
void freeList(Person* iterator);




