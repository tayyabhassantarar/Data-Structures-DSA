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

Node* maketree(Node* root)
{
	int data;
	cin >> data;

	root = new Node(data);

	if (data == -1)
	{
		return NULL;
	}
	
	root->left = maketree(root->left);
	root->right = maketree(root->right);

	return root;
}

void inOrder(Node* root)           // The structure of InOrder is "LNR"
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void preOrder(Node* root)            // The structure of InOrder is "NLR"
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Node* root)				// The structure of InOrder is "LRN"
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
int main()
{
	Node* root = NULL;
	cout << "\nPlease enter whole data of a Tree <-- -1 for NULL data -->: ";
	root = maketree(root);

	cout << "\n\t InOrder data is: " << " ";
	inOrder(root);
	cout <<endl<<endl;

	cout << "\n\t PreOrder data is: " << " ";
	preOrder(root);
	cout << endl << endl;

	cout << "\n\t PostOrder data is: " << " ";
	postOrder(root);
	cout << endl << endl;

	//tested tree data to check is: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	system("pause");
	return 0;
}