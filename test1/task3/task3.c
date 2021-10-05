#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#pragma warning(disable : 4996)

void main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("file.txt", "r");
	if (file == NULL)
	{
		printf("файл не найден\n");
		return;
	}
	const int bufferSize = 100;
	char buffer[100] = {0};
	while (fgets(buffer, sizeof(buffer), file))
	{
		int index = 0;
		char curChar = '\0';
		while (buffer[index] != '\0')
		{
			if (buffer[index] != curChar)
			{
				printf("%c", curChar);
				curChar = buffer[index];
			}
			index++;
		}
		printf("\n");
	}
	fclose(file);
}