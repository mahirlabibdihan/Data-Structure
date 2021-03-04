#include<iostream>
#include<vector>
#include<initializer_list>
#include<iterator>
using namespace std;


template<typename T>
class Vector
{
private:
    T* arr = NULL;
    int Total_Capacity;
    int Current_Size;
public:
    static int iterator;
    Vector(int n)
    {
        arr = new T[n];
        Total_Capacity = n;
        Current_Size = n;
    }

    Vector()
    {
        arr = new T[0];
        Total_Capacity = 0;
        Current_Size = 0;
    }
    Vector(const Vector<T>& X)
    {
        arr = X.arr;
        Total_Capacity = X.Total_Capacity;
        Current_Size = X.Current_Size;
    }
    Vector(initializer_list<T> x)
    {
        int n = x.size(), i;
        arr = new T[n];
        typename initializer_list<T>::iterator itr;
        for (itr = x.begin(), i = 0; itr != x.end(); itr++, i++)
        {
            arr[i] = *itr;
        }
        Total_Capacity = n;
        Current_Size = n;
    }
    ~Vector()
    {
        delete[] arr;
    }
    int capacity()
    {
        return Total_Capacity;
    }
    int size()
    {
        return Current_Size;
    }
    T at(T index)
    {
        if (index < size())
        {
            return *(arr + index);
        }
        else
        {
            throw std::out_of_range("_M_range_check: __n (which is " + to_string(index) + ") >= this->size() (which is " + to_string(Current_Size) + ")");
        }

    }
    T operator[](T index)
    {
        return *(arr + index);
    }

    void operator=(Vector X)
    {
        this->arr = X.arr;
    }

    void push_back(T data)
    {
        if (Total_Capacity == Current_Size)
        {
            if (Total_Capacity)
            {
                T* temp = new T[2 * Total_Capacity];
                for (int i = 0; i < Total_Capacity; i++)
                {
                    temp[i] = arr[i];
                }
                delete[] arr;
                Total_Capacity *= 2;
                arr = temp;
            }
            else
            {
                T* temp = new T[1];
                delete[] arr;
                Total_Capacity++;
                arr = temp;
            }
            arr[Current_Size] = data;
            Current_Size++;
        }
    }
    void pop_back()
    {
        if (Current_Size) Current_Size--;
    }
    T* begin()
    {
        return arr;
    }
    T* end()
    {
        return arr + Current_Size;
    }
    bool empty()
    {
        return !Current_Size;
    }

    friend istream& operator>> (istream& is, Vector<T>& v)
    {
        for (auto& i : v)
        {
            is >> i;
        }
        return is;
    }

    friend ostream& operator<< (ostream& os, Vector<T>& v)
    {
        for (auto& i : v)
        {
            os << i << " ";
        }
        os << endl;
        return os;
    }
};




int main()
{
    Vector<int> x;
    Vector<int>::iterator ;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);

    Vector<int> y = {1, 2, 3, 4, 5};

    // cin>>y;
    cout << y;

    int z[10];
    return 0;

}
// vector::_M_range_check: __n (which is 10) >= this->size() (which is 5)