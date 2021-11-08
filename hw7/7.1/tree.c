#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Node* createTree()
{
    return NULL;
}

void freeTree(Node** root)
{
    if (*root == NULL)
    {
        return;
    }
    freeTree(&(*root)->leftChild);
    freeTree(&(*root)->rightChild);
    free((*root)->value);
    free(*root);
}

Node** find(Node** root, const int key)
{
    while (*root != NULL && (*root)->key != key)
    {
        root = (key < (*root)->key ? &(*root)->leftChild : &(*root)->rightChild);
    }
    return root;
}

void add(Node** root, const int key, const char* value)
{
    Node** node = find(root, key);
    if (*node != NULL)
    {
        free((*node)->value);
        (*node)->value = calloc(strlen(value) + 1, sizeof(char));
        strcpy((*node)->value, value);
        return;
    }
    *node = calloc(1, sizeof(Node));
    (*node)->key = key;
    (*node)->value = calloc(strlen(value) + 1, sizeof(char));
    strcpy((*node)->value, value);
}

void del(Node** root, const int key)
{
    Node** node = find(root, key);
    if (*node == NULL)
    {
        return;
    }
    if ((*node)->rightChild == NULL)
    {
        *node = (*node)->leftChild;
        return;
    }
    Node** next = &(*node)->rightChild;
    while ((*next)->leftChild != NULL)
    {
        next = &(*next)->leftChild;
    }

    const char* tmpstr = (*node)->value;
    (*node)->value = (*next)->value;
    (*next)->value = tmpstr;

    const int tmpint = (*node)->key;
    (*node)->key = (*next)->key;
    (*next)->key = tmpint;

    Node* nodeToDelete = *next;
    *next = (*next)->rightChild;
    free(nodeToDelete->value);
    free(nodeToDelete);
}
