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
	DNode* front()
	{
		return head;
	}
	DNode* at(int idx)
	{
		DNode *target = head;
		// Finding the specific location
		for (int i = 0; i < idx; i++)
		{
			if (target->next == NULL)
			{
				cout << "Index out of range." << endl;
				return NULL;
			}
			target = target->next;
		}
		return target;
	}
	DNode* back()
	{
		DNode* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp;
	}
	bool empty()
	{
		return head == NULL;
	}
	size_t size()
	{
		DNode* temp = head;
		int i;
		for (i = 0; temp->next != NULL; i++)
		{
			temp = temp->next;
		}
		return i;
	}
	void pop_front()
	{
		if (empty())	// No nodes available
		{
			cout << "List is Empty.Deletion not possible." << endl;
		}
		else
		{
			DNode *target = head;

			if (target->next == NULL)	// List is having only one node ( first and last node of the list )
			{
				head = NULL;
				delete target;
			}
			else	// First node in the list
			{
				// Deleting from the Beginning
				head = target->next;
				target->next->prev = NULL;
				delete target;
			}

		}
	}
	void erase(int idx)
	{
		if (empty())	// No nodes available
		{
			cout << "List is Empty.Deletion not possible." << endl;
		}
		else
		{
			DNode *target = head;
			// Finding the specific location
			for (int i = 0; i < idx; i++)
			{
				if (target->next == NULL)
				{
					cout << "Index out of range.Deletion not possible." << endl;
					return;
				}
				target = target->next;
			}
			if (target == head && target->next == NULL)		// List is having only one node
			{
				head = NULL;
				delete target;
			}
			else if (target == head)	// First node in the list
			{
				// Deleting from the beginning
				head = target->next;
				target->next->prev = NULL;
				delete target;
			}
			else if (target->next == NULL)	 // Last node in the list
			{
				// Deleting from the End
				target->prev->next = NULL;
				delete target;
			}
			else	// Deleting from the specific location
			{
				target->prev->next = target->next;
				target->next->prev = target->prev;
				delete target;
			}
		}
	}

	void pop_back()
	{
		if (empty())	// No nodes available
		{
			cout << "List is Empty.Deletion not possible." << endl;
		}
		else
		{
			DNode *target = head;
			// Finding the end of the list
			while (target->next != NULL)
			{
				target = target->next;
			}
			if (target == head)	// List is having only one node ( Last and first node of the list )
			{
				head = NULL;
				delete target;
			}
			else	// Last node in the list
			{
				// Deleting from the End
				target->prev->next = NULL;
				delete target;
			}
		}
	}

	void push_front(int data)
	{
		DNode *newNode = new DNode(data);
		if (empty())	// No nodes available
		{
			newNode->next = newNode->prev = NULL;
			head = newNode;
		}
		else	// Inserting at the beginning
		{
			newNode->next = head;
			newNode->prev = NULL;
			head->prev = newNode;
			head = newNode;
		}
	}
	void insert(int idx, int data)
	{
		DNode *newNode = new DNode(data);
		if (empty())	// No nodes available
		{
			newNode->next = newNode->prev = NULL;
			head = newNode;
		}
		else
		{
			DNode* temp = head;
			// Finding the specific location
			for (int i = 0; i < idx - 1; i++)
			{
				if (temp->next == NULL)
				{
					cout << "Index out of range.Insertion not possible." << endl;
					return;
				}
				temp = temp->next;
			}
			if (temp == head)	// Inserting at the beginning
			{
				newNode->next = head;
				newNode->prev = NULL;
				head->prev = newNode;
				head = newNode;
			}
			else if (temp -> next == NULL)		// Inserting at the end
			{
				newNode->next = NULL;
				newNode->prev = temp;
				temp->next = newNode;
			}
			else	// Inserting At Specific location
			{
				newNode->next = temp->next;
				newNode->prev = temp;

				temp->next->prev = newNode;
				temp->next = newNode;
			}
		}
	}
	void push_back(int data)
	{
		DNode *newNode = new DNode(data);

		if (empty())	// No nodes available
		{
			newNode->next = newNode->prev = NULL;
			head = newNode;
		}
		else
		{
			// Finding the end of the list
			DNode* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			// Inserting at the end
			newNode->next = NULL;
			newNode->prev = temp;
			temp->next = newNode;
		}
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "List is Empty" << endl;
		}
		else
		{
			DNode *temp(head);
			while (temp->next != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data << endl;
		}
	}
};
