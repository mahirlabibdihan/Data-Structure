#include "DLList.hpp"
#include "../Graph/Edge.hpp"
int main()
{
    for (int i = 0; i < 100; i++)
    {
        try
        {
            new DLList<Edge>();
        }
        catch (std::bad_alloc &ba)
        {
            std::cerr << "bad_alloc caught: " << ba.what();
        }
    }
}