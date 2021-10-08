template<typename T>
class stack
{
private:
    T* s;
    int currentSize;
public:
    stack()
    {
        s = new T[0];
        currentSize = 0;
    }

    ~stack()
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
            throw "stack is empty";
        }
        return s[--currentSize];
    }

    T top()
    {
        if (currentSize == 0)
        {
            throw "stack is empty";
        }
        return s[currentSize - 1];
    }

    bool empty()
    {
        return currentSize == 0;
    }

};