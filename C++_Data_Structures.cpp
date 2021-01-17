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
using namespace std;

int main()
{
	{
		Queue<int> q;

		for (size_t i = 0; i < 10; i++)
		{
			q.Enqueue(i);
		}
		q.Dequeue();
		q.Dequeue();
	

		q.Enqueue(10);
		int numOfElements=q.GetCount();
		for (size_t i = 0; i < numOfElements; i++)
		{
			std::cout << q.Dequeue() << " ";
		}
	}

	_CrtDumpMemoryLeaks();
}


