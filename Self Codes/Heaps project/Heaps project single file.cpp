#include <iostream>
using namespace std;

/*
<-- Theoretical concepts -->

~ Heap is a data-structure, in which complete Binary Tree (CBT) comes with "Heap Order Property"
~ Every level is completely filled except last level/ leaf nodes
~ Heap Order Property has "Max-Heap" and "Min-Heap"
~ In 'Max-Heap', every child node value is less than parent Node value
~ In 'Min-Heap', every child node value is greater than parent Node value
~ Indexes are started from left node to right node, in particular levels of nodes: 1 -> 2 -> 3 -> 4 .....
~ Heapify: a function that place a node at a right place 

NOTE: I use index size from 1, not from 0, as it is more convenient in insertion, deletion, and in heapify concepts

*/

class Heap    //Making the class for heap
{
public:
	int arr[100];
	int size = 0;

	Heap()              // Default constructor
	{
		arr[0] = -1;   // -1 is the assumed value for index 0
		size = 0;
	}

	void origionalTree()       // Just printing input Tree for greater clearity
	{
		int arr[5] = { 50, 55, 53, 52, 54 };
		cout << "\n\t -> Origional Tree given is: ";
		for (int a = 0; a < 5; a++)
		{
			cout << arr[a] << " ";
		}
	}

	void insert(int value)    //insertion in heap       (  O(LOG N)  )
	{
		size = size + 1;  // move to index 1
		int index = size;      //pointing leaf node  ( here the leaf node is assumed also as a root node
		arr[index] = value;   //place value at above node

		while (index > 1)      
		{
			int parent = index / 2;			// for BST case, where always two child nodes exists

			if (arr[parent] < arr[index])    //agar parent ki value child se choti ho gi to yeh swap kare ga..! SORRY please
			{
				swap(arr[parent], arr[index]);     
				index = parent;
			}
			else
			{
				return;
			}
		}
	}

//  --> Method# 1 for deletion ->

	void deletefromheap()
	{
		if (size = 0)      // No index case
		{
			cout << "Nothing to delete!!" << endl;
			return;
		}
		arr[1] = arr[size];         //  pointing/putting last element to root(1st index) node
		size--;						//  removing last element	 

		// Now take the root node at its exact position
		int index = 1;
		while (index <= size)
		{
			int leftindex = 2 * index;				  //Assuming indexes are starting from 1
			int rightindex = (2 * index) + 1;			
			int nextindex = index;

			// Implementing conditions for left and right side

			if (leftindex < size && arr[nextindex] < arr[leftindex])			// LEFT condition
			{
				nextindex = leftindex;
			}
			else if (rightindex < size && arr[nextindex] < arr[rightindex])		// RIGHT condition
			{
				nextindex = rightindex;
			}
			else if (nextindex == index)			// BOTH INDEX AT SAME condition
			{
				break;
			}
			else
			{
				swap(arr[nextindex], arr[index]);
				index = nextindex;
			}
			
		}
	}

/*

	--> Method# 2 for deletion ->

	void deletefromheap()
	{
		if (size = 0)
		{
			cout << "Nothing to delete!!" << endl;
			return;
		}
		arr[1] = arr[size];    //  pointing/putting last element to root(1st index) node
		size--;						//removing last element

		// Now take the root node at its exact position
		int i = 1;
		while (i < size)
		{
			int leftindex = i * 2;  //Assuming indexes are starting from 1
			int rightindex = i * 2 + 1;

			// Implementing conditions for left and right side
			if (leftindex < size && arr[i] < arr[leftindex])
			{
				swap(arr[i], arr[leftindex]);
				i = leftindex;
			}
			else if (rightindex < size && arr[i] < arr[rightindex])
			{
				swap(arr[i], arr[rightindex]);
				i = rightindex;
			}
			else
			{
				return;
			}
		}
	}

*/
	void print()
	{
		for (int a = 1; a <= size; a++)
		{
			cout << arr[a] << " ";
		}
		cout << endl;
	}
};

void maxHeapify(int arr[], int size, int i)
{
	int largest = i;   // just for parent node accessible by largest variable
	int left = 2 * i;
	int right = 2 * i + 1;

	// Now check the conditions for both left and right
	if (left < size && arr[largest] < arr[left])  // conditions to check its outer bound and the parent and child node
	{
		largest = left;
	}
	if (right < size && arr[largest] < arr[right])
	{
		largest = right;
	}

	if (largest != i)   // last terminating condition
	{
		swap(arr[largest], arr[i]);
		maxHeapify(arr, size, largest);   // recursion for all placements at heap-max locations
	}
}

void minHeapify(int arr[], int size, int i)
{
	int smallest = i;			// just for parent node accessible by smallest variable
	int left = 2 * i + 1;       // here the attitude of left and right childs will alter
	int right = 2 * i + 2;

	// Now check the conditions for both left and right
	if (left < size && arr[smallest ] > arr[left])  // conditions to check its outer bound and the parent and child node
	{
		smallest = left;
	}
	if (right < size && arr[smallest] > arr[right])
	{
		smallest = right;
	}

	if (smallest != i)   // last terminating condition
	{
		swap(arr[smallest], arr[i]);
		maxHeapify(arr, size, smallest);   // recursion for all placements at heap-max locations
	}
}
int main()
{
	cout << "\n\t\t\t--> Heap Project <--\n\n";
	Heap h;
	h.origionalTree();

	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);

	// --> Insertion by HEAP ORDER PROPERTY (HOP)
	cout << "\n\t -> Insertion by Heap Order Property: ";
	h.print();

	// --> Deletion by HEAP ORDER PROPERTY (HOP)
	cout << "\t -> Deletion by Heap Order Property: ";
	h.deletefromheap();
	h.print();

	// --> HEAPIFYING by Max-Heap method
	int size = 5;
	int arr[6] = { -1, 54, 53, 55, 52, 50 };
	for (int i = size / 2; i > 0; i--)
	{
		maxHeapify(arr, size, i);
	}
	cout << "\t -> Printing the Max-Heap is: ";
	h.print();
 
	// --> HEAPIFYING by Min-Heap method

	for (int i = size / 2-1; i >= 0; i--)
	{
		minHeapify(arr, size, i);
	}
	cout << "\t -> Printing the Min-Heap is: ";
	h.print();

	cout << endl;
	system("pause");
	return 0;

}