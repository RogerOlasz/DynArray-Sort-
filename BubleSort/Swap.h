#ifndef __Swap_H__
#define __Swap_H__

template<class TYPE_VAR>

void Swap(TYPE_VAR& a, TYPE_VAR& b)
{
	TYPE_VAR tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#endif __Swap_H__

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../BubleSort/DynArray.h"

//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace UnitTestBubbleSort
//{
//	TEST_CLASS(UnitTest1)
//	{
//	public:
//
//		TEST_METHOD(SortTest)
//		{
//			DynArray<int> ToSort;
//
//			ToSort.PushBack(5);
//			ToSort.PushBack(2);
//			ToSort.PushBack(8);
//			ToSort.PushBack(9);
//			ToSort.PushBack(3);
//
//			ToSort.BubbleSort();
//
//			Assert::IsTrue(ToSort.data[0] < ToSort.data[1]);
//			Assert::IsTrue(ToSort.data[1] < ToSort.data[2]);
//			Assert::IsTrue(ToSort.data[2] < ToSort.data[3]);
//			Assert::IsTrue(ToSort.data[3] < ToSort.data[4]);
//		}
//
//	};
//}