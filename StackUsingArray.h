#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>

template <class T>
class StackUsingArray
{
private:
	size_t _length;
	size_t _count;
	T* _topPointer;

public:
	StackUsingArray()
	{
		_length = 5;
		_count = 0;
		_topPointer = new T[_length];
	}
	~StackUsingArray()
	{
		delete[]_topPointer;
	}
	void Push(T element);
	void Display();
	T Pop();
	T Peek();
	bool IsEmpty();
	bool IsFull();
};

template<class T>
inline void StackUsingArray<T>::Push(T element)
{
	// If stack is full
	if (_count == _length)
	{
		_length *= 2;
		T* tempPointer = new T[_length];
		std::copy(_topPointer, _topPointer + _count, tempPointer);
		delete[]_topPointer;
		_topPointer = tempPointer;
	}
	_topPointer[_count] = element;
	_count++;
}

template<class T>
inline void StackUsingArray<T>::Display()
{
	for (size_t index = 0; index < _count; index++)
	{
		std::cout << _topPointer[index] << " ";
	}
	std::cout << std::endl;
}

template<class T>
inline T StackUsingArray<T>::Pop()
{
	if (_count == 0)
	{
		return NULL;
	}
	return _topPointer[--_count];
}

template<class T>
inline T StackUsingArray<T>::Peek()
{
	if (_count == 0)
	{
		return NULL;
	}

	return _topPointer[_count - 1];
}

template<class T>
inline bool StackUsingArray<T>::IsEmpty()
{
	return _count == 0;
}

template<class T>
inline bool StackUsingArray<T>::IsFull()
{
	return _count == _length;
}


