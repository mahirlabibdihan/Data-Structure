// Reference: http://www.btechsmartclass.com/data_structures/double-linked-list.html
#include "DNode.h"
using namespace std;
class DLL
{
	DNode* head;
public:
	DLL()
	{
		head = NULL;
	}
	void push_front(int data)
	{
		DNode *newNode = new DNode(data);
		newNode->next = head;
		head = newNode;
	}
	void push_back(int data)
	{
		DNode *newNode = new DNode(data);
		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			DNode* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
	void display()
	{
		if (head == NULL)
		{
			cout<<"List is Empty"<<endl;
		}
		else
		{
			DNode *temp(head);
			while (temp->next != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<temp->data<<endl;
		}	
	}
};
