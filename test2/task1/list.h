#pragma once

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

void reverseList(Node** head);
void freeList(Node** head);
Node* initList(const char* filename);
