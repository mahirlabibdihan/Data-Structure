#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next,*last;
};

class bnode
{
public:
    int data;
    bnode *left,*right;
};

void display(node* a)
{
    node *j=a;
       while(j)
    {
        cout<<j->data<<" ";
        j=j->next;
    }
    cout<<endl;
}



class singlelink
{
public:
void insrt(node* x,int pos,int value)
{
    node *i,*j=x;

    i=new node();

    i->data=value;

    if(pos==1)
    {
        i->next=x;
        x=i;
    }

    else
    {for(int k=1;k<pos-1;k++)
    {
        j=j->next;
    }

    i->next=j->next;
    j->next=i;
    }


}

void dlt(node* x,int pos)
{
    node *i,*j=x;

    if(pos==1)
    {
        i=x;
        x=x->next;

    }

    else
    {for(int k=1;k<pos-1;k++)
    {
        j=j->next;
    }

    i=j->next;
    j->next=i->next;
    }

    delete i;
}

node* input(int n)
{
    node *x=0,*i,*j;
    while(n--)
    {
      i=new node();
     cin>>i->data;

      if(x)
      {
          j->next=i;
          j=i;
      }

       else x=j=i;
    }

    return x;
}
};



class doublelink
{
public:
void insrt(node* x,int pos,int value)
{
    node *i,*j=x;

    i=new node();

    i->data=value;

    if(pos==1)
    {
        i->next=x;
        i->last=0;
        x=i;
    }

    else
    {for(int k=1;k<pos-1;k++)
    {
        j=j->next;
    }

    i->next=j->next;
    i->last=j;
    j->next=i;
    }


}

void dlt(node* x,int pos)
{
    node *i,*j=x;

    if(pos==1)
    {
        i=x;
        x=x->next;
        x->last=0;

    }

    else
    {for(int k=1;k<pos-1;k++)
    {
        j=j->next;
    }

    i=j->next;
    j->next=i->next;
    i->next->last=j;
    }

    delete i;
}

node* input(int n)
{
  node *x=0,*i,*j;
   while(n--)
    {
      i=new node();

      cin>>i->data;

      if(x)
      {
          i->last=j;
          j->next=i;
          j=i;
      }

       else x=j=i;
    }

    return x;
}


bnode* bst(bnode* x,int m)
{
    bnode *i,*j;
    if(x)
      {i=x;
         while(i)
         {
             if(m<i->data)
             {
                 j=i;
                 i=i->left;
             }

             else
             {
                 j=i;
                 i=i->right;
             }
         }

         i=new bnode();
         i->data=m;
         if(m<j->data) j->left=i;
         else j->right=i;
      }
      else
      {
          x=new bnode();
          x->data=m;
      }
    return x;
}


void bst_asc(bnode* j)
{
    if(j)
    {bst_asc(j->left);
    cout<<j->data<<" ";
    bst_asc(j->right);}
    else return;
}

void bst_dsc(bnode* j)
{
    if(j)
    {bst_dsc(j->right);
    cout<<j->data<<" ";
    bst_dsc(j->left);}
    else return;
}

};


int main()
{
    int n,i,k,m; cin>>n;

    doublelink y;
    bnode *x=0;

    for(k=0;k<n;k++)
    {
        cin>>m;
        x=y.bst(x,m);
    }

    y.bst_dsc(x);cout<<endl;
    y.bst_asc(x);cout<<endl;
}


