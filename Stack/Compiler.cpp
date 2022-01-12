#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "AStack.hpp"
using namespace std;
map<char, int> value = {
    {'{', 2},
    {'}', -2},
    {'(', 1},
    {')', -1},
    {'<', 4},
    {'>', -4},
    {'[', -3},
    {']', -3}};
bool isPar(char c)
{
    return value.find(c) != value.end();
}
bool isOpen(char c)
{
    return isPar(c) && value[c] > 0;
}
bool isClose(char c)
{
    return isPar(c) && value[c] < 0;
}

void printError(int i)
{
    cout << "ERROR: At Line " << i << endl;
}
void compile(ifstream &source)
{
    string line;
    Stack<char> *par = new AStack<char>();
    int i;
    for (i = 1; getline(source, line); i++)
    {
        for (char c : line)
        {
            if (isPar(c))
            {
                if (par->length() > 0)
                {
                    if (value[par->topValue()] + value[c] == 0)
                    {
                        par->pop();
                    }
                    else
                    {
                        printError(i);
                        return;
                    }
                }
                else
                {
                    if (isOpen(c))
                    {
                        par->push(c);
                    }
                    else
                    {
                        printError(i);
                        return;
                    }
                }
            }
        }
    }
    if (par->length() > 0)
    {
        printError(i);
    }
}
int main(int argc, char *argv[])
{
    ifstream source(argv[1]);
    if (argc > 1)
    {
        compile(argv[1]);
    }
    source.close();
}