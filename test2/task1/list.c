#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void reverseList(Node** head)
{
    Node* newHead = NULL;
    for (Node* current = *head; current != NULL;)
    {
        Node* next = current->next;
        current->next = newHead;
        newHead = current;
        current = next;
    }
    *head = newHead;
}

void freeList(Node** head)
{
    for (Node* current = *head; current != NULL;)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

Node* initList(const char* filename)
{
    Node* head = NULL;
    FILE* in = fopen(filename, "r");
    int number = 0;
    Node** current = &head;
    while (fscanf(in, "%d", &number) > 0)
    {
        *current = calloc(1, sizeof(Node));
        if (*current == NULL)
        {
            return NULL;
        }
        (*current)->value = number;
        current = &(*current)->next;
    }
    fclose(in);
    return head;
}