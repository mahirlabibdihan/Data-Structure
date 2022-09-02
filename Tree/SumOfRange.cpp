#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int getMid(int s, int e) { return s + (e - s) / 2; }
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}
int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
    return getSumUtil(st, 0, n - 1, qs, qe, 0);
}
int constructSTUtil(vector<int> arr, int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}
int *constructST(vector<int> arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (2 << x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}
int main()
{
}