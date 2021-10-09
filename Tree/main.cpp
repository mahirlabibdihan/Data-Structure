#include "BinarySearchTree.h"
int main()
{
	int n = 10;
	BST bst;
	while(n-->0)
	{
		int temp;
		cin>>temp;
		bst.insert(temp);
	}
	bst.inTraverse();
	bst.insert(90);
	bst.inTraverse();
	bst.erase(10);
	bst.inTraverse();
}
/*
2 4 4 8 10 12 12 45 56 312
*/