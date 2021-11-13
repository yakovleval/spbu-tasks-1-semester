#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Node* buildTree(FILE* in)
{
    Node* tree = NULL;
    while (true)
    {
        char currCh = fgetc(in);
        switch (currCh)
        {
        case ' ':
            continue;
        case '(':
            tree = calloc(1, sizeof(Node));
            break;
        case '+': case '-': case '*': case  '/':
            if (tree == NULL)
            {
                return NULL;
            }
            tree->op = currCh;
            tree->isOp = true;
            tree->left = buildTree(in);
            tree->right = buildTree(in);
            break;
        case ')':
            return tree;
        default: //if number
            ungetc(currCh, in);
            tree = calloc(1, sizeof(Node));
            if (tree == NULL)
            {
                return NULL;
            }
            tree->isOp = false;
            int number = 0;
            fscanf(in, "%d", &number);
            tree->value = number;
            return tree;
            break;
        }
    }
}

void printTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (!root->isOp)
    {
        printf("%d ", root->value);
    }
    else
    {
        printf("( %c ", root->op);
        printTree(root->left);
        printTree(root->right);
        printf(") ");
    }
}

int evaluateTree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (!root->isOp)
    {
        return root->value;
    }
    int left = evaluateTree(root->left);
    int right = evaluateTree(root->right);
    switch (root->op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    default:
        return 0;
    }
}

void freeTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->isOp)
    {
        freeTree(root->left);
        freeTree(root->right);
    }
    free(root);
}
