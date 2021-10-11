#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void add(int *dest, const int *source, const int buffersSize)
{
	for (int i = 0; i < buffersSize - 1; i++)
	{
		dest[i] += source[i];
		dest[i + 1] += dest[i] / 2;
		dest[i] %= 2;
	}
	dest[buffersSize - 1] += source[buffersSize - 1];
	dest[buffersSize - 1] %= 2;
}

void decimalToBinary(int *binary, const int size, int decimal)
{
	for (int i = 0; i < size; i++)
	{
		binary[i] = decimal & 1;
		decimal >>= 1;
	}
}

int binaryToDecimal(const int *binary, const int size)
{
	int decimal = 0;
	for (int i = 0; i < size; i++)
	{
		decimal += (1 << i) * binary[i];
	}
	return decimal;
}

printBinary(const int *binary, const int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", binary[i]);
	}
	printf("\n");
}

bool isPassed()
{
	srand(239);
	const int buffersSize = 32;
	const int testsNumber = 7;
	int decimal1[7] = {0, 1, 10, 10, -239, 2147483647, -2147483647 - 1};
	int decimal2[7] = {0, -1, 15, -15, 239, -2147483647 - 1, 1};
	int* binary1 = (int*)calloc(buffersSize, sizeof(int));
	int* binary2 = (int*)calloc(buffersSize, sizeof(int));
	bool result = true;
	for (int i = 0; i < testsNumber; i++)
	{
		decimalToBinary(binary1, buffersSize, decimal1[i]);
		decimalToBinary(binary2, buffersSize, decimal2[i]);
		add(binary1, binary2, buffersSize);
		result &= (decimal1[i] + decimal2[i]) == binaryToDecimal(binary1, buffersSize);
	}
	free(binary1);
	free(binary2);
	return result;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	if (!isPassed())
	{
		printf("тесты не пройдеы\n");
		return;
	}
	printf("тесты пройдеы\n");
	const int buffersSize = 32;
	printf("¬ведите 2 целых числа:\n");
	int decimal1 = 0;
	int decimal2 = 0;
	scanf_s("%d %d", &decimal1, &decimal2);

	int* binary1 = (int*)calloc(buffersSize, sizeof(int));
	int* binary2 = (int*)calloc(buffersSize, sizeof(int));
	decimalToBinary(binary1, buffersSize, decimal1);
	decimalToBinary(binary2, buffersSize, decimal2);

	printf("двоичное представление первого числа (формат little-endian):\n");
	printBinary(binary1, buffersSize);
	printf("двоичное представление второго числа (формат little-endian):\n");
	printBinary(binary2, buffersSize);
	add(binary1, binary2, buffersSize);
	printf("двоичное представление суммы (формат little-endian):\n");
	printBinary(binary1, buffersSize);
	printf("дес€тичное представление суммы: %d\n", binaryToDecimal(binary1, buffersSize));

	free(binary1);
	free(binary2);
}