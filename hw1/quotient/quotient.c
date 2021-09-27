#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void main()
{
    setlocale(LC_ALL, "Russian");

    printf("¬ведите числа a и b: ");
    int dividend = 0;
    int divisor = 0;
    scanf_s("%d %d", &dividend, &divisor);
    while (divisor == 0)
    {
        printf("¬ведите корректные числа (b не может быть равно 0): ");
        scanf_s("%d %d", &dividend, &divisor);
    }
    int quotient = 0;
    int absDividend = abs(dividend);
    int absDivisor = abs(divisor);
    while (absDividend - quotient * absDivisor >= absDivisor)
    {
        quotient++;
    }
    if (dividend < 0)
    {
        quotient++;
    }
    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
    {
        quotient = -quotient;
    }
    printf("неполное частное равно %d", quotient);
}