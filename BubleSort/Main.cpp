#include "DynArray.h"
#include <time.h>
#include <random>

int main(int argv, char** argc)
{
	srand(100);

	DynArray<int> ToSort;

	unsigned int count = 0;
	unsigned int count_coct = 0;
	unsigned int count_comb = 0;

	for (unsigned int i = 0; i <= 10000; i++)
	{
		ToSort.PushBack(rand());
	}

	count = ToSort.BubbleSort();
	count_coct = ToSort.Cocktail();
	count_comb = ToSort.CombSort();

	printf("%d\n%d\n%d", count, count_coct, count_comb);

	getchar();

	return 0;
}