#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

void combSort(int* array, const int size)
{
	const int factor = 2;
	for (int distance = size - 1; distance > 0; distance /= factor)
	{
		for (int i = 0; i + distance < size; i++)
		{
			if (array[i] > array[i + distance])
			{
				const int tmp = array[i];
				array[i] = array[i + distance];
				array[i + distance] = tmp;
			}
		}
	}
}

bool isEqual(const int* array1, const int* array2, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array1[i] != array2[i])
		{
			return false;
		}
	}
	return true;
}

bool isPassed()
{
	const int arraysNumber = 6;
	const int arraysSize = 4;
	int arrays[6][4] =
	{
		{0, 1, 2, 3},
		{3, 2, 1, 0},
		{0, 2, 2, 3},
		{2, 3, 2, 0},
		{3, 2, 2, 0},
		{0, 0, 0, 0}
	};
	const int answers[6][4] =
	{
		{0, 1, 2, 3},
		{0, 1, 2, 3},
		{0, 2, 2, 3},
		{0, 2, 2, 3},
		{0, 2, 2, 3},
		{0, 0, 0, 0}
	};
	bool result = true;
	for (int i = 0; i < arraysNumber; i++)
	{
		combSort(arrays[i], arraysSize);
		result &= isEqual(arrays[i], answers[i], arraysSize);
	}
	return result;
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
	printf("Введите количество элементов массива:\n");
	int size = 0;
	scanf_s("%d", &size);
	int* array = calloc(size, sizeof(int));
	printf("Введите элементы массива:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &array[i]);
	}
	combSort(array, size);
	printf("Отсортированный массив:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	free(array);
}
