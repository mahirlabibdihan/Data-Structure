#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
    T* s;
    int currentSize;
public:
    Stack()
    {
        s = new T[0];
        currentSize = 0;
    }
    ~Stack()
    {
        delete[] s;
    }
    int size()
    {
        return currentSize;
    }
    
    // Push a character
    void push(T c)
    {
        T* temp = new T[++currentSize];
        for (int i = 0; i < currentSize - 1 ; i++)
        {
            temp[i] = s[i];
        }
        delete[] s;
        s = temp;
        s[currentSize - 1] = c;
    }

    // Pop a character
    T pop()
    {
        if (currentSize == 0)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            return s[--currentSize];
        }
    }

    T top()
    {
        if (currentSize == 0)
        {
            cout << "Stack is empty" << endl;
            return 0; // return null on empty stack
        }
        return s[currentSize - 1];
    }
    bool empty()
    {
        return currentSize == 0;
    }


};

int main(void)
{
    Stack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    while (!s1.empty())
    {
        cout << "Pop stack : " <<  s1.pop() << endl;
    }
    return 0;
}
