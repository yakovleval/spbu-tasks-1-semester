#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// [leftBorder..rightBorder]
void reverseSegment(int* array, int leftBorder, int rightBorder) 
{
    while (leftBorder < rightBorder)
    {
        int temp = array[leftBorder];
        array[leftBorder] = array[rightBorder];
        array[rightBorder] = temp;
        leftBorder++;
        rightBorder--;
    }
}

void main()
{
    setlocale(LC_ALL, "Russian");
    printf("введите размер первого отрезка массива: ");
    int firstSize = 0;
    scanf_s("%d", &firstSize);
    printf("введите размер второго отрезка массива : ");
    int secondSize = 0;
    scanf_s("%d", &secondSize);
    printf("введите массив: ");
    int arraySize = firstSize + secondSize;
    int* array = (int*)calloc(arraySize, sizeof(int));
    for (int index = 0; index < arraySize; index++)
    {
        scanf_s("%d", &array[index]);
    }
    reverseSegment(array, 0, firstSize - 1);
    reverseSegment(array, firstSize, arraySize - 1);
    reverseSegment(array, 0, arraySize - 1);
    printf("результат перестановки: ");
    for (int index = 0; index < arraySize; index++)
    {
        printf("%d ", array[index]);
    }
    free(array);
}