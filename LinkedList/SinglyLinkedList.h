// Reference: http://www.btechsmartclass.com/data_structures/single-linked-list.html
#include "SNode.h"
using namespace std;
class SLL
{
	SNode* head;
public:
	SLL()
	{
		head = NULL;
	}
	void erase(int idx)
	{
		if(head != NULL)
		{
			SNode *temp1 = head, *temp2;
			for(int i=0;i<idx;i++)
			{
				if(temp1->next == NULL)
				{
					cout<<"Index out of range"<<endl;
					return;
				}
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = temp1->next;
			delete temp1;
		}
	}
	void push_front(int data)
	{
		SNode *newNode = new SNode(data);
		newNode->next = head;
		head = newNode;
	}
	void insert(int idx, int data)
	{
		SNode *newNode = new SNode(data);
		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			SNode* temp = head;
			for(int i=0;i<idx-1;i++)
			{
				if(temp->next == NULL)
				{
					cout<<"Index out of range"<<endl;
					return;
				}
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void push_back(int data) 
	{
		SNode *newNode = new SNode(data);
		if(head == NULL)
		{
			head = newNode;
		}
		else
		{
			SNode* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
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
			SNode *temp(head);
			while (temp->next != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<temp->data<<endl;
		}	
	}
};
