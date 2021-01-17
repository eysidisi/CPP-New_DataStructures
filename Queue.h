#pragma once
template <class T>
class Queue
{
private:
	int size;
	int count;
	T* arrPtr;
	int headIndex;
	int endIndex;
public:
	Queue()
	{
		size = 5;
		count = 0;
		arrPtr = new T[size];
		headIndex = -1;
		endIndex = -1;
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

	else if (endIndex == size - 1)
	{
		OrginizeArr();
	}

	arrPtr[++endIndex] = element;
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
	return arrPtr[++headIndex];
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
	headIndex = -1;
	endIndex = -1;
	for (int i = 0; i < count; i++)
	{
		tempPtr[i] = arrPtr[i];
		endIndex++;
	}
	delete[] arrPtr;
	arrPtr = tempPtr;
}
