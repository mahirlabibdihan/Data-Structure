#include <iostream>
class SNode
{
public:
	int data;
	SNode *next;
	SNode()
	{
		data = 0;
		next = NULL;
	}
	SNode(int data)
	{
		this->data = data;
		next = NULL;
	}
	SNode(const SNode& n)
	{
		this->data = n.data;
		next = NULL;
		if(n.next)
		{
			this->next = new SNode();
			*this->next = *n.next;
		}
	}
	~SNode()
	{
		if(next) delete next;
	}
};
