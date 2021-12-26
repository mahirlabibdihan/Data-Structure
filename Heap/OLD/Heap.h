// Global variables are stored on the heap

// Heap is almost complete binary tree. All the level except the last one is fully filled.
// 2^(h-1)<n<=2^h


#include "BinaryTree.h"
class Heap:public BinaryTree
{
public:
	static void heapifyNode(BNode* root)
	{
		BNode* largest = root; //initialize root as largest element
		BNode* left = root->left; //left child
		BNode* right = root->right; //right child
		// If left child is larger than root
		if (left != NULL)
		{
			if(left->data > largest->data)
			{
				largest = left;
			}
		}
		// If right child is larger than largest so far
		if (right !=NULL)
		{
			if(right->data > largest->data)
			{
				largest = right;
			}
		}

		if (largest != root) //largest elemnt jodi root na hoy..
		{
			swap(largest->data, root->data); //swap korey dibo
			heapifyNode(largest); //recursively heapify
		}
	}

	static void heapify(BNode* root)
	{
		// If a node doesn't have left or right child,then it's a leaf. Otherwise it's non-leaf
		if(root!=NULL)
		{
			if(root->left == NULL && root->right == NULL) return;  // Leaf
			heapify(root->left);
			heapifyNode(root);	// called heapify on all the non-leaf elements of the heap
			heapify(root->right);		
		}
	}

	static void heapifyArray(int* arr,int n, int root)
	{
		int largest = root; //initialize root as largest element
		int left = 2 * root + 1; //left child
		int right = 2 * root + 2; //right child
		// If left child is larger than root
		if (left < n)
		{
			if(arr[left] > arr[largest])
			{
				largest = left;
			}			
		}
		// If right child is larger than largest so far
		if (right < n)
		{
			if(arr[right] > arr[largest])
			{
				largest = right;
			}	
		}

		if (largest != root) //largest elemnt jodi root na hoy..
		{
			swap(arr[largest], arr[root]); //swap korey dibo
			heapifyArray(arr, n, largest); //recursively heapify
		}
	}

	// To heapify the whole tree we need to heapify all the non-leaf elements. From bottom to root.
	static void heapify(int *arr,int n, int i)
	{
		// Recursive
		/*int root = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if(i<n)
		{
			if(left >= n && right >= n) return;  // Leaf
			heapify(arr,n,left);		
			heapifyArray(arr,n,root);	// called heapify on all the non-leaf elements of the heap
			heapify(arr,n,right);		
		}*/

		// Iterative	 
		// In array representation,	0th to (n/2)-1 th elements are non-leaf elements
		for (int i = (n / 2) - 1; i >= 0; i--)
		{
			heapifyArray(arr, n, i);
		}
	}

	static void sort(int* arr,int n)
	{
		heapify(arr,n,0);
		// We will delete the root of the heap, until the heap is empty.
		// So we will delete the maximum element of the heap everytime
		for (int i = n - 1; i > 0; i--)
		{
			swap(arr[0], arr[i]);		// move current root to end
			heapifyArray(arr, i, 0);	// call max heapify on the reduced heap
		}
	}
};