#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>

int mostFrequent(const int* array, const int size)
{
	int min = array[0];
	int max = array[0];
	for (int i = 0; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	const int freqArraySize = max - min + 1;
	int* frequencies = (int*)calloc(freqArraySize, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		frequencies[array[i] - min]++;
	}
	int answer = min;
	int maxFrequency = frequencies[0];
	for (int i = 0; i < freqArraySize; i++)
	{
		if (frequencies[i] > maxFrequency)
		{
			answer = i + min;
			maxFrequency = frequencies[i];
		}
	}
	free(frequencies);
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

bool isPassed()
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