#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
protected:
	Node *head;
	Node *tail;
public:
	LinkedList();

	void insertatTail(int);
	void insertatHead(int);
	int deletefromHead();
	int deletefromTail();

	void display();

};
LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}