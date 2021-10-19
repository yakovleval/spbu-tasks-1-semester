#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

bool isPalindrome(const char* string)
{
	const int size = strlen(string);
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		if (string[left] == ' ' || string[right] == ' ')
		{
			string[left] == ' ' ? left++ : right--;
			continue;
		}
		if (string[left] != string[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}

bool isPassed()
{
	const int stringsNumber = 6;
	const char* strings[6] =
	{
		"a",
		"aaa",
		"    a  a    a ",
		"я иду с мечем судия",
		"   a  b ",
		"123456"
	};
	const bool answers[6] =
	{
		true,
		true,
		true,
		true,
		false,
		false
	};
	bool result = true;
	for (int i = 0; i < stringsNumber; i++)
	{
		result &= isPalindrome(strings[i]) == answers[i];
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
}
