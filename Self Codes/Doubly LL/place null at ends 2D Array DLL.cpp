#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data; // To hold the value of matrix

  // 4 pointers for left, right, up, down for markings.
  Node* left;
  Node* right;
  Node* up;
  Node* down;

  Node(int x) : data(x) , left(NULL) , right(NULL) , up(NULL) , down(NULL) {}
};

void print(Node* head) {
  // Require 2 pointers, downptr and rightptr, for rows and columns.
  Node* downptr = head;
  Node* rightptr;
  while (downptr) {
    rightptr = downptr;
    while (rightptr) {
      cout << (rightptr->data) << " ";
      rightptr = rightptr->right;
    }
    cout << "\n";
    downptr = downptr->down;
  }
}
//Driver Code
int main() {
  int mat[3][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };
  int n = 3, m = 3;

  Node* head_main = NULL; // head of our final modified doubly linked list from 2d matrix.
  Node* prev, *upper = new Node(-1); // dummy node to mark start of up pointer.
  for (int i = 0; i < n; i++) {
    Node* head_row; //row-wise head of list.
    Node *prev = new Node(-1); // dummy node to mark start of left pointer.
    for (int j = 0; j < m; j++) {
      Node* temp = new Node(mat[i][j]);

      if (j == 0) head_row = temp;
      if (i == 0 && j == 0) head_main = temp;

      temp->left = prev;
      prev->right = temp;
      if (i == n - 1) temp->down = NULL;

      //This is only used for 1st row.
      if (!upper->right) {
        upper->right = new Node(-1);
      }
      upper = upper->right;

      temp->up = upper;
      upper->down = temp;
      prev = temp;

      if (j == m - 1) prev->right = NULL;

    }
    upper = head_row->left;
  }
  print(head_main);

  return 0;
}
