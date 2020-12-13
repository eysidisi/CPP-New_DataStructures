#pragma once
#include <iostream>
template <typename  K>
struct ListNode
{
	K data;
	ListNode<K>* nextNode;
};

template <class T>
class LinkedList
{

private:
	ListNode<T>* headNode = nullptr;
	int length = 0;
private:
	ListNode<T>* ReverseRecursive(ListNode<T>* tailNode, ListNode<T>* leadingNode);
public:
	~LinkedList();
public:
	LinkedList()
	{
		headNode = nullptr;
		length = 0;
	}
	LinkedList(const LinkedList& r)
	{

		headNode = nullptr;
		ListNode<T>* tempHeadNode = r.headNode;

		while (tempHeadNode != nullptr)
		{
			Add(tempHeadNode->data);
			tempHeadNode = tempHeadNode->nextNode;
		}
	}

	/// <summary>
	/// Adds newData to the end of list
	/// </summary>
	/// <param name="newData"></param>
	void Add(T newData);
	/// <summary>
	/// 
	/// </summary>
	void Display();
	/// <summary>
	/// Finds the maximum element in a list
	/// </summary>
	/// <returns></returns>
	T Max();
	/// <summary>
	/// Searches for an element and returns index 
	/// If no such element exists returns -1
	/// </summary>
	/// <typeparam name="K"></typeparam>
	int Find(T element);
	/// <summary>
	/// Inserts element in index given in the parameter "index"
	/// </summary>
	/// <param name="element"></param>
	/// <param name="index"></param>
	void Insert(T element, int index);
	/// <summary>
	/// Deletes the element at the given index
	/// </summary>
	/// <param name="index"></param>
	void Remove(size_t index = 0);
	/// <summary>
	/// Sorts list in a ascending order using Binary Sort algorithm
	/// </summary>
	void BinarySort();
	/// <summary>
	/// Checks if the list is sorted in ascending order
	/// </summary>
	/// <returns></returns>
	bool IsSortedInAscending();
	/// <summary>
	/// Checks if the list is sorted in descending order
	/// </summary>
	/// <returns></returns>
	bool IsSortedInDescending();
	/// <summary>
	/// Removes duplicates from the list
	/// </summary>
	void RemoveDuplicates();
	/// <summary>
	/// Reverses the list elements order
	/// </summary>
	void Reverse();
	/// <summary>
	/// Reverses the list int a recursive manner
	/// </summary>
	void ReverseRecursive();
	/// <summary>
	/// Concatenates two lists and returns a new list
	/// </summary>
	/// <param name="list1"></param>
	/// <param name="list2"></param>
	/// <returns></returns>
	static LinkedList<T> Concatenate(LinkedList<T> list1, LinkedList<T> list2);
	/// <summary>
	/// Sorts two lists and then creates a new list by merging the two lists
	/// </summary>
	/// <param name="list1"></param>
	/// <param name="list2"></param>
	/// <returns></returns>
	static LinkedList<T> Merge(LinkedList<T> list1, LinkedList<T> list2);
	LinkedList<T> operator=(const LinkedList& b);
};

template<class T>
inline ListNode<T>* LinkedList<T>::ReverseRecursive(ListNode<T>* tailNode, ListNode<T>* leadingNode)
{
	if (leadingNode == nullptr)
	{
		headNode = tailNode;
		return tailNode;
	}

	ReverseRecursive(leadingNode, leadingNode->nextNode)->nextNode = tailNode;
	return tailNode;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	while (headNode != nullptr)
	{
		ListNode<T>* nextNode = headNode->nextNode;
		delete(headNode);
		headNode = nextNode;
	}
}

template<class T>
void LinkedList<T>::Add(T newData)
{
	length++;
	if (headNode == nullptr)
	{
		headNode = new ListNode<T>();
		headNode->data = newData;
		headNode->nextNode = nullptr;

		return;
	}

	ListNode<T>* tempNode = headNode;

	while (tempNode->nextNode != nullptr)
	{
		tempNode = tempNode->nextNode;
	}

	tempNode->nextNode = new ListNode<T>();
	tempNode->nextNode->data = newData;
	tempNode->nextNode->nextNode = nullptr;
}

