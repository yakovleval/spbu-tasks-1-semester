#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

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
    int *pLeftIndex, int *pRightIndex, const int pivot)
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
void quickSort(int *array, const int leftBound, const int rightBound)
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

// checks is segment [leftBound, rightBound] of array sorted
bool isSorted(const int *array, const size_t leftBound, const size_t rightBound)
{
    for (size_t i = leftBound; i < rightBound; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool testQuickSort(int *array, const size_t size)
{
    quickSort(array, 0, size - 1);
    return isSorted(array, 0, size - 1);
}

int* generateRandomArray(const size_t size)
{
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < size; i++)
    {
        array[i] = rand();
    }
    return array;
}

bool testRandomArrays()
{
    const int testArraysNumber = 10;
    const int arraysSize = 50;
    int* testArrays[10] = {NULL};
    for (int i = 0; i < testArraysNumber; i++)
    {
        testArrays[i] = generateRandomArray(arraysSize);
    }

    bool result = true;
    for (size_t i = 0; i < testArraysNumber; i++)
    {
        result &= testQuickSort(testArrays[i], arraysSize);
    }
    for (int i = 0; i < testArraysNumber; i++)
    {
        free(testArrays[i]);
    }
    return result;
}

bool testSmallArrays()
{

    int testArray1[2] = {2, 1};
    int testArray2[2] = {1, 2};
    int testArray3[10] = {10, 9, 7, 8, 5, 4, 6, 3, 2, 1};
    int testArray4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return testQuickSort(testArray1, 2) &&
        testQuickSort(testArray2, 2) &&
        testQuickSort(testArray3, 10) &&
        testQuickSort(testArray4, 10);
}

bool isPassed()
{
    return testRandomArrays() &&
        testSmallArrays();
}

void main()
{
    srand(239);
    setlocale(LC_ALL, "Russian");
    if (!isPassed())
    {
        printf("Тесты не пройдены\n");
        return;
    }
    printf("Тесты пройдены\n"); 
}