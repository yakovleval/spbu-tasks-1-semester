#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "Russian");
    printf("введите число, до которого нужно вывести все простые: ");
    int border = 0;
    scanf_s("%d", &border);
    int* sieve = (int*)calloc(border + 1, sizeof(int));
    int divisor = 2;
    while (divisor * divisor <= border)
    {
        for (int number = divisor * divisor; number <= border; number += divisor)
        {
            sieve[number] = 1;
        }
        divisor++;
        while (sieve[divisor] != 0)
        {
            divisor++;
        }
    }
    printf("список простых чисел, не превосходящих %d: ", border);
    for (int number = 2; number <= border; number++)
    {
        if (sieve[number] == 0)
        {
            printf("%d ", number);
        }
    }
    free(sieve);
}