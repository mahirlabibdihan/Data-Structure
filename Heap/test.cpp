#include "LHeap.hpp"
class Comparable
{
public:
    static bool prior(int a, int b)
    {
        return a > b;
    }
};
int main()
{
    LHeap<int, Comparable> *h = new LHeap<int, Comparable>();
    h->insert(10);
    cout << h << endl;
    h->insert(1);
    cout << h << endl;
    h->insert(23);
    cout << h << endl;
    h->insert(4);
    cout << h << endl;
    h->insert(3);
    cout << h << endl;
    h->insert(11);
    cout << h << endl;
    h->removeFirst();
    cout << h << endl;
}