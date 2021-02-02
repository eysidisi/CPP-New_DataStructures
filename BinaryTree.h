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
	/// Inserts given element into the tree level by level
	/// </summary>
	/// <param name="element"></param>
	void Insert(T elementValue);
	/// <summary>
	/// Displays tree elements in pre-order manner 
	/// </summary>	
	void DisplayPreOrder();
	/// <summary>
	/// Displays tree elements in pre-order manner using a loop instead of recursion
	/// </summary>	
	void IterativeDisplayPreOrder();
	/// <summary>
	/// Displays tree elements in in-order manner
	/// </summary>
	void DisplayInOrder();
	/// <summary>
	/// Displays tree elements in in-order manner using a loop instead of recursion
	/// </summary>	
	void IterativeDisplayInOrder();
	/// <summary>
	/// Displays tree elements in post-order manner
	/// </summary>
	void DisplayPostOrder();
	/// <summary>
	/// Displays tree elements in post-order manner using a loop instead of recursion
	/// </summary>	
	void IterativeDisplayPostOrder();
	/// <summary>
	/// Displays tree by level order
	/// </summary>
	void LevelOrderTraversal();
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
	std::cout << node->value << " ";
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
inline void BinaryTree<T>::IterativeDisplayPreOrder()
{
	std::stack<Node<T>*> nodeStack;

	Node<T>* currentNode = rootNode;


	while (currentNode != nullptr || !nodeStack.empty())
	{
		if (currentNode != nullptr)
		{
			std::cout << currentNode->value << " ";
			nodeStack.push(currentNode);
			currentNode = currentNode->lChild;
		}

		else
		{
			currentNode = nodeStack.top();
			nodeStack.pop();
			currentNode = currentNode->rChild;
		}
	}
}

template<class T>
inline void BinaryTree<T>::DisplayInOrder()
{
	RecursiveDisplayInOrder(rootNode);
}

template<class T>
inline void BinaryTree<T>::IterativeDisplayInOrder()
{
	std::stack<Node<T>*> nodeStack;

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
inline void BinaryTree<T>::DisplayPostOrder()
{
	RecursiveDisplayPostOrder(rootNode);
}

template<class T>
inline void BinaryTree<T>::IterativeDisplayPostOrder()
{
	std::stack<Node<T>*> nodeStack1, nodeStack2;

	Node<T>* currentNode = nullptr;

	bool printNode = false;
	nodeStack1.push(rootNode);
	while (!nodeStack1.empty())
	{
		currentNode = nodeStack1.top();
		nodeStack2.push(currentNode);
		nodeStack1.pop();

		if (currentNode->lChild)
		{
			nodeStack1.push(currentNode->lChild);
		}

		if (currentNode->rChild)
		{
			nodeStack1.push(currentNode->rChild);
		}
	}

	while (!nodeStack2.empty())
	{
		std::cout << (nodeStack2.top())->value << " ";
		nodeStack2.pop();
	}
}

template<class T>
inline void BinaryTree<T>::LevelOrderTraversal()
{
	std::queue<Node<T>*>nodeQueue;
	nodeQueue.push(rootNode);
	Node<T>* currentNode;

	while (!nodeQueue.empty())
	{
		currentNode = nodeQueue.front();
		nodeQueue.pop();

		std::cout << currentNode->value;

		if (currentNode->lChild!=nullptr)
		{
			nodeQueue.push(currentNode->lChild);
		}
		
		if (currentNode->rChild!= nullptr)
		{
			nodeQueue.push(currentNode->rChild);
		}
	}
}
