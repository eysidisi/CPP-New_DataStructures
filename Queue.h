#pragma once
/// <summary>
/// A Queue implementation using one array and two array index parameters
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
class Queue
{
private:
	int size;
	int count;
	T* arrPtr;
	int headPtrIndex;
	int endPtrIndex;
public:
	Queue()
	{
		size = 5;
		count = 0;
		arrPtr = new T[size];
		headPtrIndex = -1;
		endPtrIndex = -1;
	}
	void Enqueue(T element);
	T Dequeue();
	size_t GetCount();
	~Queue()
	{
		delete[] arrPtr;
	}
private:
	void IncreaseArrSize();
	void OrginizeArr();
};

template<class T>
inline void Queue<T>::Enqueue(T element)
{
	if (count == size)
	{
		IncreaseArrSize();
	}

	else if (endPtrIndex == size - 1)
	{
		OrginizeArr();
	}

	arrPtr[++endPtrIndex] = element;
	count++;
}

template<class T>
inline T Queue<T>::Dequeue()
{
	if (count == 0)
	{
		return NULL;
	}

	count--;
	return arrPtr[++headPtrIndex];
}

template<class T>
inline size_t Queue<T>::GetCount()
{
	return count;
}

template<class T>
inline void Queue<T>::IncreaseArrSize()
{
	size *= 2;
	T* tempPtr = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		tempPtr[i] = arrPtr[i];
	}

	delete[] arrPtr;
	arrPtr = tempPtr;
}

template<class T>
inline void Queue<T>::OrginizeArr()
{
	T* tempPtr = new T[size];
	headPtrIndex = -1;
	endPtrIndex = -1;
	for (int i = 0; i < count; i++)
	{
		tempPtr[i] = arrPtr[i];
		endPtrIndex++;
	}
	delete[] arrPtr;
	arrPtr = tempPtr;
}
