#include "implementation.h"

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
	cout << "\n\t -> Insertion by Heap Order Property:\t";
	h.print();

	// --> HEAPIFYING by Max-Heap method
	int size = 5;
	int arr[6] = { -1, 54, 53, 55, 52, 50 };
	for (int i = size / 2; i > 0; i--)
	{
		h.maxHeapify(arr, size, i);
	}
	cout << "\t -> Printing the Max-Heap is: \t";
	h.print();

	// --> HEAPIFYING by Min-Heap method

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		h.minHeapify(arr, size, i);
	}
	//cout << "\t -> Printing the Min-Heap is: \t";
	//h.print();

	// --> Deletion by HEAP ORDER PROPERTY (HOP)
	cout << "\t -> Deletion by Heap Order Property:\t";
	h.deletefromheap();
	h.print();



	cout << endl;
	system("pause");
	return 0;

}