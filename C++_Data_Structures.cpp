// C++_Data_Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
#include "LinkedList.h"
#include <iostream>
#include "Recursion.h"
#include <ctime>
#include "ArrayADT.h"
int main()
{
	LinkedList<int> list;

	for (size_t i = 0; i < 2; i++)
	{
		list.Add(i);
	}
	list.ReverseRecursive();
	list.Display();
	list.~LinkedList();
	_CrtDumpMemoryLeaks();
}

