#pragma once
/// <summary>
/// An implemantation of a Dynamic, generic array with some functionality
/// </summary>
/// <typeparam name="T"></typeparam>
#include <iostream>
template <typename T>
class ArrayADT
{
private:
	/// Total size of the array
	size_t size;
	/// current number of elements in array
	size_t length;
	T* headPtr;
public:
	ArrayADT(size_t size = 5) :size(size), length(0)
	{
		headPtr = new T[size];
	}

	void Append(T newElement);
	void Display();
	void Insert(T newElement, size_t index);
	T Delete(size_t index);
	int LinearSearch(T searchElement);
	int BinarySearch(T searchElement);
	int RecursiveBinarySearch(T searchElement);

	/// <summary>
	/// Returns the element at the parameter index.
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	T Get(size_t index);

	/// <summary>
	/// Returns the index of max element
	/// </summary>
	/// <typeparam name="T"></typeparam>
	int Max();

	/// <summary>
	/// Sets the value at index.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	void Set(size_t index, T value);

	/// <summary>
	/// Reverses array
	/// </summary>
	/// <typeparam name="T"></typeparam>
	void Reverse();

	/// <summary>
	/// Shifts array to right for num of index. Fills empty elements with null
	/// </summary>
	/// <typeparam name="T"></typeparam>
	void ShiftRight(size_t shiftNum);

	/// <summary>
	/// Shifts array to left for num of index. Deletes elements
	/// </summary>
	/// <typeparam name="T"></typeparam>
	void ShiftLeft(size_t shiftNum);

	/// <summary>
	/// Inserts an element in a ascending sorted array
	/// </summary>
	/// <param name="newElement"></param>
	void InsertInASortedArr(T newElement);

	/// <summary>
	/// Merges two sorted arrays
	/// </summary>
	/// <typeparam name="T"></typeparam>
	ArrayADT<T> MergeSortedArrays(ArrayADT<T> arr2);

	//------------------------------------------ SET OPERATIONS -------------------------------------------

	/// <summary>
	/// Creates union of two ArrayADTs
	/// </summary>
	/// <param name="arr"></param>
	/// <returns></returns>
	ArrayADT<T> Union(ArrayADT<T> arr);

	/// <summary>
	/// Returns intersection of two ArrayADTs
	/// </summary>
	/// <param name="arr"></param>
	/// <returns></returns>
	ArrayADT<T> Intersection(ArrayADT<T>arr);

	/// <summary>
	/// Returns elements which present in this arr and not present in other arr
	/// </summary>
	/// <param name="arr"></param>
	/// <returns></returns>
	ArrayADT<T> Difference(ArrayADT<T>arr);

private:
	void ResizeArr();
};

template<typename T>
void ArrayADT<T>::Append(T newElement)
{
	if (length == size)
	{
		ResizeArr();
	}

	headPtr[length] = newElement;
	length++;
}

