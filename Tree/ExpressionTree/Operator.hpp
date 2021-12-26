class Operator
{
    char sign;

public:
    Operator()
    {
        sign = '\0';
    }
    Operator(const Operator &op)
    {
        sign = op.sign;
    }
    Operator(const char &c)
    {
        sign = c;
    }
    bool operator==(const char &c)
    {
        return sign == c;
    }
    friend ostream &operator<<(ostream &os, const Operator &n);
};
ostream &operator<<(ostream &os, const Operator &op)
{
    os << op.sign;
    return os;
}