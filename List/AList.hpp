#ifndef __A_LIST__
#define __A_LIST__
#include <iostream>
#include "List.hpp"
using namespace std;

// Array list implementation
template <typename T>
class AList : public List<T>
{
private:
    static const int defaultSize = 10;
    int chunk;
    int maxSize;
    int listSize;
    int curr;
    T *listArray;
    void realloc(int size)
    {
        T *temp = new T[size];
        for (int i = 0; i < maxSize; i++)
        {
            temp[i] = listArray[i];
        }
        maxSize = size;
        delete[] listArray;
        listArray = temp;
    }
    void rightShift()
    {
        for (int i = listSize; i > curr; i--) // Shift elements up
        {
            listArray[i] = listArray[i - 1]; // to make room
        }
    }
    void leftShift()
    {
        for (int i = curr; i < listSize - 1; i++)
        {
            listArray[i] = listArray[i + 1];
        }
    }

public:
    AList(int maxSize = defaultSize)
    { // Constructor
        chunk = this->maxSize = maxSize;
        listSize = curr = 0;
        listArray = new T[maxSize];
    }
    AList(int *arr, int listSize, int maxSize = defaultSize)
    { // Constructor
        chunk = this->maxSize = maxSize;
        this->listSize = listSize;
        curr = 0;
        listArray = new T[maxSize];
        for (int i = 0; i < listSize; i++)
        {
            listArray[i] = arr[i];
        }
    }
    ~AList()
    {
        delete[] listArray;
    }
    void clear()
    {
        listSize = curr = 0;
    }
    void insert(const T &it)
    { // Insert "it" at current position
        if (listSize == maxSize)
        {
            // Reallocating memory to store more elements
            realloc(maxSize + chunk);
        }
        rightShift();
        listArray[curr] = it; // Inserting 'it'
        listSize++;           // Increment list size
    }
    void append(const T &it)
    { // Append "it"
        if (listSize == maxSize)
        {
            // Reallocating memory to store more elements
            realloc(maxSize + chunk);
        }
        listArray[listSize++] = it;
    }

    T remove()
    { // Remove and return the current element.
        if ((curr < 0) || (curr >= listSize))
        {
            cout << "No element" << endl;
            exit(-1);
        }
        T it = listArray[curr];
        leftShift();
        listSize--; // Decrement listSize

        // Stepping back 'curr'
        if (curr == listSize)
        {
            if (curr != 0)
            {
                curr--;
            }
        }
        return it;
    }
    void moveToStart()
    {
        curr = 0;
    }
    void moveToEnd()
    {
        curr = listSize - 1;
    }
    void prev()
    {
        if (curr == 0)
        {
            cout << "Already at first position" << endl;
            exit(-1);
        }
        curr--;
    }
    void next()
    {
        if (curr == listSize - 1)
        {
            cout << "Already at last position" << endl;
            exit(-1);
        }
        curr++;
    }
    int length() const
    {
        return listSize;
    }
    int currPos() const
    { // Return current position
        return curr;
    }
    void moveToPos(int pos)
    { // Set current list position to "pos"
        if ((pos < 0) || (pos >= listSize))
        {
            cout << "Pos out of range" << endl;
            exit(-1);
        }
        curr = pos;
    }
    const T &getValue() const
    { // Return current element
        if ((curr < 0) || (curr >= listSize))
        {
            cout << "No current element" << endl;
            exit(-1);
        }
        return listArray[curr];
    }
    int Search(const T &item) const
    { // Search for item in the list
        for (int i = 0; i < listSize; i++)
        {
            if (listArray[i] == item)
            {
                return i;
            }
        }
        return -1;
    }
};
#endif