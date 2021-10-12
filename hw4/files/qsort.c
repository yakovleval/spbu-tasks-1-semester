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
