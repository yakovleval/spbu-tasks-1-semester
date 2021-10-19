#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#pragma warning(disable : 4996) 

void main()
{
	FILE* f = fopen("f.txt", "r");
	FILE* g = fopen("g.txt", "r");
	FILE* h = fopen("h.txt", "w");
	int bound = 0;
	fscanf(g, "%d", &bound);
	int current = 0;
	while (fscanf(f, "%d", &current) > 0)
	{
		if (current < bound)
		{
			fprintf(h, "%d ", current);
		}
	}
	fclose(f);
	fclose(g);
	fclose(h);
}
