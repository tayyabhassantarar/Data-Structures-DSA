#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}

};
void insertAtHead(Node* &head,int data)
{
	Node *newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}

void insertAtTail(Node* &tail, int data)
{
	Node *TailNode = new Node(data);
	tail->next = TailNode;
	tail = TailNode;
}

void insertatPosition(Node* &head, Node* &tail, int position, int data)
{
	Node *temp = head;
	int cnt = 1;
	while (cnt < position - 1)
	{
		temp = temp->next;
		cnt++;
	}
	if (temp->next = NULL)
	{
		insertAtTail(tail, data);
	}
	Node *nNode = new Node(data);
	nNode->next = temp->next;
	temp->next = nNode;
}
void deleteNode(Node* &head, int position)
{
	if (position == 1)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Node *curr = head;
		Node *prev = NULL;
		int cnt = 1;
		while (cnt < position)
		{
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}

void display(Node* &head)
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
	Node *Nodeobj = new Node(20);
//	cout << "Origional Node: "<<Nodeobj->data << " " << endl;

	Node *head = Nodeobj;
	Node *tail = Nodeobj;

	/*
	cout << "\nInsertions at Head: ";
	insertAtHead(head,10);
	insertAtHead(head,20);
	*/
//	cout << "\n\nInsertions at tail: ";
	insertAtTail(tail, 40);
	insertAtTail(tail, 60);

//	cout << "\nInsertions at N- Place (Node): ";
//	insertatPosition(head,tail,2,93);

	deleteNode(head, 1);

	display(head);
	cout << endl;
	system("pause");
	return 0;
}

