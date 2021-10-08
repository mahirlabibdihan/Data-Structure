#include "SNode.h"
using namespace std;
class SinglyLinkedList
{
	SNode* head;
public:
	SinglyLinkedList()
	{
		head = NULL;
	}
	/*void insert(SNode* head, int pos, int data)
	{
		SNode *i, *j = head;

		i = new SNode();

		i->data = data;

		if (pos == 1)
		{
			i->next = head;
			head = i;
		}

		else
		{	for (int k = 1; k < pos - 1; k++)
			{
				j = j->next;
			}

			i->next = j->next;
			j->next = i;
		}
	}

	void erase(SNode* head, int pos)
	{
		SNode *i, *j = head;

		if (pos == 1)
		{
			i = head;
			head = head->next;
		}

		else
		{	for (int k = 1; k < pos - 1; k++)
			{
				j = j->next;
			}

			i = j->next;
			j->next = i->next;
		}

		delete i;
	}*/

	void push_front(int data)
	{
		SNode *newNode = new SNode(data);
		newNode->next = head;
		head = newNode;
	}
	void push_back(int data)
	{
		SNode* temp;
		if(head == NULL)
		{
			head = new SNode(data);
		}
		else
		{
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new SNode(data);
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
