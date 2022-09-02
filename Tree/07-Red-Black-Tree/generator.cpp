#include <iostream>
using namespace std;
int main()
{
    freopen("input.in", "w", stdout);
    int n = 100000;
    // cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        int r = rand() % 4;
        int x = 1 + rand() % 1000001;
        cout << r << " " << x << endl;
    }
}