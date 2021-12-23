#include "BinarySearchTree.h" 
int main()
{
	int n = 5;
	BST bst;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		bst.insert(temp);
	}
	int *arr = bst.toArray();
	cout << "Array Representation of BST: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "->";
	}
	cout << endl;

	cout << "Array Representation of Heap: ";
	for (int i = (n / 2) - 1; i >= 0; i--)
		BST::heapify(arr, n, i);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "->";
	}
	cout << endl;

	for (int i = n - 1; i > 0; i--) //Protibar root er sathey compare korbo..tai 0 bad
	{
		//move current root to end
		swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		BST::heapify(arr, i, 0); //prev root takey bad diye heapify again.
	}

	cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "->";
	}
}
/*
4 2 1 3 5
*/