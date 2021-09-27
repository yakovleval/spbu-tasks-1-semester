#include <locale.h>
#include <stdio.h>
#include <stdbool.h>

double powerLinear(const int base, const int power)
{
    if (base == 0)
    {
        return 0;
    }
    if (power == 0)
    {
        return 1;
    }
    long long result = 1;
    int absPower = abs(power);
    while (absPower > 0)
    {
        result *= base;
        absPower--;
    }
    return power > 0 ? result : (1.0 / result);
}

double powerLogarithmic(const int base, const int power)
{
    if (base == 0)
    {
        return 0;
    }
    if (power == 0)
    {
        return 1;
    }
    int absPower = abs(power);
    if (absPower % 2 == 1)
    {
        const double result  = powerLogarithmic(base, absPower - 1) * base;
        return power > 0 ? result : (1.0 / result);
    }
    else
    {
        double result = powerLogarithmic(base, absPower / 2);
        result *= result;
        return power > 0 ? result : (1.0 / result);
    }
}

bool testPower(const int base, const int power, const double answer)
{
    return powerLinear(base, power) == answer &&
        powerLogarithmic(base, power) == answer;
}

bool isPassed()
{
    return
        testPower(0, 1, 0) &&
        testPower(1, 0, 1) &&
        testPower(1, 1, 1) &&
        testPower(2, 10, 1024) &&
        testPower(-1, 0, 1) &&
        testPower(-2, 10, 1024) &&
        testPower(1, -1, 1) &&
        testPower(2, -10, 1.0 / 1024) &&
        testPower(-2, -10, 1.0 / 1024);
}

void main()
{
    setlocale(LC_ALL, "Russian");
    if (!isPassed())
    {
        printf("тесты не пройдены\n");
        return;
    }
    printf("тесты пройдены\n");
}