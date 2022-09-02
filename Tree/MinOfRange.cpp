#include <climits>
#include <cmath>
using namespace std;
int getMid(int s, int e) { return s + (e - s) / 2; }
int RMQUtil(int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return min(RMQUtil(ss, mid, qs, qe, 2 * index + 1),
               RMQUtil(mid + 1, se, qs, qe, 2 * index + 2));
}
int RMQ(int n, int qs, int qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
    return RMQUtil(0, n - 1, qs, qe, 0);
}
int constructSTUtil(int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = a[ss];
        return a[ss];
    }
    int mid = getMid(ss, se);
    st[si] = min(constructSTUtil(ss, mid, st, si * 2 + 1),
                 constructSTUtil(mid + 1, se, st, si * 2 + 2));
    return st[si];
}
int *constructST(int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(0, n - 1, st, 0);
    return st;
}