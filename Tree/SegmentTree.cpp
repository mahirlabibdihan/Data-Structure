// C++ program to show segment tree operations like construction, query
// and update
#include <bits/stdc++.h>
using namespace std;

#define left_child(v) v << 1
#define right_child(v) (v << 1) ^ 1

class SegmentTree
{
private:
    vector<int> tree; // May change based on what we are storing

    int combine(int a, int b) // May change
    {
        return a + b;
    }

    void build(const vector<int> &a, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = a[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(a, left_child(node), start, mid);
            build(a, right_child(node), mid + 1, end);
            tree[node] = combine(tree[left_child(node)], tree[right_child(node)]);
        }
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(left_child(node), start, mid, idx, val);
            else
                update(right_child(node), mid + 1, end, idx, val);
            tree[node] = combine(tree[left_child(node)], tree[right_child(node)]);
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == start && r == end)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return combine(query(left_child(node), start, mid, l, min(r, mid)), query(right_child(node), mid + 1, end, max(l, mid + 1), r));
    }

public:
    int n;
    SegmentTree(vector<int> &nums)
    {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void update(int idx, int incr)
    {
        update(1, 0, n - 1, idx, incr);
    }

    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int getMid(int s, int e) { return s + (e - s) / 2; }
int getSumUtil(vector<int> &st, int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}

void updateValueUtil(vector<int> &st, int ss, int se, int i, int diff, int si)
{
    if (i < ss || i > se)
        return;
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
        updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}
void updateValue(vector<int> &arr, vector<int> &st, int n, int i, int new_val)
{
    if (i < 0 || i > n - 1)
    {
        cout << "Invalid Input";
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n - 1, i, diff, 0);
}
int getSum(vector<int> &st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        // cout << "Invalid Input";
        return -1;
    }

    return getSumUtil(st, 0, n - 1, qs, qe, 0);
}
int constructSTUtil(vector<int> &arr, int ss, int se, vector<int> &st, int si)
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

vector<int> constructST(vector<int> arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    vector<int> st(max_size);
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}
// Driver program to test above functions
int main()
{
    // int arr[] = {1, 3, 5, 7, 9, 11};
    // int n = sizeof(arr) / sizeof(arr[0]);

    int n = 15;
    // Build segment tree from given array
    vector<int>
        arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    vector<int> st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    cout << "Sum of values in given range = " << getSum(st, n, 1, 3) << endl;

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr, st, n, 1, 10);

    // Find sum after the value is updated
    cout << "Updated sum of values in given range = "
         << getSum(st, n, 1, 3) << endl;
    return 0;
}
// This code is contributed by rathbhupendra