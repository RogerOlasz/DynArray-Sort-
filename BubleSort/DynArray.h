#ifndef __DynamicArray_H__
#define __DynamicArray_H__

#include <assert.h>
#include "Swap.h"
#include <iostream>

template<class Type>
class DynArray
{
	public:

		Type* data;
		unsigned int allocated_memory;
		unsigned int allocated_items;

		void Reallocate(unsigned int new_memory_size)
				{
					if (data != NULL)
					{
						Type* tmp = new Type[allocated_memory];

						for (unsigned int i = 0; i < allocated_items; i++)
						{
							tmp[i] = data[i];
						}

						delete[] data;
						allocated_memory = new_memory_size;
						data = new Type[allocated_memory];

						for (unsigned int i = 0; i < allocated_items; i++)
						{
							data[i] = tmp[i];
						}
					}
					else
					{
						delete data;
						allocated_memory = new_memory_size;
						data = new Type[allocated_memory];
					}
				}
	public:

		DynArray() :data(NULL), allocated_memory(0), allocated_items(0) {}

		DynArray(unsigned int mem_size) : data(NULL), allocated_items(0) { Reallocate(mem_size); }

		~DynArray(){ if (data != NULL) delete[] data;}

		unsigned int getAllocatedItems() const
		{
			return allocated_items;
		}

		unsigned int getAllocatedMemory() const
		{
			return allocated_memory;
		}

		void PushBack(Type value)
		{
			if (data != NULL)
			{
				if (allocated_memory <= allocated_items)
				{
					Reallocate(allocated_memory + 1);
				}
				data[allocated_items] = value;
				allocated_items++;
			}
			else
			{
				Reallocate(1);
				data[allocated_items] = value;
				allocated_items++;
			}
		}

		Type Pop()
		{
			if (data != NULL)
			{
				if (allocated_items != 0)
				{
					allocated_items--;
					return data[allocated_items];
				}
			}
			return 666; //It's just an ERROR.
		}

		void Clear()
		{
			if (data != NULL)
			{
				allocated_items = 0;
			}
			
		}

		bool Insert(Type value, unsigned int position)
		{
			if (position <= allocated_items)
			{
				Type* tmp = new Type[allocated_memory];

				for (unsigned int i = 0; i < allocated_items; i++)
				{
					tmp[i] = data[i];
				}

				if (allocated_memory <= allocated_items)
				{
					Reallocate(allocated_memory + 1);
				}

				for (unsigned int i = 0; i < position; i++)
				{
					data[i] = tmp[i];
				}

				data[position] = value;	

				for (unsigned int i = position; i == allocated_items ; i++)
				{
					data[i + 1] = tmp[i];
				}

				allocated_items++;
				delete[] tmp;
				return true;
				}
			return false;
		}

		unsigned int BubbleSort()
		{
			unsigned int counter;
			unsigned int counter_cmp = 0;
			do
			{
				counter = 0;

				for (unsigned int i = 0; i < allocated_items - 1; i++)
				{
					counter_cmp++;
					if (data[i] > data[i + 1])
					{
						Swap(data[i], data[i + 1]);
						counter++;
					}
				}
			} while (counter != 0);

		 return counter_cmp;
		}

		unsigned int Cocktail()
		{
			unsigned int counter = 0;
			for (unsigned int i = 0; i < allocated_items - 1; i++)
			{
				for (unsigned int j = i + 1; j < allocated_items; j++)
				{
					counter++;
					if (data[i] > data[j]) 
					{ 
						Swap(data[i], data[j]); 
					}
				}
			}
			return counter;
		}

		unsigned int CombSort()
		{
			bool swapped = true;
			unsigned int sever = allocated_items - 1;
			unsigned int counter = 0;

			while (sever > 1 || swapped == true)
			{
				sever /= 1.3;
				if (sever < 1)
				{
					sever = 1;
				}
					
				swapped = false;

				for (unsigned int i = 0; i + sever < allocated_items; i++)
				{
					counter++;
					if (data[i] > data[i + sever])
					{
						Swap(data[i], data[i + sever]);
						swapped = true;
					}
				}
			}
			return counter;
		}

		int& operator[](unsigned int index)
		{
			assert(index < allocated_items);
			return data[index];
		}
		const int& operator[](unsigned int index) const
		{
			assert(index < allocated_items);
			return data[index];
		}
};

#endif //__DynamicArray_H__