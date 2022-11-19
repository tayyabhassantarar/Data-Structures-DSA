#include <iostream>
using namespace std;
#define size 5
class Stack
{
private:
	
	int top;
	int arr[size];
public:
	Stack()  //default constructor
	{
		top = -1;
		for (int a = 0; a < size; a++)
		{
			arr[a] = 0;
		}
	}
	bool isEmpty()   //Empty check
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()    //Full stack check
	{
		if (top == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int value)       //Push values in the stack
	{
		if (isFull()) 
		{
			cout << "Stack Overflow!" << endl;
		}
		else
		{
			top++;
			arr[top] = value;
		}
	}
	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack Underflow! " << endl;
		}
		else
		{
			int PopValue = arr[top];
			arr[top] = 0;
			top--;
			return PopValue;
		}
	}
	void change(int position, int value)
	{
		arr[position] = value;
		

	}
	void display()
	{
		cout << "All values in stack are: "<<endl;
		for (int i = size-1; i >= 0; i--) 
		{
			cout << arr[i] << endl;
		}
	}
};
int main()
{
	Stack stkObj;
	
	while (1)
	{

		cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. Push()" << endl;
		cout << "2. Pop()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. isFull()" << endl;
		cout << "5. change()" << endl;
		cout << "6. display()" << endl;
		
		int option;
		cin >> option;
		if (option == 1)
		{
			int value;
			cout << "Enter the value you want to push: ";
			cin >> value;
			stkObj.push(value);
			system("cls");
		}
		else if (option == 2)
		{
			cout << "Popped function called! " << endl;
			stkObj.pop(); 
			system("cls");
		}
		else if (option == 3)
		{
			if (stkObj.isEmpty())
			{
				cout << "Stack is Empty" << endl;
			}
			else
			{
				cout << "Stack is not empty" << endl;
			}
			system("cls");
		}
		else if (option == 4)
		{
			if (stkObj.isFull())
			{
				cout << "Stack is Full" << endl;
			}
			else
			{
				cout << "Stack is not Full" << endl;
			}
			system("cls");
		}
		else if (option == 5)
		{
			int location, value;
			cout << "Enter the location where you want to change value: ";
			cin >> location;
			cout << "Enter the value: ";
			cin >> value;
			stkObj.change(location, value);

		}


		else if (option == 6)
		{
			cout << "\t\t<--- Display --->" << endl;
			stkObj.display();
			
		}

	}
	system("pause");
	return 0;
}
