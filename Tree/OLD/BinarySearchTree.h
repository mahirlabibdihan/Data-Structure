// Reference: http://www.btechsmartclass.com/data_structures/binary-search-tree.html
#include <iostream>
#include "BinaryTree.h"
using namespace std;

class BST : public BinaryTree
{
public:
	BST() : BinaryTree()
	{
	}
	BST(const BST &bst) : BinaryTree(bst)
	{
	}
	BNode *search(int data)
	{
		if (root == NULL)
		{
			return NULL;
		}
		else
		{
			BNode *current = root;
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
			BNode *current = root;
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
	static BNode *getMin(BNode *root)
	{
		BNode *min = root;
		while (min != NULL && min->left != NULL)
		{
			min = min->left;
		}
		return min;
	}
	static BNode *getMax(BNode *root)
	{
		BNode *max = root;
		while (max != NULL && max->right != NULL)
		{
			max = max->right;
		}
		return max;
	}
	BNode *getMin()
	{
		BNode *min = root;
		while (min != NULL && min->left != NULL)
		{
			min = min->left;
		}
		return min;
	}
	BNode *getMax()
	{
		BNode *max = root;
		while (max != NULL && max->right != NULL)
		{
			max = max->right;
		}
		return max;
	}
	void erase(int data)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			// Searching the node to be deleted
			BNode *target = root, *parent = NULL;
			while (data != target->data)
			{
				parent = target;
				if (data < target->data)
				{
					if (target->left == NULL)
					{
						return;
					}
					else
					{
						target = target->left;
					}
				}
				else
				{
					if (target->right == NULL)
					{
						return;
					}
					else
					{
						target = target->right;
					}
				}
			}

			// Deleting target node
			// Case-1:  Deleting a node with no child
			if (target->left == NULL && target->right == NULL)
			{
				if (target == root)
					root = NULL;
				else if (target == parent->left)
					parent->left = NULL;
				else if (target == parent->right)
					parent->right = NULL;
				// Delete the target node
				delete target;
			}
			// Case-2: Deleting a node with one child
			else if (target->left == NULL)
			{
				if (target == root)
					root = target->right;
				else if (target == parent->left)
					parent->left = target->right;
				else if (target == parent->right)
					parent->right = target->right;
				// Delete the target node
				delete target;
			}
			else if (target->right == NULL)
			{
				if (target == root)
					root = target->left;
				else if (target == parent->left)
					parent->left = target->left;
				else
					parent->right = target->left;
				// Delete the target node
				delete target;
			}
			// Case-3: Deleting a node with two child
			else
			{
				// Finding the smallest node in the right subtree of the target(Inorder Succesor)
				// We could also used largest node of left subtree
				BNode *inSucc = target->right;
				while (inSucc != NULL && inSucc->left != NULL)
				{
					inSucc = inSucc->left;
				}

				int value = inSucc->data;
				// Delete the successor
				erase(value);

				// Replace the target node with its succesor
				if (target == root)
					root->data = value;
				else if (target == parent->left)
					parent->left->data = value;
				else if (target == parent->right)
					parent->right->data = value;
			}
		}
	}
};