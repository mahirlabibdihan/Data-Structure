#include <iostream>
using namespace std;

template <typename E>
class Operand
{
    E value;

public:
    Operand()
    {
        value = 0;
    }
    Operand(const Operand<E> &var)
    {
        value = var.value;
    }
    Operand(const E &n)
    {
        value = n;
    }
    template <typename T>
    friend ostream &operator<<(ostream &os, const Operand<T> &opnd);
};
template <typename T>
ostream &operator<<(ostream &os, const Operand<T> &opnd)
{
    os << opnd.value;
    return os;
}