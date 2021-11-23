#pragma once
#include <stdio.h>

int** initMatrix(FILE* in, const int size);
void freeMatrix(int** matrix, const int size);
void warshall(int** matrix, const int size);