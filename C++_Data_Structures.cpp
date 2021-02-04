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
		tree.InsertRecursive(0);
		tree.InsertRecursive(1);
		tree.InsertRecursive(-3);
		tree.InsertRecursive(5);
		tree.DisplayInOrderIterative();

	}

	_CrtDumpMemoryLeaks();
}


