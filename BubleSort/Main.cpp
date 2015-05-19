#include "DynArray.h"

int main(int argv, char** argc)
{

	DynArray<int> ToFlip;

	ToFlip.PushBack(1);
	ToFlip.PushBack(2);
	ToFlip.PushBack(3);
	ToFlip.PushBack(4);
	ToFlip.PushBack(5);
	ToFlip.PushBack(6);
	ToFlip.PushBack(7);

	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n\n", ToFlip.data[0], ToFlip.data[1], ToFlip.data[2], ToFlip.data[3], ToFlip.data[4], ToFlip.data[5], ToFlip.data[6]);

	ToFlip.Flip();

	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", ToFlip.data[0], ToFlip.data[1], ToFlip.data[2], ToFlip.data[3], ToFlip.data[4], ToFlip.data[5], ToFlip.data[6]);

	getchar();

	return 0;
}