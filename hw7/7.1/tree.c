#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct Node
{
    struct Node* leftChild;
    struct Node* rightChild;
    struct Node* parent;
    int key;
    char* value;
} Node;


Node* createTree()
{
    return NULL;
}

void freeTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root->value);
    free(root);
}

Node** findNode(Node* root, const int key)
{
    Node** pointerRoot = &root;
    Node* current = *pointerRoot;
    while (current != NULL && current->key != key)
    {
        pointerRoot = (key < current->key ? &current->leftChild : &current->rightChild);
        current = *pointerRoot;
    }
    return pointerRoot;
}

char* findValue(Node* root, const int key)
{
    Node* foundNode = *findNode(root, key);
    return foundNode == NULL ? NULL : foundNode->value;
}

void addNode(Node** root, const int key, const char* value)
{
    Node** node = findNode(root, key);
    if (*node != NULL)
    {
        free((*node)->value);
        (*node)->value = calloc(strlen(value) + 1, sizeof(char));
        if ((*node)->value == NULL)
        {
            free(*node);
            return;
        }
        strcpy((*node)->value, value);
        return;
    }
    *node = calloc(1, sizeof(Node));
    if (*node == NULL)
    {
        return;
    }
    (*node)->key = key;
    (*node)->value = calloc(strlen(value) + 1, sizeof(char));
    if ((*node)->value == NULL)
    {
        free(*node);
        return;
    }
    strcpy((*node)->value, value);
}

void deleteNode(Node** root, const int key)
{
    Node** node = findNode(root, key);
    if (*node == NULL)
    {
        return;
    }
    if ((*node)->rightChild == NULL)
    {
        Node* nodeToDelete = *node;
        *node = (*node)->leftChild;
        free(nodeToDelete);
        return;
    }
    Node** next = &(*node)->rightChild;
    while ((*next)->leftChild != NULL)
    {
        next = &(*next)->leftChild;
    }

    char* const tmpStr = (*node)->value;
    (*node)->value = (*next)->value;
    (*next)->value = tmpStr;

    const int tmpInt = (*node)->key;
    (*node)->key = (*next)->key;
    (*next)->key = tmpInt;

    Node* nodeToDelete = *next;
    *next = (*next)->rightChild;
    free(nodeToDelete->value);
    free(nodeToDelete);
}