template<class T>
inline void LinkedList<T>::Display()
{
	ListNode<T>* tempNode = headNode;

	while (tempNode != nullptr)
	{
		std::cout << tempNode->data;
		tempNode = tempNode->nextNode;
	}

	std::cout << "\n";
}

template<class T>
T LinkedList<T>::Max()
{
	if (headNode == nullptr)
		throw "List has no elements";

	ListNode<T>* tempNode = headNode->nextNode;
	T maxElement = headNode->data;

	while (tempNode != nullptr)
	{
		if (tempNode->data > maxElement)
			maxElement = tempNode->data;
		tempNode = tempNode->nextNode;
	}

	return maxElement;

}

template <class T>
int LinkedList<T>::Find(T element)
{
	ListNode<T>* tempNode = headNode;

	for (size_t i = 0; i < length; i++)
	{
		if (tempNode->data == element)
			return i;
		tempNode = tempNode->nextNode;
	}

	return -1;
}

template<class T>
void LinkedList<T>::Insert(T element, int index)
{
	if (index<0 || index>length)
		return;

	auto* newNode = new ListNode<T>();
	newNode->data = element;

	if (index == 0)
	{
		newNode->nextNode = headNode;
		headNode = newNode;
		length++;
		return;
	}

	int currentIndex = 0;
	ListNode<T>* tempNode = headNode;
	while (currentIndex < index - 1)
	{
		tempNode = tempNode->nextNode;
		currentIndex++;
	}

	newNode->nextNode = tempNode->nextNode;
	tempNode->nextNode = newNode;
	length++;
}

template<class T>
inline void LinkedList<T>::Remove(size_t index)
{
	if (index<0 || index>length - 1)
		throw "Index out of range!";

	if (index == 0)
	{
		ListNode<T>* tempNode = headNode->nextNode;
		delete(headNode);
		headNode = tempNode;
		length--;
		return;
	}

	ListNode<T>* prevNode = headNode;

	for (size_t i = 0; i < index - 1; i++)
	{
		prevNode = prevNode->nextNode;
	}

	ListNode<T>* nodeToDelete = prevNode->nextNode;

	prevNode->nextNode = nodeToDelete->nextNode;

	delete(nodeToDelete);

	length--;
}

template<class T>
inline void LinkedList<T>::BinarySort()
{
	if (length == 0 || length == 1)
	{
		return;
	}

	for (size_t i = 0; i < length - 1; i++)
	{
		ListNode<T>* followerNode = headNode;
		ListNode<T>* leadingNode = headNode->nextNode;

		bool swappedAtLeastOne = false;

		for (size_t j = 0; j < length - i - 1; j++)
		{

			if (followerNode->data > leadingNode->data)
			{
				T tempData = leadingNode->data;
				leadingNode->data = followerNode->data;
				followerNode->data = tempData;
				swappedAtLeastOne = true;
			}

			followerNode = leadingNode;
			leadingNode = leadingNode->nextNode;
		}

		if (!swappedAtLeastOne)
		{
			break;
		}
	}
}

template<class T>
inline bool LinkedList<T>::IsSortedInAscending()
{
	if (length == 0 || length == 1)
	{
		return true;
	}

	ListNode<T>* leadingNode = headNode->nextNode;
	ListNode<T>* followerNode = headNode;

	while (leadingNode != nullptr)
	{
		if (followerNode->data > leadingNode->data)
		{
			return false;
		}

		followerNode = leadingNode;
		leadingNode = leadingNode->nextNode;
	}

	return true;
}

template<class T>
inline bool LinkedList<T>::IsSortedInDescending()
{
	if (length == 0 || length == 1)
	{
		return true;
	}
	ListNode<T>* leadingNode = headNode->nextNode;
	ListNode<T>* followerNode = headNode;

	while (leadingNode != nullptr)
	{
		if (followerNode->data < leadingNode->data)
		{
			return false;
		}

		followerNode = leadingNode;
		leadingNode = leadingNode->nextNode;
	}

	return true;
}

