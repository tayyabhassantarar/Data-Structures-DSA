#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
	int * arr;
	int size;
	int top;
	
	Stack (int size)
	{
		this-> size= size;
		arr= new int [size];
		top=-1;
	}
	
	void push (int element)
	{
		if (size-top> 1)
		{
			top++;
			arr[top]=element;
		}
		else
		{
			cout << "stack overflow";
		}
	}
	void pop()
	{
		if (top>=0)
		{
			top--; 
		}
		else
		{
			cout << "Stack underflow";
		}
	}
	int peek ()
	{
		if (top>=0)
		{
			return arr[top];
		}
		else 
		{
			cout <<" Stack is empty ";
			return -1;
		}
	}
	bool isEmpty()
	{
		if (top==-1)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	
};

int main ()
{
	
	Stack s(5);
	
	s.push(5);	
	s.push(6);	
	s.push(9);	
	s.pop();
	
	
	cout <<" Peak is:"<<s.peek()<<endl;
	system ("pause");
	return 0;
}
