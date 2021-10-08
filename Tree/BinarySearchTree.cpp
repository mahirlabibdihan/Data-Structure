#include <iostream>
#include "BinaryTree.h"
using namespace std;


class BST:public BinaryTree
{
public:
	BST():BinaryTree()
	{
	}
	BST(const BST& bst):BinaryTree(bst)
	{
	}
	BNode* search(int data)
	{
		if (root == NULL)
		{
			return NULL;
		}
		else
		{
			BNode* current = root;
			while (data != current->data)
			{
				if (data < current->data)
				{
					if (current->left == NULL)
					{
						return NULL;
					}
					else
					{
						current = current->left;
					}
				}
				else
				{
					if (current->right == NULL)
					{
						return NULL;
					}
					else
					{
						current = current->right;
					}
				}
			}
			return current;
		}
	}
	void insert(int data)
	{
		if (root == NULL)
		{
			root = new BNode(data);
		}
		else
		{
			BNode* current = root;
			while (true)
			{
				if (data < current->data)
				{
					if (current->left == NULL)
					{
						current->left = new BNode(data);
						return;
					}
					else
					{
						current = current->left;
					}
				}
				else
				{
					if (current->right == NULL)
					{
						current->right = new BNode(data);
						return;
					}
					else
					{
						current = current->right;
					}
				}
			}
		}
	}
	void erase(int data)
	{
	}
};


int main()
{
	int n, m;
	cin >> n;

	BST bst;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		bst.insert(m);
	}

	bst.inTraverse();
}


