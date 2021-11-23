#include "warshall.h"
#include <stdlib.h>
#include <stdio.h>

int** initMatrix(FILE* in, const int size)
{
	int** matrix = NULL;
	matrix = calloc(size, sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		matrix[i] = calloc(size, sizeof(int));
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fscanf(in, "%d", &matrix[i][j]);
		}
	}
	return matrix;
}

void freeMatrix(int** matrix, const int size)
{
	for (int i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void warshall(int** matrix, const int size)
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = matrix[i][j] ||
					(matrix[i][k] && matrix[k][j]);
			}
		}
	}
}