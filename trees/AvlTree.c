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

/* Node rotation functions */
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
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);

int main() {
  Node* root = NULL;
  int choice;
  while(1) {
    int choice, value;
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Inorder\n");
    printf("5. Preorder\n");
    printf("6. Postorder\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 4:
        printf("Inorder : ");
        inorder(root);
        printf("\n");
        break;

      case 5:
        printf("Preorder : ");
        preorder(root);
        printf("\n");
        break;

      case 6:
        printf("Postorder : ");
        postorder(root);
        printf("\n");
        break;
      case 7:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int height(Node* node) {
  if(node == NULL)
    return 0;
  return node->height;
}

Node *createNode(int data) {
  Node *node = (Node *) malloc(sizeof(Node));
  node->data = data;
  node->left = node->right = NULL;
  node->height = 1;
  return node;
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->left;
  Node *t2 = y->right;

  y->right = x;
  x->left = t2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(x->right)) + 1;
  return y;
}

int getBalance(Node* node) {
  if(node == NULL)
    return 0;
  return height(node->left) - height(node->right);
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
