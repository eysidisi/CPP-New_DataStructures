#pragma once
#include <iostream>
#include <queue>
#include<stack>
template<class T>
struct Node
{
	Node<T>* lChild;
	T value;
	Node<T>* rChild;
};
template<class T>
class BinaryTree
{
	Node<T>* rootNode = nullptr;

public:
	~BinaryTree()
	{
		if (rootNode == nullptr)
		{
			return;
		}

		std::queue <Node<T>*> ptrQueue;
		ptrQueue.push(rootNode);
		std::stack <Node<T>*> ptrStck;

		Node<T>* tempNode;

		while (!ptrQueue.empty())
		{
			tempNode = (Node<T>*) ptrQueue.front();
			ptrQueue.pop();
			ptrStck.push(tempNode);

			if (tempNode->lChild != nullptr)
			{
				ptrQueue.push(tempNode->lChild);
			}

			if (tempNode->rChild != nullptr)
			{
				ptrQueue.push(tempNode->rChild);
			}
		}

		while (!ptrStck.empty())
		{
			delete((Node<T>*)ptrStck.top());
			ptrStck.pop();
		}
	}
private:
	void RecursiveDisplayPreOrder(Node<T>* node);
	void RecursiveDisplayInOrder(Node<T>* node);
	void RecursiveDisplayPostOrder(Node<T>* node);
public:
	/// <summary>
	/// Inserts given element into the tree using pre-order fashion
	/// </summary>
	/// <param name="element"></param>
	void Insert(T elementValue);
	/// <summary>
	/// Displays tree elements in pre-order manner 
	/// </summary>	
	void DisplayPreOrder();
	/// <summary>
	/// Displays tree elements in in-order manner
	/// </summary>
	void DisplayInOrder();
	/// <summary>
	/// Displays tree elements in post-order manner
	/// </summary>
	void DisplayPostOrder();
};

template<class T>
inline void BinaryTree<T>::RecursiveDisplayPreOrder(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::cout << node->value << " ";
	RecursiveDisplayPreOrder(node->lChild);
	RecursiveDisplayPreOrder(node->rChild);
}

template<class T>
inline void BinaryTree<T>::RecursiveDisplayInOrder(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	RecursiveDisplayInOrder(node->lChild);
	std::cout << node->value << " ";
	RecursiveDisplayInOrder(node->rChild);
}

template<class T>
inline void BinaryTree<T>::RecursiveDisplayPostOrder(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	RecursiveDisplayPostOrder(node->lChild);
	RecursiveDisplayPostOrder(node->rChild);
	std::cout << node->value<<" ";
}

template<class T>
void inline BinaryTree<T>::Insert(T elementValue)
{
	if (rootNode == nullptr)
	{
		rootNode = new Node<T>();
		rootNode->value = elementValue;
		return;
	}

	std::queue <Node<T>*> ptrQueue;
	ptrQueue.push(rootNode);

	Node<T>* tempNode;

	while (true)
	{
		tempNode = ptrQueue.front();
		ptrQueue.pop();
		ptrQueue.push(tempNode->lChild);
		ptrQueue.push(tempNode->rChild);

		if (tempNode->lChild == nullptr)
		{
			tempNode->lChild = new Node<T>();
			tempNode->lChild->value = elementValue;
			break;
		}
		else if (tempNode->rChild == nullptr)
		{
			tempNode->rChild = new Node<T>();
			tempNode->rChild->value = elementValue;
			break;
		}
	}
}

template<class T>
inline void BinaryTree<T>::DisplayPreOrder()
{
	RecursiveDisplayPreOrder(rootNode);
}

template<class T>
inline void BinaryTree<T>::DisplayInOrder()
{
	RecursiveDisplayInOrder(rootNode);
}

template<class T>
inline void BinaryTree<T>::DisplayPostOrder()
{
	RecursiveDisplayPostOrder(rootNode);
}
