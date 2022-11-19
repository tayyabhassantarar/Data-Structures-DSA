#include "LinkedListfunctions.h"

void LinkedList::insertatTail(int value)
{
	Node *newNode = new Node;     // General syntax to create new Node with Null ptr at its address
	newNode->data = value; 
	newNode->next = nullptr;

	if (head == nullptr && tail == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}

}

void LinkedList::insertatHead(int value)
{
	Node * newNode = new Node;   // General syntax to create new Node with Null ptr at its address
	newNode->data = value;
	newNode->next = nullptr;

	if (head == nullptr && tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

int LinkedList::deletefromHead()
{
	if (head == nullptr && tail == nullptr) //for no Node case
	{
		cout << "\nLinked List is empty" << endl;
		return NULL;
	}

	else if (head == tail)   //single Node case
	{
		int shiftdata = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return shiftdata;
	}

	else   // For multiple Nodes case
	{
		Node *temp = head;
		head = head->next;
		int shiftdata = head->data;
		delete temp;
		temp = nullptr;
		return shiftdata;
	}
}

int LinkedList::deletefromTail()
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "\nEmpty Linked list\n";
	}

	else if (head = tail)
	{
		int shiftdata = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
		return shiftdata;
	}
	else
	{
		Node *temp = head;

		while (1)   // loop to shift pointer at last Node
		{
			if (temp->next == tail)   //if next is already at tail
			{
				break;
			}
			else
			{
				temp = temp->next;   // move next pointer to the last Node
			}
		}
		int shiftdata = tail->data;
		delete tail;
		tail = temp;
		temp->next = nullptr;
		return shiftdata;
	}
}


void LinkedList::display()   //Display function
{
	if (head == nullptr && tail == nullptr)
	{
		cout << "\nLinked List is empty!!" << endl;
	}
	else
	{
		Node *temp = head;
		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;

			if (temp == nullptr)
			{
				break;
			}
		}
	}
}