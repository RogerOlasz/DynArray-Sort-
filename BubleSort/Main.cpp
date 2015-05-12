#include "DynArray.h"
#include <time.h>
#include <random>

int main(int argv, char** argc)
{
	srand(100);

	DynArray<int> ToSort;

	unsigned int count = 0;
	unsigned int count_op = 0;

	for (unsigned int i = 0; i <= 100; i++)
	{
		ToSort.PushBack(rand());
	}

	count = ToSort.BubbleSort();
	count_op = ToSort.BubbleSortOptimized();

	printf("%d\n%d", count, count_op);

	getchar();

	return 0;
}