#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


void choiseSort(int* array, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				const int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

bool isSorted(const int* array, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool isPassed()
{
	const int testArraysNumber = 3;
	const int testArraysSize = 5;
	const int testArrays[3][5] = 
	{
		{0, 0, 0, 0, 0}, 
		{5, 4, 2, 2, 1}, 
		{1, 1, 2, 2, 3}
	};
	bool result = true;
	for (int i = 0; i < testArraysNumber; i++)
	{
		choiseSort(testArrays[i], testArraysSize);
		result &= isSorted(testArrays[i], testArraysSize);
	}
	return result;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	if (!isPassed())
	{
		printf("тесты не пройдены\n");
		return;
	}
	printf("тесты пройдены\n");
	const int arraySize = 10;
	int array[10] = {0};
	printf("¬ведите %d элементов массива: ", arraySize);
	for (int i = 0; i < arraySize; i++)
	{
		scanf_s("%d", &array[i]);
	}
	choiseSort(array, arraySize);
	printf("отсортированный массив: \n");
	for (int i = 0; i < arraySize; i++)
	{
		printf("%d ", array[i]);
	}
}