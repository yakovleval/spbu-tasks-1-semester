#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

bool isPassed()
{
	return true;
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

	Node* root = createTree();
	const int bufSize = 101;
	printf("0 -- выйти из программы\n");
	printf("1 -- добавить новую запись\n");
	printf("2 -- найти запись по ключу\n");
	printf("3 -- проверить наличие записи\n");
	printf("4 -- удалить запись\n");
	int key = 0;
	char buffer[101] = {0};
	while (true)
	{
		printf("Введите номер действия: \n");
		int action = 0;
		scanf(" %d", &action);
		switch (action)
		{
		case 0:
			freeTree(&root);
			return;
		case 1:
			printf("введите ключ и значение: \n");
			scanf("%d", &key);
			scanf("%s", &buffer);
			add(&root, key, buffer);
			break;
		case 2:
			printf("введите ключ: \n");
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
			printf("введите ключ: \n");
			scanf("%d", &key);
			if (*find(&root, key) == NULL)
			{
				printf("Записи с таким ключом нет\n");
			}
			else
			{
				printf("Запись с таким ключом есть\n");
			}
			break;
		case 4:
			printf("введите ключ: \n");
			scanf("%d", &key);
			del(&root, key);
			break;
		default:
			printf("некорректный ввод\n");
			break;
		}
	}
}
