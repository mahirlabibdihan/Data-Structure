#ifndef __LIST__
#define __LIST__
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
template <typename E>
class List
{
private:
    void operator=(const List &) {} // Protect assignment
    List(const List &) {}           // Protect copy constructor
public:
    List() {}
    virtual ~List() {}
    virtual void clear() = 0;
    virtual void insert(const E &item) = 0;
    virtual void append(const E &item) = 0;
    virtual E remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() const = 0;
    virtual int currPos() const = 0;
    virtual void moveToPos(int pos) = 0;
    virtual const E &getValue() const = 0;
    virtual int find(const E &item) const = 0;
};

template <typename E>
ostream &operator<<(ostream &os, List<E> *lst)
{
    int curr = lst->currPos();
    os << "<";
    if (lst->length() > 0)
    {
        for (lst->moveToStart();; lst->next())
        {
            if (lst->currPos() == curr)
            {
                os << "| ";
            }
            os << lst->getValue() << ' ';

            if (lst->currPos() + 1 == lst->length())
            {
                break;
            }
        }
        lst->moveToPos(curr);
    }
    os << ">";
    return os;
}
#endif