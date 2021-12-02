#include<bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *next, *last;
};


class singlelink
{
public:
  void insrt(node* x, int pos, int value)
  {
    node *i, *j = x;

    i = new node();

    i->data = value;

    if (pos == 1)
    {
      i->next = x;
      x = i;
    }

    else
    { for (int k = 1; k < pos - 1; k++)
      {
        j = j->next;
      }

      i->next = j->next;
      j->next = i;
    }


  }

  void dlt(node* x, int pos)
  {
    node *i, *j = x;

    if (pos == 1)
    {
      i = x;
      x = x->next;

    }

    else
    { for (int k = 1; k < pos - 1; k++)
      {
        j = j->next;
      }

      i = j->next;
      j->next = i->next;
    }

    delete i;
  }

  node* input(int n)
  {
    node *x = 0, *i, *j;
    while (n--)
    {
      i = new node();
      cin >> i->data;

      if (x)
      {
        j->next = i;
        j = i;
      }

      else x = j = i;
    }

    return x;
  }
};



class doublelink
{
public:
  void insrt(node* x, int pos, int value)
  {
    node *i, *j = x;

    i = new node();

    i->data = value;

    if (pos == 1)
    {
      i->next = x;
      i->last = 0;
      x = i;
    }

    else
    {
      for (int k = 1; k < pos - 1; k++)
      {
        j = j->next;
      }

      i->next = j->next;
      i->last = j;
      j->next = i;
    }


  }

  void dlt(node* x, int pos)
  {
    node *i, *j = x;

    if (pos == 1)
    {
      i = x;
      x = x->next;
      x->last = 0;
    }

    else
    { for (int k = 1; k < pos - 1; k++)
      {
        j = j->next;
      }

      i = j->next;
      j->next = i->next;
      i->next->last = j;
    }

    delete i;
  }

  node* input(int n)
  {
    node *x = 0, *i, *j;
    while (n--)
    {
      i = new node();

      cin >> i->data;

      if (x)
      {
        i->last = j;
        j->next = i;
        j = i;
      }

      else x = j = i;
    }

    return x;
  }

};


int main()
{
  int n, i, k, m; cin >> n;
}


