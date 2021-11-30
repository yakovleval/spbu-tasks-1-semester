#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

bool testAddAndFind()
{
    Node* root = createTree();
    addNode(&root, 555, "string1");
    addNode(&root, 666, "string 2");
    const bool result = *findNode(root, 555) != NULL &&
        *findNode(root, 666) != NULL &&
        *findNode(root, 0) == NULL;
    freeTree(root);
    return result;
}

bool testChange()
{
    Node* root = createTree();
    addNode(&root, 555, "string1");
    addNode(&root, 666, "string2");
    addNode(&root, 555, "string");
    const bool result = strcmp(findValue(root, 555), "string") == 0;
    freeTree(root);
    return result;
}

bool testDel()
{
    Node* root = createTree();
    addNode(&root, 555, "string1");
    addNode(&root, 666, "string2");
    addNode(&root, 555, "string");
    const bool result = strcmp(findValue(root, 555), "string") == 0;
    freeTree(root);
    return result;
}

bool isPassed()
{
    return testAddAndFind() &&
        testChange() &&
        testDel();
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

    printf("0 -- выйти из программы\n");
    printf("1 -- добавить новую запись\n");
    printf("2 -- найти запись по ключу\n");
    printf("3 -- проверить наличие записи\n");
    printf("4 -- удалить запись\n");
    Node* root = createTree();
    const int bufferSize = 101;
    int key = 0;
    char buffer[101] = {0};
    while (true)
    {
        printf("Введите номер действия: \n");
        int action = 0;
        scanf(" %d", &action);
        switch (action)
        {
        case 0:
            freeTree(root);
            return;
        case 1:
            printf("введите ключ и значение: \n");
            scanf("%d", &key);
            scanf("%s", &buffer);
            addNode(&root, key, buffer);
            break;
        case 2:
            printf("введите ключ: \n");
            scanf("%d", &key);
            char* foundValue = findValue(root, key);
            if (foundValue == NULL)
            {
                printf("Записи с таким ключом нет\n");
            }
            else
            {
                printf("%s\n", foundValue);
            }
            break;
        case 3:
            printf("введите ключ: \n");
            scanf("%d", &key);
            if (*findNode(root, key) == NULL)
            {
                printf("Записи с таким ключом нет\n");
            }
            else
            {
                printf("Запись с таким ключом есть\n");
            }
            break;
        case 4:
            printf("введите ключ: \n");
            scanf("%d", &key);
            deleteNode(&root, key);
            break;
        default:
            printf("некорректный ввод\n");
            break;
        }
    }
}
