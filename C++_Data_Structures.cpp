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
#include "BinaryTree.h"


int main()
{
	{
		BinaryTree<int> tree;
		for (int i = 1; i < 18; i++)
		{
			tree.Insert(i);
		}

		tree.DisplayPostOrder();
		std::cout << std::endl;
		tree.IterativeDisplayPostOrder();
		std::cout << std::endl;
	}

	_CrtDumpMemoryLeaks();
}


