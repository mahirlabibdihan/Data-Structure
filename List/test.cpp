#include "DLList.hpp"

int main()
{
    List<int> *lst = new DLList<int>();
    lst->append(10);
    cout << lst << endl;
}