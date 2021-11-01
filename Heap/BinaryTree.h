#include <iostream>
#include <queue>
#include "BNode.h"
using namespace std;
class BinaryTree
{
public:
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
	BNode* getRoot()
	{
		return root;
	}
	void preTraverse(BNode *current)
	{
		if (current != NULL)
		{
			cout << current->data << " ";
			preTraverse(current->left);
			preTraverse(current->right);
		}
	}
	void inTraverse(BNode *current)
	{
		if (current != NULL)
		{
			inTraverse(current->left);
			cout << current->data << " ";
			inTraverse(current->right);
		}
	}
	void postTraverse(BNode *current)
	{
		if (current != NULL)
		{
			postTraverse(current->left);
			postTraverse(current->right);
			cout << current->data << " ";
		}
	}
	void preOrder()
	{
		preTraverse(root);
		cout << endl;
	}
	void inOrder()
	{
		inTraverse(root);
		cout << endl;
	}
	void postOrder()
	{
		postTraverse(root);
		cout << endl;
	}
	void levelOrder()
	{
		if (root != NULL)
		{
			queue<BNode*> q;
			q.push(root);
			while (!q.empty())
			{
				BNode* temp = q.front();
				cout << temp->data << endl;
				q.pop();
				if (temp->left != NULL)
				{
					q.push(temp->left);
				}
				if (temp->right != NULL)
				{
					q.push(temp->right);
				}
			}
		}
	}
	int height(BNode* node)
	{
		if (node == NULL)
		{
			return -1;
		}
		else
		{
			/* compute the depth of each subtree */
			int lDepth = height(node->left);
			int rDepth = height(node->right);

			/* use the larger one */
			return max(lDepth, rDepth) + 1;
		}
	}

	int totalNodes()
	{
		return (1 << (height(root) + 1)) - 1;  // n = 2^(h+1)-1
	}
	static void arrayRepresentation(BNode *current, int i, int *arr)
	{
		if (current != NULL)
		{
			arr[i] = current->data;
			arrayRepresentation(current->left, 2 * i + 1, arr);
			arrayRepresentation(current->right, 2 * i + 2, arr);
		}
	}
	int* toArray()
	{
		int* arr = new int[totalNodes()] {0};
		arrayRepresentation(root, 0, arr);
		return arr;
	}
};
