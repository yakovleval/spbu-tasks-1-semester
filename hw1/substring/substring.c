#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<assert.h>

void main()
{
    setlocale(LC_ALL, "Russian");
    // ввод строк
    printf("¬ведите длину строки: ");
    int lenString = 0;
    scanf_s("%d", &lenString);
    printf("¬ведите строку: ");
    char* string = (char*)calloc(lenString + 1, sizeof(char));
    scanf_s("%s", string, lenString + 1);
    printf("¬ведите длину подстроки: ");
    int lenSubString = 0;
    scanf_s("%d", &lenSubString);
    printf("¬ведите подстроку: ");
    char *subString = (char*)calloc(lenSubString + 1, sizeof(char));
    scanf_s("%s", subString, lenSubString + 1);
    //вычисление префикс-функции
    int lenConcatString = lenString + lenSubString + 2;
    char* concatString = (char*)calloc(lenConcatString, sizeof(char));
    memcpy_s(concatString, lenSubString + 1, subString, lenSubString + 1);
    memcpy_s(concatString + lenSubString + 1, lenString + 1, string, lenString + 1);
    int* prefixFunc = (int*)calloc(lenConcatString, sizeof(int));
    assert(prefixFunc);
    for (int index = 1; index < lenConcatString; index++)
    {
        int maxBorder = prefixFunc[index - 1];
        while (maxBorder > 0 && concatString[index] != concatString[maxBorder])
        {
            maxBorder = prefixFunc[maxBorder - 1];
        }
        if (concatString[index] == concatString[maxBorder])
        {
            maxBorder++;
        }
        prefixFunc[index] = maxBorder;
    }
    // вычисление ответа
    int subStringCount = 0;
    for (int index = 0; index < lenConcatString; index++)
    {
        if (prefixFunc[index] == lenSubString)
        {
            subStringCount++;
        }
    }
    printf("количество вхождений подстроки в строку равно %d", subStringCount);
    
    free(string);
    free(subString);
    free(concatString);
    free(prefixFunc);
}