#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// сортирует отрезок [leftBound, rightBound] массива array
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

// раздел€ет по опорному элементу отрезок [leftBound, rightBound] массива array
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

// сортирует отрезок [leftBound, rightBound] массива array
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
    quickSort(array, leftBound, rightPartIndex);
    quickSort(array, leftPartIndex, rightBound);
}

bool binSearch(const int* array, const size_t size, const int key)
{
    // инвариант: leftBound <= key, rightBound > key
    int leftBound = 0;
    int rightBound = size;
    while (rightBound - leftBound > 1)
    {
        int middle = (leftBound + rightBound) / 2;
        if (array[middle] <= key)
        {
            leftBound = middle;
        }
        else
        {
            rightBound = middle;
        }
    }
    return array[leftBound] == key;
}

void generateRandomArray(int *array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}

bool doesExist(const int* array, const int size, const int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return true;
        }
    }
    return false;
}

testBinSearch(const int* array, const int size, const int key)
{
    return doesExist(array, size, key) == binSearch(array, size, key);
}

bool isPassed()
{
    const int testArraySize = 50;
    int testArray[50] = {0};
    int testKeys[50] = {0};
    generateRandomArray(testArray, testArraySize);
    generateRandomArray(testKeys, testArraySize);
    for (int i = 0; i < testArraySize; i += 2)
    {
        testKeys[i] *= -1;
    }

    bool result = true;
    for (size_t i = 0; i < testArraySize; i++)
    {
        result &= testBinSearch(testArray, testArraySize, testKeys[i]);
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

    int n = 0;
    int k = 0;
    printf("¬ведите числа n и k:\n");
    scanf_s("%d%d", &n, &k);
    while (n < 0 || k < 0)
    {
        printf("¬ведите корректные числа (n и k должны быть неотрицательны):\n");
        scanf_s("%d%d", &n, &k);
    }
    int *randomArray = (int*)calloc(n, sizeof(int));
    int *keys = (int*)calloc(k, sizeof(int));
    generateRandomArray(randomArray, n);
    generateRandomArray(keys, k);
    
    quickSort(randomArray, 0, n - 1);
    for (int i = 0; i < k; i++)
    {
        const bool doesExist = binSearch(randomArray, k, keys[i]);
        printf("%d: %s\n", keys[i], doesExist ? "есть в массиве" : "нет в массиве");
    }

    free(randomArray);
    free(keys);
}