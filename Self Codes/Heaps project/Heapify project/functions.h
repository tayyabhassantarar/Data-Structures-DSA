#include <iostream>
using namespace std;

class Heap					 //Making the class for heap
{
public:
	int arr[100];
	int size = 0;

	//  ---> Functions <---

	void origionalTree();
	void insert(int value);          
	void deletefromheap();
	void maxHeapify(int arr[], int size, int i);
	void minHeapify(int arr[], int size, int i);
	void print();
	

	Heap()              // Default constructor
	{
		arr[0] = -1;   // -1 is the assumed value for index 0
		size = 0;
	}
};


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