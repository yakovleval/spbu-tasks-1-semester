#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// sorts segment [leftBound, rightBound] in array
void insertionSort(int* array, const size_t leftBound, const size_t rightBound)
{
	for (size_t i = leftBound + 1; i <= rightBound; i++)
	{
		for (size_t j = i - 1; j >= 0 && array[j] > array[j + 1]; j--)
		{
			const int tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;
		}
	}
}

// parts segment [leftBound, rightBound] of array
void partition(int* array, const int leftBound, const int rightBound,
	int* pLeftIndex, int* pRightIndex, const int pivot)
{
	int leftIndex = leftBound;
	int rightIndex = rightBound;
	while (leftIndex <= rightIndex)
	{
		while (leftIndex <= rightBound && array[leftIndex] < pivot)
		{
			leftIndex++;
		}
		while (rightIndex >= leftBound && array[rightIndex] >= pivot)
		{
			rightIndex--;
		}
		if (leftIndex <= rightIndex)
		{
			const int tmp = array[leftIndex];
			array[leftIndex] = array[rightIndex];
			array[rightIndex] = tmp;
			leftIndex++;
			rightIndex--;
		}
	}
	*pLeftIndex = leftIndex;
	*pRightIndex = rightIndex;
}

// sorts segment [leftBound, rightBound] in array
void quickSort(int* array, const int leftBound, const int rightBound)
{
	const int blockSize = rightBound - leftBound + 1;
	if (blockSize <= 0)
	{
		return;
	}
	if (blockSize < 10)
	{
		insertionSort(array, leftBound, rightBound);
		return;
	}

	// chooses pivot 
	int pivot = array[0];
	for (int i = leftBound; i <= rightBound; i++)
	{
		if (array[i] != array[i + 1])
		{
			pivot = array[i] > array[i + 1] ? array[i] : array[i + 1];
			break;
		}
		return;
	}

	int leftPartIndex = 0;
	int rightPartIndex = 0;
	partition(array, leftBound, rightBound, &leftPartIndex, &rightPartIndex, pivot);
	quickSort(array, leftBound, rightPartIndex);
	quickSort(array, leftPartIndex, rightBound);
}

int mostFrequent(const int* array, const int size)
{
	quickSort(array, 0, size - 1);
	int answer = array[0];
	int maxCount = 1;
	int count = 1;
	for (int i = 1; i < size; i++)
	{
		if (array[i] == answer)
		{
			count++;
		}
		else
		{
			if (count > maxCount)
			{
				maxCount = count;
				answer = array[i - 1];
				count = 1;
			}
		}
	}
	if (count > maxCount)
	{
		maxCount = count;
		answer = array[size - 1];
		count = 1;
	}
	return answer;
}

bool checkMostFrequent(const int* array, const int size, const int element)
{
	int maxFrequency = 0;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (array[j] == array[i])
			{
				count++;
			}
		}
		if (count > maxFrequency)
		{
			maxFrequency = count;
		}
	}
	int countElement = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == element)
		{
			countElement++;
		}
	}
	return countElement == maxFrequency;
}

void generateRandomArray(int* array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
}

bool testMostFrequent(const int* array, const int size)
{
	return checkMostFrequent(array, size, mostFrequent(array, size));
}

bool testRandomArrays()
{
	const int testArraysNumber = 10;
	const int arraysSize = 50;
	int* testArrays[10] = {NULL};
	for (int i = 0; i < testArraysNumber; i++)
	{
		testArrays[i] = (int*)calloc(arraysSize, sizeof(int));
		generateRandomArray(testArrays[i], arraysSize);
	}
	bool result = true;
	for (int i = 0; i < testArraysNumber; i++)
	{
		result &= testMostFrequent(testArrays[i], arraysSize);
	}

	for (int i = 0; i < testArraysNumber; i++)
	{
		free(testArrays[i]);
	}
	return result;
}

bool testOneElement()
{
	const int arraySize = 1;
	const int testArray[1] = {239};
	return testMostFrequent(testArray, arraySize);
}

bool testAllEqual()
{
	const int arraySize = 5;
	const int testArray[5] = {2, 2, 2, 2, 2};
	return testMostFrequent(testArray, arraySize);
}

bool isPassed()
{
	return testRandomArrays() &&
		testOneElement() &&
		testAllEqual();
}

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(239);
	if (!isPassed())
	{
		printf("тесты не пройдены\n");
		return;
	}
	printf("тесты пройдены\n");
}