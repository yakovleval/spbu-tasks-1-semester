#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

bool testEmpty()
{
	FILE* in = fopen("testEmpty.txt", "r");
	Node* root = buildTree(in, NULL);
	fclose(in);
	bool result = evaluateTree(root) == 0;
	return result;
}

bool testTrivial()
{
	FILE* in = fopen("testTrivial.txt", "r");
	Node* root = buildTree(in, NULL);
	fclose(in);
	bool result = evaluateTree(root) == 239;
	return result;
}

bool testAverage()
{
	FILE* in = fopen("testAverage.txt", "r");
	Node* root = buildTree(in, NULL);
	fclose(in);
	bool result = evaluateTree(root) == 10;
	return result;
}

bool isPassed()
{
	return testEmpty() &&
		testTrivial() &&
		testAverage();
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
	FILE* in = fopen("file.txt", "r");
	Node* root = buildTree(in, NULL);
	fclose(in);
	printTree(root);
	printf("\n");
	printf("%d", evaluateTree(root));
	freeTree(root);
}
