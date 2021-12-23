// Reference: http://www.btechsmartclass.com/data_structures/single-linked-list.html
#ifndef __SLL__
#define __SLL__
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
	SNode* front()
	{
		return head;
	}
	SNode* at(int idx)
	{
		SNode *target = head;
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
	SNode* back()
	{
		SNode* temp = head;
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
		SNode* temp = head;
		int i;
		for (i = 0; temp->next != NULL; i++)
		{
			temp = temp->next;
		}
		return i;
	}
	/*
	Deletion:
	1. Deleting one and only node of the list
	2. Deleting from Beginning of the list
	3. Deleting from End of the list
	4. Deleting a Specific Node
	*/
	/*
	Deleting from Beginning of the list
	Step 1 - Check whether list is Empty 
	Step 2 - If it is Empty then, display 'List is Empty!!! Deletion is not possible' and terminate the function.
	Step 3 - If it is Not Empty then, define a Node pointer 'temp' and initialize with head.
	Step 4 - Check whether list is having only one node (temp → next == NULL)
	Step 5 - If it is TRUE then set head = NULL and delete temp 
	Step 6 - If it is FALSE then set head = temp → next, and delete temp.
	*/
	void pop_front()
	{
		if (empty())	// No nodes available
		{
			cout << "List is Empty.Deletion not possible." << endl;
		}
		else
		{
			SNode *target = head;

			if (target->next == NULL)	// List is having only one node ( first and last node of the list )
			{
				head = NULL;
				delete target;
			}
			else	// First node in the list
			{
				// Deleting from the Beginning
				head = target->next;
				delete target;
			}

		}
	}
	
	/*
	Deleting a Specific Node from the list
	Step 1 - Check whether list is Empty
	Step 2 - If it is Empty then, display 'List is Empty!!! Deletion is not possible' and terminate the function.
	Step 3 - If it is Not Empty then, define two Node pointers 'temp1' and 'temp2' and initialize 'temp1' with head.
	Step 4 - Keep moving the temp1 until it reaches to the exact node to be deleted or to the last node. And every time set 'temp2 = temp1' before moving the 'temp1' to its next node.
	Step 5 - If it is reached to the last node then display 'Given node not found in the list! Deletion not possible!!!'. And terminate the function.
	Step 6 - If it is reached to the exact node which we want to delete, then check whether list is having only one node or not
	Step 7 - If list has only one node and that is the node to be deleted, then set head = NULL and delete temp1.
	Step 8 - If list contains multiple nodes, then check whether temp1 is the first node in the list.
	Step 9 - If temp1 is the first node then move the head to the next node (head = head → next) and delete temp1.
	Step 10 - If temp1 is not first node then check whether it is last node in the list (temp1 → next == NULL).
	Step 11 - If temp1 is last node then set temp2 → next = NULL and delete temp1.
	Step 12 - If temp1 is not first node and not last node then set temp2 → next = temp1 → next and delete temp1.
	*/
	void erase(int idx)
	{
		if (empty())	// No nodes available
		{
			cout << "List is Empty.Deletion not possible." << endl;
		}
		else
		{
			SNode *target = head, *parent;
			// Finding the specific location
			for (int i = 0; i < idx; i++)
			{
				if (target->next == NULL)
				{
					cout << "Index out of range.Deletion not possible." << endl;
					return;
				}
				parent = target;
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
				delete target;
			}
			else if (target->next == NULL)	 // Last node in the list
			{
				// Deleting from the End
				parent->next = NULL;
				delete target;
			}
			else	// Deleting from the specific location
			{
				parent->next = target->next;
				delete target;
			}
		}
	}

	/*
	Deleting from End of the list
	Step 1 - Check whether list is Empty
	Step 2 - If it is Empty then, display 'List is Empty!!! Deletion is not possible' and terminate the function.
	Step 3 - If it is Not Empty then, define two Node pointers 'temp1' and 'temp2' and initialize 'temp1' with head.
	Step 4 - Check whether list has only one Node (temp1 → next == NULL)
	Step 5 - If it is TRUE. Then, set head = NULL and delete temp1. And terminate the function. (Setting Empty list condition)
	Step 6 - If it is FALSE. Then, set 'temp2 = temp1 ' and move temp1 to its next node. Repeat the same until it reaches to the last node in the list. (until temp1 → next == NULL)
	Step 7 - Finally, Set temp2 → next = NULL and delete temp1.
	*/
	void pop_back()
	{
		if (empty())	// No nodes available
		{
			cout << "List is Empty.Deletion not possible." << endl;
		}
		else
		{
			SNode *target = head, *parent;
			// Finding the end of the list
			while (target->next != NULL)
			{
				parent = target;
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
				parent->next = NULL;
				delete target;
			}
		}
	}

	/*
	Insertion:
	1. Inserting in empty list
	2. Inserting at the Beginning of the list
	3. Inserting at thet= End of the list
	4. Inserting at a Specific location
	*/
	/*
	Inserting At Beginning of the list
	Step 1 - Create a newNode with given value.
	Step 2 - Check whether list is Empty (head == NULL)
	Step 3 - If it is Empty then, set newNode→next = NULL and head = newNode.
	Step 4 - If it is Not Empty then, set newNode→next = head and head = newNode.
	*/
	void push_front(int data)
	{
		SNode *newNode = new SNode(data);
		if (empty())	// No nodes available
		{
			newNode->next = NULL;
			head = newNode;
		}
		else	// Inserting at the beginning
		{
			newNode->next = head;
			head = newNode;
		}
	}

	/*
	Inserting At Specific location in the list
	Step 1 - Create a newNode with given value.
	Step 2 - Check whether list is Empty (head == NULL)
	Step 3 - If it is Empty then, set newNode → next = NULL and head = newNode.
	Step 4 - If it is Not Empty then, define a node pointer temp and initialize with head.
	Step 5 - Keep moving the temp to its next node until it reaches to the node after which we want to insert the newNode (until temp1 → data is equal to location, here location is the node value after which we want to insert the newNode).
	Step 6 - Every time check whether temp is reached to last node or not. If it is reached to last node then display 'Given node is not found in the list!!! Insertion not possible!!!' and terminate the function. Otherwise move the temp to next node.
	Step 7 - Finally, Set 'newNode → next = temp → next' and 'temp → next = newNode'
	*/
	void insert(int idx, int data)
	{
		SNode *newNode = new SNode(data);
		if (empty())	// No nodes available
		{
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			SNode* temp = head;
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
				head = newNode;
			}
			else if (temp -> next == NULL)		// Inserting at the end
			{
				newNode -> next = NULL;
				temp->next = newNode;
			}
			else	// Inserting At Specific location
			{
				newNode -> next = temp -> next;
				temp->next = newNode;
			}
		}
	}

	/*
	Inserting At End of the list
	Step 1 - Create a newNode with given value and newNode → next as NULL.
	Step 2 - Check whether list is Empty (head == NULL).
	Step 3 - If it is Empty then, set head = newNode.
	Step 4 - If it is Not Empty then, define a node pointer temp and initialize with head.
	Step 5 - Keep moving the temp to its next node until it reaches to the last node in the list (until temp → next is equal to NULL).
	Step 6 - Set temp → next = newNode.
	*/
	void push_back(int data)
	{
		SNode *newNode = new SNode(data);

		if (empty())	// No nodes available
		{
			newNode->next = NULL;
			head = newNode;
		}
		else
		{
			// Finding the end of the list
			SNode* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			// Inserting at the end
			newNode->next = NULL;
			temp->next = newNode;
		}
	}
	void display()
	{
		if (empty())
		{
			cout << "List is Empty" << endl;
		}
		else
		{
			SNode *temp(head);
			while (temp->next != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << temp->data << endl;
		}
	}
};
#endif