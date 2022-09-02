#include <iostream>
using namespace std;

#include "RBT.hpp"
// Max depth = x
// Min depth = y
// x < 2y
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    RBT<int, int> *rbt = new RBT<int, int>();
    int n;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        int e, x;
        cin >> e >> x;
        cout << e << " " << x << " ";
        switch (e)
        {
        case 0: // Terminate - O(logn)
            cout << rbt->remove(x);
            break;
        case 1: // Initiate - O(logn)
            cout << rbt->insert(x, x);
            break;
        case 2: // Search - O(logn)
            cout << rbt->find(x);
            break;
        case 3: // Count - How to do it in O(logn)?
            // Inorder
            cout << rbt->lowerBound(x);
            break;
        default:
            cout << "ERROR: Invalid Command";
            return EXIT_FAILURE;
            break;
        }
        cout << endl;
    }
    // delete rbt;
}