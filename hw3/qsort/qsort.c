#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
#include<stdlib.h>

// [leftBound, rightBound]
void insertionSort(int* array, const size_t leftBound, const size_t rightBound)
{
    for (size_t i = leftBound + 1; i <= rightBound; i++)
    {
        for (size_t j = i - 1; j >= 0 && array[j] > array[j+1]; j--)
        {
            const int tmp = array[j];
            array[j] = array[j+1];
            array[j+1] = tmp;
        }
    }
}

// [leftBound, rightBound]
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

// [leftBound, rightBound]
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

    // выбор опорного элемента
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
    quickSort(array, leftBound, rightPartIndex); //leftPartIndex > rightPartIndex
    quickSort(array, leftPartIndex, rightBound); //leftPartIndex > rightPartIndex
}

// [leftBound, rightBound]
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

bool isPassed()
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