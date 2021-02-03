// C++_Data_Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "LinkedList.h"
#include <iostream>
#include "Recursion.h"
#include <ctime>
#include "ArrayADT.h"
#include "StackUsingArray.h"
#include "Queue.h"
#include "C++_Data_Structures.h"
#include "BinarySearchTree.h"

int main()
{
	{
		BinarySearchTree<int> tree;
		tree.InsertIterative(0);
		tree.InsertIterative(1);
		tree.InsertIterative(-3);
		tree.InsertIterative(5);
		std::cout << tree.SearchForElement(-9);
		
	}

	_CrtDumpMemoryLeaks();
}


