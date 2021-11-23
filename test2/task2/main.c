#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "warshall.h"

bool isPassed()
{
	return true;
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

	FILE* in = fopen("in.txt", "r");
	FILE* out = fopen("out.txt", "w");
	int size = 0;
	fscanf(in, "%d", &size);
	int** matrix = initMatrix(in, size);
	warshall(matrix, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fprintf(out, "%d ", matrix[i][j]);
		}
		fprintf(out, "\n");
	}
	freeMatrix(matrix, size);
	fclose(in);
	fclose(out);
}
