/*int main()
{
	int n=5;
	Heap* h=new Heap();
	
	h->root = new BNode(5);
	h->root->left = new BNode(3);
	h->root->right = new BNode(6);
	h->root->left->left = new BNode(1);
	h->root->left->right = new BNode(4);

	int *arr = h->toArray();
	cout<<"Array Representation of BT: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"->";
	}
	cout<<endl;	

	/*cout<<"Array Representation of Heap: ";
	// for (int i = (n / 2) - 1; i >= 0; i--)
		Heap::dfs(h->root);

	arr = h->toArray();
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"->";
	}
	cout<<endl;


	for (int i = n - 1; i > 0; i--)//Protibar root er sathey compare korbo..tai 0 bad
	{
		//move current root to end
		swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		Heap::maxHeapifyArray(arr, i, 0); //prev root takey bad diye heapify again.
	}*/
/*Heap::sort(arr,n);
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"->";
	}
}*/
class Comparable
{
public:
	static bool prior(int a, int b)
	{
		return a < b;
	}
};

#include "AHeap1.hpp"
#include <iostream>
using namespace std;
int main()
{
	int a[] = {5, 4, 3, 2, 5, 1};
	int n = sizeof(a) / sizeof(a[0]);
	heapsort<int, Comparable>(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}