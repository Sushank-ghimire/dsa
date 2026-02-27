#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  int height;
  struct Node *left, *right;
} Node;

/* Utility Functions */
int max(int, int);
int height(Node*);

Node* createNode(int);
Node* rightRotate(Node*);
Node* leftRotate(Node*);
int getBalance(Node*);

/* Tree actions */
Node *insert(Node*, int);
Node *findMin(Node*);
Node *deleteNode(Node*, int);

/* Searching */
Node *search(Node*, int);

/* Traversals */

int main() {
  return 0;
}

void inorder(Node* root) {
  if(root == NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(Node* root) {
  if(root == NULL) return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root) {
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}
