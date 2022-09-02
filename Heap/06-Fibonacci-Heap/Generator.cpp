#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    freopen("test_1_graph.in", "w", stdout);
    int n = 8000;
    int m = n * (n - 1) / 2;
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << i << " " << j << " " << rand() % 1000000000 << endl;
        }
    }
}