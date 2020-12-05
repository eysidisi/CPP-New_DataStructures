#pragma once
#include <iostream>
template <class T>
class LinkedList
{
private:
	template <class K>
	struct ListNode
	{
		K data;
		ListNode<K>* nextNode;
	};

private:
	ListNode<T>* headNode = nullptr;
	int length = 0;
public:
	~LinkedList();
public:
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
};


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
