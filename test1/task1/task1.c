#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int digitsSum(int number)
{
	if (number < 0)
	{
		number = -number;
	}
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

int maxDigitsSum(const int* array, const int size)
{
	int maxDigitsSum = 0;
	for (int i = 0; i < size; i++)
	{
		int digitsSumResult = digitsSum(array[i]);
		if (digitsSumResult > maxDigitsSum)
		{
			maxDigitsSum = digitsSumResult;
		}
	}
	return maxDigitsSum;
}

bool isPassed()
{
	const int testArray1Size = 5;
	const int testArray2Size = 1;
	const int testArray1[5] = {0, 1, 239, -1234, -100000};
	const int testArray2[1] = {-12346};
	return maxDigitsSum(testArray1, testArray1Size) == 14 &&
		maxDigitsSum(testArray2, testArray2Size) == 16;
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
	int size = 0;
	printf("¬ведите размер массива:");
	scanf_s("%d", &size);
	int* array = (int*)calloc(size, sizeof(int));
	printf("¬ведите значени€ элементов массива:");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &array[i]);
	}
	int maxDigitsSumResult = maxDigitsSum(array, size);
	printf("элементы с максимальной суммой цифр: \n");
	for (int i = 0; i < size; i++)
	{
		if (digitsSum(array[i]) == maxDigitsSumResult)
		{
			printf("%d ", array[i]);
		}
	}
	free(array);
}