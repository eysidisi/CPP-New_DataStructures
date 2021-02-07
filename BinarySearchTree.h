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
class BinarySearchTree
{
private:
	Node<T>* rootNode = nullptr;

public:
	void InsertIterative(T element);
	void InsertRecursive(T element);
	void DisplayLevelOrder();
	void DisplayInOrderRecursive();
	void DisplayInOrderIterative();
	void DeleteElement(T element);
	bool SearchForElement(T element);

private:
	void DisplayInOrderPrivate(Node<T>* node);
	void PrivateInsertRecursive(Node<T>* node, T element);
	Node<T>* PrivateDeleteRecursively(Node<T>* currentNode, T elementToDelete);
	Node<T>* FindPredecessor(Node<T>* nodePtr);
};

template<class T>
inline void BinarySearchTree<T>::InsertIterative(T element)
{
	if (rootNode == nullptr)
	{
		rootNode = new Node<T>();
		rootNode->value = element;
		return;
	}

	Node<T>* currentNode = rootNode;

	while (true)
	{
		if (element >= currentNode->value)
		{
			if (currentNode->rChild == nullptr)
			{
				currentNode->rChild = new Node<T>();
				currentNode->rChild->value = element;
				return;
			}

			currentNode = currentNode->rChild;
		}

		else
		{
			if (currentNode->lChild == nullptr)
			{
				currentNode->lChild = new Node<T>();
				currentNode->lChild->value = element;
				return;
			}

			currentNode = currentNode->lChild;
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::InsertRecursive(T element)
{
	if (rootNode == nullptr)
	{
		rootNode = new Node<T>();
		rootNode->value = element;
		return;
	}
	PrivateInsertRecursive(rootNode, element);
}

template<class T>
inline void BinarySearchTree<T>::DisplayLevelOrder()
{
	if (rootNode == nullptr)
	{
		return;
	}

	std::queue<Node<T>*> nodeQueue;
	nodeQueue.push(rootNode);

	Node<T>* currentNode;

	while (!nodeQueue.empty())
	{
		currentNode = nodeQueue.front();
		nodeQueue.pop();

		std::cout << currentNode->value << " ";

		if (currentNode->lChild != nullptr)
		{
			nodeQueue.push(currentNode->lChild);
		}

		if (currentNode->rChild != nullptr)
		{
			nodeQueue.push(currentNode->rChild);
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::DisplayInOrderRecursive()
{
	DisplayInOrderPrivate(rootNode);
}

template<class T>
inline void BinarySearchTree<T>::DisplayInOrderIterative()
{
	if (rootNode == nullptr)
	{
		return;
	}

	std::stack <Node<T>*> nodeStack;

	Node<T>* currentNode = rootNode;

	while (!nodeStack.empty() || currentNode != nullptr)
	{
		if (currentNode != nullptr)
		{
			nodeStack.push(currentNode);
			currentNode = currentNode->lChild;
		}

		else
		{
			currentNode = nodeStack.top();
			std::cout << currentNode->value << " ";
			nodeStack.pop();
			currentNode = currentNode->rChild;
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::DeleteElement(T element)
{
	PrivateDeleteRecursively(rootNode, element);
}

template<class T>
inline void BinarySearchTree<T>::DisplayInOrderPrivate(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	DisplayInOrderPrivate(node->lChild);
	std::cout << node->value << " ";
	DisplayInOrderPrivate(node->rChild);
}

template<class T>
inline void BinarySearchTree<T>::PrivateInsertRecursive(Node<T>* node, T element)
{
	if (element >= node->value)
	{
		if (node->rChild == nullptr)
		{
			node->rChild = new Node<T>();
			node->rChild->value = element;
			return;
		}
		else
		{
			PrivateInsertRecursive(node->rChild, element);
		}
	}
	else
	{
		if (node->lChild == nullptr)
		{
			node->lChild = new Node<T>();
			node->lChild->value = element;
			return;
		}
		else
		{
			PrivateInsertRecursive(node->lChild, element);
		}

	}
}


template<class T>
inline Node<T>* BinarySearchTree<T>::PrivateDeleteRecursively(Node<T>* currentNode, T elementToDelete)
{
	if (currentNode == nullptr)
	{
		return nullptr;
	}

	if (elementToDelete > currentNode->value)
	{
		currentNode->rChild=PrivateDeleteRecursively(currentNode->rChild, elementToDelete);
		return currentNode;
	}

	else if (elementToDelete < currentNode->value)
	{
		currentNode->lChild=	PrivateDeleteRecursively(currentNode->lChild, elementToDelete);
		return currentNode;
	}

	else
	{
		if (currentNode->lChild == nullptr && currentNode->rChild == nullptr)
		{
			delete(currentNode);
			return nullptr;
		}

		else if (currentNode->lChild == nullptr && currentNode->rChild != nullptr)
		{
			currentNode->value = currentNode->rChild->value;
			currentNode->rChild = PrivateDeleteRecursively(currentNode->rChild, currentNode->rChild->value);
			return(currentNode);
		}

		else if (currentNode->rChild == nullptr && currentNode->lChild != nullptr)
		{
			currentNode->value = currentNode->lChild->value;
			currentNode->lChild = PrivateDeleteRecursively(currentNode->lChild, currentNode->lChild->value);
			return(currentNode);
		}

		else
		{
			Node<T>* predecessorNode = FindPredecessor(currentNode);
			currentNode->value = predecessorNode->value;
			currentNode->lChild = PrivateDeleteRecursively(currentNode->lChild, predecessorNode->value);
			return currentNode;
		}
	}
}

template<class T>
inline Node<T>* BinarySearchTree<T>::FindPredecessor(Node<T>* nodePtr)
{
	Node<T>* currentNode = nodePtr->lChild;

	while (currentNode->rChild != nullptr)
	{
		currentNode = currentNode->rChild;
	}

	return currentNode;
}

template<class T>
inline bool BinarySearchTree<T>::SearchForElement(T element)
{
	if (rootNode == nullptr)
	{
		return false;
	}
	Node<T>* currentNode = rootNode;
	while (currentNode != nullptr)
	{
		if (currentNode->value == element)
		{
			return true;
		}

		if (element > currentNode->value)
		{
			currentNode = currentNode->rChild;
		}
		else
		{
			currentNode = currentNode->lChild;
		}
	}

	return false;
}
