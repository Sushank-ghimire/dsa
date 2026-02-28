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
  int choice, flag;
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
      case 1:
        printf("Enter value: ");
        scanf("%d", &value);

        if(search(root, value)) {
          printf("Duplicate value not allowed!\n");
        } else {
          root = insert(root, value);
          printf("Value inserted!\n");
        }
        break;
      case 2:
        printf("Enter value to delete: ");
        scanf("%d", &value);
        root = deleteNode(root, value);
        break;
      case 3:
        printf("Enter value to search: ");
        scanf("%d", &value);
        if(!search(root, value))
          printf("Value Not Found!\n");
        break;
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
    printf("\n");
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

Node *findMin(Node* root) {
  if(root->left == NULL)
    return NULL;
  while(root->left != NULL)
    root = root->left;
  return root;
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
  Node *y = x->right;
  Node *t2 = y->left;

  y->left = x;
  x->right = t2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(x->right)) + 1;
  return y;
}

Node *insert(Node *root, int key) {
  if (root == NULL)
    return createNode(key);
  if(key < root->data)
    root->left = insert(root->left, key);
  else if (key > root->data)
    root->right = insert(root->right, key);

  root->height = 1 + max(height(root->left), height(root->right));
  int balance = getBalance(root);

  // LL Case Rotation
  if(balance > 1 && key < root->left->data)
    return rightRotate(root);

  // RR Case Rotation
  if(balance < -1 && key > root->right->data)
    return leftRotate(root);

  // Left Right Rotation
  if(balance > 1 && key > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // Right Left Rotation
  if(balance < -1 && key < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

Node *deleteNode(Node* root, int key) {
  if(root == NULL || !search(root, key)) {
    printf("Value not found\n");
    return root;
  }
  if(key < root->data)
    root->left = deleteNode(root->left, key);
  else if(key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    printf("Deleted : %d\n", key);
    if(root->left == NULL || root->right == NULL) {
      Node *temp = root->left ? root->left : root->right;
      if(temp == NULL) {
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }
      free(temp);
    } else {
      Node *temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  if(root == NULL)
    return root;
  root->height = 1 + max(height(root->left), height(root->right));
  int balance = getBalance(root);

  // LL
  if(balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  // LR
  if(balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // RR
  if(balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  // RL
  if(balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

Node *search(Node* root, int key) {
  if(root == NULL)
    return NULL;

  if(key == root->data) {
    printf("Value %d found in tree.\n", key);
    return root;
  }

  if(key < root->data)
    return search(root->left, key);
  else
    return search(root->right, key);
  return root;
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
