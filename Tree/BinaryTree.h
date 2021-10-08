#include <iostream>
#include "BNode.h"
using namespace std;
class BinaryTree
{
protected:
	BNode* root;
public:
	BinaryTree()
	{
		root = NULL;
	}
	BinaryTree(const BinaryTree& bt)
	{
		if (bt.root)
		{
			this->root = new BNode(*bt.root);
		}
		else
		{
			this->root = NULL;
		}
	}
	~BinaryTree()
	{
		if (root) delete root;
	}
	void preOrder(BNode *current)
	{
		if (current != NULL)
		{
			cout << current->data << " ";
			preOrder(current->left);
			preOrder(current->right);
		}
	}
	void inOrder(BNode *current)
	{
		if (current != NULL)
		{
			inOrder(current->left);
			cout << current->data << " ";
			inOrder(current->right);
		}
	}
	void postOrder(BNode *current)
	{
		if (current != NULL)
		{
			postOrder(current->left);
			postOrder(current->right);
			cout << current->data << " ";
		}
	}
	void preTraverse()
	{
		preOrder(root);
		cout << endl;
	}
	void inTraverse()
	{
		inOrder(root);
		cout << endl;
	}
	void postTraverse()
	{
		postOrder(root);
		cout << endl;
	}
};
