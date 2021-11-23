#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

bool testReverse()
{
    Node* head = initList("testReverse.txt");
    reverseList(&head);
    int answer[6] = {60, 50, 40, 30, 20, 10};
    bool result = true;
    Node* current = head;
    for (int i = 0; i < 6; i++)
    {
        result &= current->value == answer[i];
        current = current->next;
    }
    freeList(&head);
    return result;
}

bool testOneElement()
{
    Node* head = initList("testOneElem.txt");
    reverseList(&head);
    int answer[1] = {10};
    bool result = true;
    Node* current = head;
    for (int i = 0; i < 1; i++)
    {
        result &= current->value == answer[i];
        current = current->next;
    }
    freeList(&head);
    return result;
}

bool isPassed()
{
    return testReverse() &&
        testOneElement();
}

void main()
{
    setlocale(LC_ALL, "Russian");
    if (!isPassed())
    {
        printf("Тесты не пройдены\n");
        return;
    }
    printf("Тесты пройдены\n");

    Node* head = initList("file.txt");
    reverseList(&head);
    for (Node* current = head; current != NULL; current = current->next)
    {
        printf("%d ", current->value);
    }
    freeList(&head);
}
