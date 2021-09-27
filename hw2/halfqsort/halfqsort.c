#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void partition(int* array, const size_t size, const int pivot)
{
    int leftIndex = 0;
    int rightIndex = size - 1;
    while (leftIndex <= rightIndex)
    {
        while (leftIndex < size && array[leftIndex] < pivot)
        {
            leftIndex++;
        }
        while (rightIndex >= 0 && array[rightIndex] >= pivot)
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
}

bool isParted(const int* array, const size_t size, const int pivot)
{
    size_t index = 0;
    while (array[index] < pivot)
    {
        index++;
    }
    while (index < size && array[index] >= pivot)
    {
        index++;
    }
    return index == size;
}

bool testPartition(const int* array, const size_t size, const int pivot)
{
    int* testArray = (int*)calloc(size, sizeof(int));
    if (testArray == NULL)
    {
        free(testArray);
        return;
    }
    memcpy(testArray, array, size * sizeof(int));
    partition(testArray, size, pivot);
    const bool result = isParted(testArray, size, pivot);
    free(testArray);
    return result;
}

bool isPassed()
{
    const size_t testArraysNumber = 5;
    const size_t testArraysSize = 5;
    const int **testArrays[6][5] =
    {
        {5, 4, 3, 2, 1},
        {5, 3, 3, 3, 1},
        {3, 3, 3, 3, 3},
        {5, 4, 3, 2, 1},
        {5, 4, 3, 2, 1},
        {2, 1, 3, 5, 4}
    };
    const int *pivots[6] = {3, 3, 3, 5, 1, 3};
    bool result = true;
    for (size_t i = 0; i < testArraysNumber; i++)
    {
        result &= testPartition(testArrays[i], testArraysSize, pivots[i]);
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
    printf("введите размер массива: \n");
    size_t size = 0;
    scanf_s("%d", &size);
    int* array = (int*)calloc(size, sizeof(int));
    srand(239);
    printf("исходный массив случайных чисел: \n");
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
        printf("%d ", array[i]);
    }
    printf("\n");
    const int pivot = array[0];
    partition(array, size, pivot);
    printf("массив после partition с опорным элементом %d: \n", pivot);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
}