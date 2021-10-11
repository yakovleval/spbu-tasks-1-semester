#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "qsort.h"


void main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("input.txt", "r");
	if (file == NULL)
	{
		printf("ошибка открытия файла\n");
		return;
	}
	int size = 0;
	fscanf(file, "%d", &size);
	int* array = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		fscanf(file, "%d", &array[i]);
	}
	quickSort(array, 0, size - 1);
	printf("отсортированный массив:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	free(array);
	fclose(file);
}
