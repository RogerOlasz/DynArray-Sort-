#include "stdafx.h"
#include "CppUnitTest.h"

#include "../BubleSort/DynArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBubbleSort
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(SortTest)
		{
			DynArray<int> ToSort;

			ToSort.PushBack(5);
			ToSort.PushBack(2);
			ToSort.PushBack(8);
			ToSort.PushBack(9);
			ToSort.PushBack(3);

			ToSort.BubbleSort();

			Assert::IsTrue(ToSort.data[0] < ToSort.data[1]);
			Assert::IsTrue(ToSort.data[1] < ToSort.data[2]);
			Assert::IsTrue(ToSort.data[2] < ToSort.data[3]);
			Assert::IsTrue(ToSort.data[3] < ToSort.data[4]);
		}

	};
}