template<typename T>
inline void ArrayADT<T>::Display()
{
	for (size_t index = 0; index < length; index++)
	{
		std::cout << headPtr[index] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
inline void ArrayADT<T>::Insert(T newElement, size_t insertionIndex)
{
	if (insertionIndex > length || insertionIndex < 0)
		return;
	if (length == size)
		ResizeArr();

	for (size_t arrIndex = length; arrIndex > insertionIndex; arrIndex--)
	{
		headPtr[arrIndex] = headPtr[arrIndex - 1];
	}

	headPtr[insertionIndex] = newElement;
	length++;
}

template<typename T>
inline T ArrayADT<T>::Delete(size_t index)
{
	if (index > length - 1 || index < 0)
		return NULL;

	T returnItem = headPtr[index];
	for (size_t currentIndex = index; currentIndex < length - 1; currentIndex++)
	{
		headPtr[currentIndex] = headPtr[currentIndex + 1];
	}

	length--;
	return returnItem;
}

template<typename T>
inline int ArrayADT<T>::LinearSearch(T searchElement)
{
	if (length < 1)
		return -1;

	for (size_t index = 0; index < length; index++)
	{
		if (searchElement == headPtr[index])
			return index;
	}
	return -1;
}

template<typename T>
int ArrayADT<T>::BinarySearch(T searchElement)
{
	if (length < 1)
		return -1;

	// TODO: Check if array is sorted

	int lowIndex = 0;
	int highIndex = length - 1;
	int midIndex;

	while (lowIndex <= highIndex)
	{
		midIndex = lowIndex + floor((highIndex - lowIndex) / 2);

		if (headPtr[midIndex] == searchElement)
			return headPtr[midIndex];

		if (headPtr[midIndex] > searchElement)
		{
			highIndex = midIndex - 1;
		}
		else
		{
			lowIndex = midIndex + 1;
		}
	}

	return -1;


	return 0;
}

template<typename T>
inline int ArrayADT<T>::RecursiveBinarySearch(T searchElement)
{
	if (length < 1)
		return -1;

	static int highIndex = length - 1;
	static int lowIndex = 0;
	static int midIndex;
	midIndex = lowIndex + floor((highIndex - lowIndex) / 2);

	if (lowIndex > highIndex)
		return -1;

	if (headPtr[midIndex] == searchElement)
		return headPtr[midIndex];

	if (headPtr[midIndex] > searchElement)
	{
		highIndex = midIndex - 1;
		return RecursiveBinarySearch(searchElement);
	}
	else
	{
		lowIndex = midIndex + 1;
		return RecursiveBinarySearch(searchElement);
	}
}

template<typename T>
inline T ArrayADT<T>::Get(size_t index)
{
	if (index < 0 || index >= length)
		throw std::out_of_range("index is out of range");

	return(headPtr[index]);
}

template<typename T>
inline int ArrayADT<T>::Max()
{
	if (length == 0)
		return -1;


	size_t maxElementIndex = 0;

	for (size_t i = 1; i < length; i++)
	{
		if (headPtr[i] > headPtr[maxElementIndex])
			maxElementIndex = i;
	}
	return maxElementIndex;
}

template<typename T>
inline void ArrayADT<T>::Set(size_t index, T value)
{
	if (index <= 0 || index >= length)
		throw std::out_of_range("index is out of range");
	headPtr[index] = value;
}

template<typename T>
inline void ArrayADT<T>::Reverse()
{
	size_t endIndex = length - 1;
	size_t frontIndex = 0;

	while (endIndex > frontIndex)
	{
		T temp = headPtr[frontIndex];
		headPtr[frontIndex] = headPtr[endIndex];
		headPtr[endIndex] = temp;
		endIndex--;
		frontIndex++;
	}
}

template<typename T>
inline void ArrayADT<T>::ShiftRight(size_t shiftNum)
{
	shiftNum = shiftNum % length;
	ShiftLeft(length - shiftNum);
}

template<typename T>
inline void ArrayADT<T>::ShiftLeft(size_t shiftNum)
{
	shiftNum = shiftNum % length;

	T* newArr = new T[size];

	for (size_t i = 0; i < length; i++)
	{
		size_t arrIndex = (i + shiftNum) % length;
		newArr[i] = headPtr[arrIndex];
	}

	delete[] headPtr;

	headPtr = newArr;
}

template<typename T>
inline void ArrayADT<T>::InsertInASortedArr(T newElement)
{

	if (length <= 0)
		return;

	if (newElement >= headPtr[length - 1])
	{
		Append(newElement);
		return;
	}

	if (newElement <= headPtr[0])
	{
		Insert(newElement, 0);
		return;
	}

	size_t smallIndex = 0;
	size_t largeIndex = length - 1;
	size_t midIndex = smallIndex + floor((largeIndex - smallIndex) / 2);

	while (largeIndex >= smallIndex)
	{
		if (headPtr[midIndex] <= newElement)
		{
			if (headPtr[midIndex + 1] >= newElement)
			{
				Insert(newElement, midIndex + 1);
				break;
			}
			else
			{
				smallIndex = midIndex + 1;
				midIndex = smallIndex + floor((largeIndex - smallIndex) / 2);
			}
		}

		else
		{
			largeIndex = midIndex - 1;
			midIndex = smallIndex + floor((largeIndex - smallIndex) / 2);
		}
	}

}

template<typename T>
ArrayADT<T> ArrayADT<T>::MergeSortedArrays(ArrayADT<T> arr2)
{
	ArrayADT<T>* newArr = new ArrayADT(arr2.size + size);

	if (length == 0)
	{
		for (size_t i = 0; i < arr2.length; i++)
		{
			newArr->Append(arr2.Get(i));
		}
		return *newArr;
	}

	if (arr2.length == 0)
	{
		for (size_t i = 0; i < length; i++)
		{
			newArr->Append(Get(i));
		}

		return *newArr;
	}

	size_t arr1Index = 0;
	size_t arr2Index = 0;

	while (arr1Index != length && arr2Index != arr2.length)
	{
		if (Get(arr1Index) >= arr2.Get(arr2Index))
		{
			newArr->Append(arr2.Get(arr2Index));
			arr2Index++;
		}
		else
		{
			newArr->Append(Get(arr1Index));
			arr1Index++;
		}
	}

	if (arr1Index == length)
	{
		while (arr2Index < arr2.length)
		{
			newArr->Append(arr2.Get(arr2Index));
			arr2Index++;
		}
	}

	else
	{
		while (arr1Index < length)
		{
			newArr->Append(Get(arr1Index));
			arr1Index++;
		}
	}

	return *newArr;
}

template<typename T>
inline ArrayADT<T> ArrayADT<T>::Union(ArrayADT<T> arr2)
{
	ArrayADT<T>* newArr = new ArrayADT<T>();

	for (size_t i = 0; i < length; i++)
	{
		if (newArr->LinearSearch(headPtr[i]) == -1)
			newArr->Append(headPtr[i]);
	}

	for (size_t i = 0; i < arr2.length; i++)
	{
		if (newArr->LinearSearch(arr2.Get(i)) == -1)
			newArr->Append(arr2.Get(i));
	}

	return *newArr;
}

template<typename T>
inline ArrayADT<T> ArrayADT<T>::Intersection(ArrayADT<T> arr)
{
	ArrayADT<T>* newArr = new ArrayADT<T>();

	for (size_t i = 0; i < length; i++)
	{
		if (arr.LinearSearch(headPtr[i]) != -1)
			newArr->Append(headPtr[i]);
	}

	return *newArr;
}

template<typename T>
inline ArrayADT<T> ArrayADT<T>::Difference(ArrayADT<T> arr)
{
	ArrayADT<T>* newArr = new ArrayADT<T>();
	for (size_t i = 0; i < length; i++)
	{
		if (arr.LinearSearch(headPtr[i]) == -1)
			newArr->Append(headPtr[i]);
	}

	return *newArr;
}

template<typename T>
inline void ArrayADT<T>::ResizeArr()
{
	size *= 2;
	T* tempPtr = new T[size];

	for (size_t index = 0; index < length; index++)
	{
		tempPtr[index] = headPtr[index];
	}

	delete[] headPtr;
	headPtr = tempPtr;
	tempPtr = nullptr;
}
