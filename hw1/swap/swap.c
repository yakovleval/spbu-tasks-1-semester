#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

void main()
{
    setlocale(LC_ALL, "Russian");

    long long x = 0;
    int y = 0;
    printf("¬ведите числа x и y (от %d до %d): ", INT_MIN, INT_MAX);
    scanf_s("%lld %d", &x, &y);
    x += y;
    y = x - y;
    x -= y;
    printf("x = %lld, y = %d", x, y);
}