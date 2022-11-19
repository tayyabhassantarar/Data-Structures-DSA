#include <iostream>
using namespace std;

int factorial(int n)
{
	// firstly write a base case
	if (n == 0)
	{
		return 1;
	}
	else
	{
		int smallerproblem = factorial(n - 1);
		int largerproblem = n* smallerproblem;
		return largerproblem;
	}
}
int power(int n)
{
	// firstly write a base case
	if (n == 0)
	{
		return 1;
	}
	else
	{
		int smallerproblem = power(n - 1);
		
		int largerproblem = 3 * smallerproblem; // find power for base 3
		return largerproblem;
	}
}
int counting(int n)
{
	// firstly write a base case
	if (n == 0)
	{
		return ;
	}
	else
		cout << n << " ";
	{
		cout << counting(n - 1) << " ";
	}
	
}
int main()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;

	int factAns= factorial(n);
	cout << "Factorial of number:"<< factAns << endl;

	int powerAns = power(n);
	cout << "Power of number:" << powerAns << endl;

	cout << "Counting of number:" << counting(n)<< endl;

	system("pause");
	return 0;
}