#pragma once
#include "functions.h"


void Heap::origionalTree()				  // Just printing input Tree for greater clearity
{
	int arr[5] = { 50, 55, 53, 52, 54 };
	cout << "\n\t -> Origional Tree given is: ";
	for (int a = 0; a < 5; a++)
	{
		cout << arr[a] << " ";
	}
}

void Heap::insert(int value)		  //insertion in heap       (  O(LOG N)  )
{
	size = size + 1;			   	// move to index 1
	int index = size;		       //pointing leaf node  ( here the leaf node is assumed also as a root node
	arr[index] = value;           //place value at above node

	while (index > 1)
	{
		int parent = index / 2;		        // for BST case, where always two child nodes exists

		if (arr[parent] < arr[index])     //agar parent ki value child se choti ho gi to yeh swap kare ga..! SORRY please
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

void Heap::deletefromheap()
{
	if (size == 0)      // No index case
	{
		cout << "Nothing to delete!!" << endl;
		return;
	}
	arr[1] = arr[size];          //  pointing/putting last element to root(1st index) node
	size--;						//  removing last element	 

	// Now take the root node at its exact position
	int index = 1;
	while (index <= size)
	{

		int leftindex = 2 * index;				  //Assuming indexes are starting from 1
		int rightindex = (2 * index) + 1;
		int nextindex = index;
		// Implementing conditions for left and right side

		if (leftindex < size && arr[nextindex] < arr[leftindex])			  // LEFT condition
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
		index++;
	}
}

void Heap::maxHeapify(int arr[], int size, int i)
{
	int largest = i;   // just for parent node accessible by largest variable
	int left = 2 * i;
	int right = 2 * i + 1;

	// Now check the conditions for both left and right

	if (left < size && arr[largest] < arr[left])      // conditions to check its outer bound and the parent and child node
	{
		largest = left;
	}
	if (right < size && arr[largest] < arr[right])
	{
		largest = right;
	}

	if (largest != i)                          // last terminating condition
	{
		swap(arr[largest], arr[i]);
		maxHeapify(arr, size, largest);   // recursion for all placements at heap-max locations
	}
}


void Heap:: minHeapify(int arr[], int size, int i)
{
	int smallest = i;			 // just for parent node accessible by smallest variable
	int left = 2 * i + 1;       // here the attitude of left and right childs will alter
	int right = 2 * i + 2;

	// Now check the conditions for both left and right

	if (left < size && arr[smallest] > arr[left])  // conditions to check its outer bound and the parent and child node
	{
		smallest = left;
	}
	if (right < size && arr[smallest] > arr[right])
	{
		smallest = right;
	}

	if (smallest != i)        // last terminating condition
	{
		swap(arr[smallest], arr[i]);
		maxHeapify(arr, size, smallest);     // recursion for all placements at heap-max locations
	}
}
void Heap:: print()        // Simple display function
{
	for (int a = 1; a <= size; a++)
	{
		cout << arr[a] << " ";
	}
	cout << endl;
}


// --> Method# 2 for deletion ->


/*
void Heap:: deletefromheap()
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