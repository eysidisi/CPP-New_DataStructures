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
		tree.InsertRecursive(10);
		tree.InsertRecursive(7);
		tree.InsertRecursive(6);
		tree.InsertRecursive(17);
		tree.InsertRecursive(13);
		tree.InsertRecursive(15);
		tree.InsertRecursive(14);
		tree.InsertRecursive(19);
		tree.DeleteElement(10);
		tree.DisplayInOrderIterative();
	}

	_CrtDumpMemoryLeaks();
}


