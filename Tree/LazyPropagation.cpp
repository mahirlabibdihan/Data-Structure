// Program to show segment tree to demonstrate lazy
// propagation
#include <stdio.h>
#include <math.h>
#define MAX 1000

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff, int *tree, int *lazy)
{
	//cout<<si<<" "<<ss<<" "<<se<<endl;
	if (lazy[si] != 0)
	{
		tree[si] += (se - ss + 1) * lazy[si];
		if (ss != se)
		{
			lazy[si * 2 + 1] += lazy[si];
			lazy[si * 2 + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss >= us && se <= ue)
	{
		tree[si] += (se - ss + 1) * diff;
		if (ss != se)
		{
			lazy[si * 2 + 1] += diff;
			lazy[si * 2 + 2] += diff;
		}
		return;
	}
	if (ss > se || ss > ue || se < us)
	{
		return;
	}
	int mid = (ss + se) / 2;
	updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff, tree, lazy);
	updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff, tree, lazy);
	tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}
void updateRange(int n, int us, int ue, int diff, int *tree, int *lazy)
{
	updateRangeUtil(0, 0, n - 1, us, ue, diff, tree, lazy);
}
int getSumUtil(int ss, int se, int qs, int qe, int si, int *tree, int *lazy)
{
	if (lazy[si] != 0)
	{
		tree[si] += (se - ss + 1) * lazy[si];
		if (ss != se)
		{
			lazy[si * 2 + 1] += lazy[si];
			lazy[si * 2 + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss > se || ss > qe || se < qs)
	{
		return 0;
	}
	if (ss >= qs && se <= qe)
	{
		return tree[si];
	}
	int mid = (ss + se) / 2;
	return getSumUtil(ss, mid, qs, qe, 2 * si + 1, tree, lazy) +
		   getSumUtil(mid + 1, se, qs, qe, 2 * si + 2, tree, lazy);
}
int getSum(int n, int qs, int qe, int *tree, int *lazy)
{
	return getSumUtil(0, n - 1, qs, qe, 0, tree, lazy);
}
int get(int n, int q, int *tree, int *lazy)
{
	return getSum(n, q, q, tree, lazy);
}
void constructSTUtil(int arr[], int ss, int se, int si, int *tree, int *lazy)
{
	if (ss > se)
	{
		return;
	}
	if (ss == se)
	{
		tree[si] = arr[ss];
		return;
	}
	int mid = (ss + se) / 2;
	constructSTUtil(arr, ss, mid, si * 2 + 1, tree, lazy);
	constructSTUtil(arr, mid + 1, se, si * 2 + 2, tree, lazy);
	tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}
void constructST(int arr[], int n, int *tree, int *lazy)
{
	constructSTUtil(arr, 0, n - 1, 0, tree, lazy);
}
// Driver program to test above functions
int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	// Build segment tree from given array
	constructST(arr, n);

	// Print sum of values in array from index 1 to 3
	printf("Sum of values in given range = %d\n",
		   getSum(n, 1, 3));

	// Add 10 to all nodes at indexes from 1 to 5.
	updateRange(n, 1, 5, 10);

	// Find sum after the value is updated
	printf("Updated sum of values in given range = %d\n",
		   getSum(n, 1, 3));

	return 0;
}
