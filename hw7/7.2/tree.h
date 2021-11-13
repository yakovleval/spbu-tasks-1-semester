#pragma once

typedef struct Node
{
    struct Node* left;
    struct Node* right;
    bool isOp;
    int value;
    char op;
} Node;

Node* buildTree(FILE* in);
void printTree(Node* root);
int evaluateTree(Node* root);
void freeTree(Node* root);
