#pragma once

typedef struct Node Node;

// просто возвращает NULL
Node* createTree();
// очищает память выделенную под дерево
void freeTree(Node* root);
// поиск вершины по ключу, возвращает NULL если ключа нет
Node** findNode(Node* root, const int key);
// поиск значения по ключу, возвращает NULL если ключа нет
char* findValue(Node* root, const int key);
// добавляет ключ в дерево, меняет значение существующего
// если ключ уже есть
void addNode(Node** root, const int key, const char* value);
// удаляет ключ из дерева, ничего не делает если ключа нет
void deleteNode(Node** root, const int key);
