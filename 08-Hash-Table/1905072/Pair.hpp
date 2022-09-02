#ifndef __PAIR__
#define __PAIR__
class Pair
{
    string k;
    int v;

public:
    Pair()
    {
        k = "";
        v = -1;
    }
    Pair(string k, int v)
    {
        this->k = k;
        this->v = v;
    }
    string key() const { return k; }
    void setKey(string k) { this->k = k; }
    int value() const { return v; }
    void setValue(int v) { this->v = v; }
};
#endif
