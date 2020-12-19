// C++_Data_Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "LinkedList.h"
#include <iostream>
#include "Recursion.h"
#include <ctime>
#include "ArrayADT.h"
#include "StackUsingArray.h"
int main()
{
	{
		StackUsingArray<int> stack;

		for (size_t i = 0; i < 10; i++)
		{
			stack.Push(i);
		}
		stack.Display();

		std::cout << stack.IsFull();
	}

	_CrtDumpMemoryLeaks();
}

