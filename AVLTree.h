#pragma once
struct AVLTreeNode
{
public:
	int data;
	AVLTreeNode* lNode;
	AVLTreeNode* rNode;
};

class AVLTree
{
private:
	AVLTreeNode* rootNode;

public:
	void Insert(int data);
};

