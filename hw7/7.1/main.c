#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

bool testAddandFind()
{
	Node* root = createTree();
	add(&root, 555, "string1");
	add(&root, 666, "string 2");
	const bool result = *find(&root, 555) != NULL &&
		*find(&root, 666) != NULL &&
		*find(&root, 0) == NULL;
	freeTree(&root);
	return result;
}

bool testChange()
{
	Node* root = createTree();
	add(&root, 555, "string1");
	add(&root, 666, "string2");
	add(&root, 555, "string");
	const bool result = strcmp((*find(&root, 555))->value, "string") == 0;
	freeTree(&root);
	return result;
}

bool testDel()
{
	Node* root = createTree();
	add(&root, 555, "string1");
	add(&root, 666, "string2");
	add(&root, 555, "string");
	const bool result = strcmp((*find(&root, 555))->value, "string") == 0;
	freeTree(&root);
	return result;
}

bool isPassed()
{
	return testAddandFind() &&
		testChange() &&
		testDel();
}

void main()
{
	setlocale(LC_ALL, "Russian");
	if (!isPassed())
	{
		printf("����� �� ��������\n");
		return;
	}
	printf("����� ��������\n");

	Node* root = createTree();
	const int bufSize = 101;
	printf("0 -- ����� �� ���������\n");
	printf("1 -- �������� ����� ������\n");
	printf("2 -- ����� ������ �� �����\n");
	printf("3 -- ��������� ������� ������\n");
	printf("4 -- ������� ������\n");
	int key = 0;
	char buffer[101] = {0};
	while (true)
	{
		printf("������� ����� ��������: \n");
		int action = 0;
		scanf(" %d", &action);
		switch (action)
		{
		case 0:
			freeTree(&root);
			return;
		case 1:
			printf("������� ���� � ��������: \n");
			scanf("%d", &key);
			scanf("%s", &buffer);
			add(&root, key, buffer);
			break;
		case 2:
			printf("������� ����: \n");
			scanf("%d", &key);
			Node** node = find(&root, key);
			if (*node == NULL)
			{
				printf("NULL\n");
			}
			else
			{
				printf("%s\n", (*node)->value);
			}
			break;
		case 3:
			printf("������� ����: \n");
			scanf("%d", &key);
			if (*find(&root, key) == NULL)
			{
				printf("������ � ����� ������ ���\n");
			}
			else
			{
				printf("������ � ����� ������ ����\n");
			}
			break;
		case 4:
			printf("������� ����: \n");
			scanf("%d", &key);
			del(&root, key);
			break;
		default:
			printf("������������ ����\n");
			break;
		}
	}
}