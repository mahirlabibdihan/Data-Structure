#include <iostream>
class DNode
{
public:
	int data;
	DNode *last, *next;
	DNode()
	{
		data = 0;
		last = next = NULL;
	}
	DNode(int data)
	{
		this->data = data;
		last = next = NULL;
	}
	DNode(const DNode& n)
	{
		this->data = n.data;
		last = next = NULL;
		if(n.last)
		{
			this->last = new DNode();
			*this->last = *n.last;
		}
		if(n.next)
		{
			this->next = new DNode();
			*this->next = *n.next;
		}
	}
	~DNode()
	{
		if(last) delete last;
		if(next) delete next;
	}
};
