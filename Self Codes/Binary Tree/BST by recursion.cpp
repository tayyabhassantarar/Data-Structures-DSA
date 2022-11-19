#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
// function for different insertions cases
Node* insertintoBST(Node* &root, int data)
{
	if (root == NULL)
	{
		root = new Node(data);
		return root;
	}
	if (data > root->data)
	{
		root->right = insertintoBST(root->right, data);
	}
	else
	{
		root->left = insertintoBST(root->left, data);
	}
	return root;
}
// create a new tree
void createDATA(Node* &root)
{
	int data;
	cin >> data;

	while (data != -1)
	{
		insertintoBST(root, data);
		cin >> data;
	}
}

// ORDERLY conversions

void preOrder(Node* &root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node* &root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}

}

void inOrder(Node* root)
{
	if (root == NULL) // Base case
	{
		return;
	}
	else
	{
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

bool searchNode(Node* root, int finddata)   //Finding the Node from a tree
{
	if (root == NULL)
	{
		return false;
	}
	if (root->data > finddata)
	{
		return searchNode(root->left, finddata);
	}
	else
	{
		return searchNode(root->right, finddata);
	}
}

Node* minKey(Node* root)     // finding minimum key from tree
{
	Node* temp = root;

	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

Node* maxKey(Node* root)		// finding Maximum key from tree
{
	Node* temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}
//Deletion of the Nodes from BST

Node* deletefromBST(Node* &root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	if (root->data == key)
	{
		// <<< 0 child case >>>

		if (root->left == NULL && root->right == NULL)  
		{
			delete root;
			return NULL;
		}

		// <<< 1 child case >>>

		if (root->left != NULL && root->right == NULL)  // When left side is not Null
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		if (root->left == NULL && root->right != NULL)  // When right side is not Null
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}

		// <<< 2 child case >>>

		if (root->left != NULL && root->right != NULL)
		{
			int mini = minKey(root->right)->data;           // 1- choose most minumum from right side
			root->data = mini;						        // 2- place choosen minimum value at its root (deletion node)
			root->right = deletefromBST(root->right, mini); // 3- delete the choosen value of the right child 
			return root;
		}
	}
	if (root->data > key)   // simple Left child case
	{
		root->left = deletefromBST(root->left, key);
		return root;
	}
	if (root->data < key)  // simple right child case
	{
		root->right = deletefromBST(root->right, key);
		return root;
	}
}


int main()
{
	Node* root = NULL;

	cout << "\n Enter data for Binary Search Tree: ";
	createDATA(root);
	cout << endl;

	cout << "\n\t PreOrder data is: " << " ";
	preOrder(root);
	cout << endl << endl;

	cout << "\n\t PostOrder data is: " << " ";
	postOrder(root);
	cout << endl << endl;

	cout << "\n\t InOrder data is: " << " ";
	inOrder(root);
	cout << endl << endl;

	cout << "Minimum key in a Tree is: " << minKey(root)->data << endl;
	cout << "Maximum key in a Tree is: " << maxKey(root)->data << endl;
	cout << endl << endl;

	int key;
	cout << "Enter the key node to delete: ";
	cin >> key;
	root= deletefromBST(root, key);    // how to display tree after deletion..?


	/*
	cout << "\n Enter data to find from tree: ";    (Node searching code)
	cin >> finddata;
	int finddata;
	searchNode(root, finddata);
	cout << endl << endl;

	*/
	
	//data to check is: 1 3 7 11 17 -1               // -1 is denoting NULL
	system("pause");
	return 0;
}