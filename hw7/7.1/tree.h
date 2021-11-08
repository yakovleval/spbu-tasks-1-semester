#pragma once

typedef struct Node
{
    struct Node* leftChild;
    struct Node* rightChild;
    struct Node* parent;
    int key;
    char* value;
} Node;

Node* createTree();
void freeTree(Node** root);
Node** find(Node** root, const int key);
void add(Node** root, const int key, const char* value);
void del(Node** root, const int key);
