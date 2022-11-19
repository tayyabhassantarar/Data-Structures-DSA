#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

void insertAtHead(Node* & head, int data)
{
	Node *temp = new Node(data);
	temp->next = head;
	head->prev = temp;
	head = temp;
}

void insertAtTail(Node* tail, int data)
{
	Node* temp = new Node(data);
	tail->next = temp;
	temp->prev = tail;
	tail = temp;
}
void insertAtPosition(Node* &head, int position, int data)
{
	Node *newNode = new Node(data);
	Node* temp = head;
	if (position == 1)
	{
		insertAtHead(head, data);
	}
	else
	{
		newNode->next = temp->next;
		temp->next->prev = newNode;
		temp->next = newNode;
		newNode->prev = temp;
	}
}

void deleteAtHead(Node* &head)
{
	Node* temp = head;
	temp->next->prev = NULL;
	head = temp->next;
	temp->next = NULL;
	
	delete temp;
}
void display(Node *& head, Node *& tail)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node *NewNode = new Node(20);
	Node* head = NewNode;
	Node* tail = NewNode;

	insertAtHead(head, 15);
	insertAtHead(head, 10);
	insertAtHead(head, 5);

	insertAtTail(tail, 50);



	insertAtPosition(head, 2, 4);
	display(head,tail);

	deleteAtHead(head);
	system("pause");
	return 0;

}