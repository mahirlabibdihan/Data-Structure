#include <iostream>
class DNode
{
public:
	int data;
	DNode *prev, *next;
	DNode(int data)
	{
		this->data = data;
		prev = next = NULL;
	}
};
