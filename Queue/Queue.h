// Local variables are stored on the Queue 
template<typename T>
class Queue
{
private:
    T* s;
    int currentSize;
public:
    Queue()
    {
        s = new T[0];
        currentSize = 0;
    }

    ~Queue()
    {
        delete[] s;
    }
};