template<class T>
inline void LinkedList<T>::RemoveDuplicates()
{
	if (length == 0 || length == 1)
	{
		return;
	}

	ListNode<T>* fixedNode = headNode;

	while (fixedNode != nullptr)
	{
		ListNode<T>* movingNode = fixedNode->nextNode;
		ListNode<T>* followerNode = fixedNode;

		while (movingNode != nullptr)
		{
			if (movingNode->data == fixedNode->data)
			{
				followerNode->nextNode = movingNode->nextNode;
				delete(movingNode);
				movingNode = followerNode->nextNode;
				length--;
			}

			else
			{
				followerNode = movingNode;
				movingNode = movingNode->nextNode;
			}
		}

		fixedNode = fixedNode->nextNode;
	}
}

template<class T>
inline void LinkedList<T>::Reverse()
{
	if (length == 0 || length == 1)
	{
		return;
	}

	ListNode<T>* tailNode = nullptr;
	ListNode<T>* middleNode = headNode;
	ListNode<T>* leadingNode = middleNode->nextNode;

	while (middleNode != nullptr)
	{
		ListNode<T>* tempNode = nullptr;

		if (leadingNode != nullptr)
		{
			tempNode = leadingNode->nextNode;
		}
		middleNode->nextNode = tailNode;

		tailNode = middleNode;
		middleNode = leadingNode;
		leadingNode = tempNode;
	}

	headNode = tailNode;
}

template<class T>
inline void LinkedList<T>::ReverseRecursive()
{
	if (length == 0 || length == 1)
	{
		return;
	}

	ListNode<T>* lastNode = ReverseRecursive(headNode, headNode->nextNode);
	lastNode->nextNode = nullptr;
}

template<class T>
inline LinkedList<T> LinkedList<T>::Merge(LinkedList<T> list1, LinkedList<T> list2)
{

	LinkedList<T> newList;
	LinkedList<T> copyList1 = LinkedList<T>(list1);
	LinkedList<T> copyList2 = LinkedList<T>(list2);

	copyList1.BinarySort();
	copyList2.BinarySort();
	
	ListNode<T>* list1TempHead = copyList1.headNode;
	ListNode<T>* list2TempHead = copyList2.headNode;

	while (list1TempHead != nullptr && list2TempHead != nullptr)
	{
		if (list1TempHead->data > list2TempHead->data)
		{
			newList.Add(list2TempHead->data);
			list2TempHead = list2TempHead->nextNode;
		}

		else
		{
			newList.Add(copyList1.headNode->data);
			list1TempHead = list1TempHead->nextNode;
		}
	}

	ListNode<T>* ptr;
	if (list1TempHead ==nullptr)
	{
		ptr = list2TempHead;
	}
	else
	{
		ptr = list1TempHead;
	}

	while (ptr!=nullptr)
	{
		newList.Add(ptr->data);
		ptr = ptr->nextNode;
	}
	return newList;
}

template<class T>
inline LinkedList<T> LinkedList<T>::operator=(const LinkedList& b)
{
	this->length = b.length;
	this->headNode = b.headNode;
}

template<class T>
inline LinkedList<T> LinkedList<T>::Concatenate(const LinkedList<T> list1, const LinkedList<T> list2)
{
	LinkedList<T> newList;

	ListNode<T>* list1HeadNode = list1.headNode;
	while (list1HeadNode != nullptr)
	{
		(newList).Add(list1HeadNode->data);
		list1HeadNode = list1HeadNode->nextNode;
	}
	ListNode<T>* list2HeadNode = list2.headNode;
	while (list2HeadNode != nullptr)
	{
		(newList).Add(list2HeadNode->data);
		list2HeadNode = list2HeadNode->nextNode;
	}

	return newList;
}

