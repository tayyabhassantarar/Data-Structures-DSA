#include "myLinkedList.h"

int main()
{
	LinkedList obj;

	obj.insertatTail(15);
	obj.insertatTail(30);
	obj.insertatTail(45);

	obj.insertatHead(12);
	obj.insertatHead(13);


//		cout <<"Delete from Head: "<< obj.deletefromHead();



	
	cout <<"Delete from tail: "<< obj.deletefromTail();


	obj.display();

	system("pause");
	return 0;
}