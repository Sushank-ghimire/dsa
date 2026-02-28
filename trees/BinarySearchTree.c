#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

Node* createNode(int);
Node* insert(Node*, int);
Node* search(Node*, int);
Node* findMin(Node*);
Node* deleteNode(Node*, int, int*);

void inorder(Node*);
void preorder(Node*);
void postorder(Node*);

int main() {
  struct Node* root = NULL;
  int choice, value;
  int flag = 0;

  while(1) {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Inorder\n");
    printf("5. Preorder\n");
    printf("6. Postorder\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
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
        root = deleteNode(root, value, &flag);

        if(flag)
          printf("Value deleted!\n");
        else
          printf("Value not found!\n");
        break;

      case 3:
        printf("Enter value to search: ");
        scanf("%d", &value);
        if(search(root, value))
          printf("Value Found!\n");
        else
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
      default:
        printf("Invalid choice!\n");
    }
    printf("\n");
  }
}

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Memory Allocation Failed!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node* insert(Node* root, int data) {
  if(root == NULL) {
    return createNode(data);
  }
  if(data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

Node* search(Node* root, int key)  {
  if(root == NULL || root->data == key) {
    return root;
  }
  if(key < root->data) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

Node* findMin(Node* root) {
  if(root == NULL)
    return NULL;
  while(root->left != NULL)
    root = root->left;
  return root;
}

Node* deleteNode(Node* root, int key, int* deleted) {
  if(root == NULL)
    return NULL;
  if(key < root->data)
    root->left = deleteNode(root->left, key, deleted);
  else if (key > root->data)
    root->right = deleteNode(root->right, key, deleted);
  else {
    *deleted = 1;
    if(root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root);
      return temp;
    } else {
      Node* temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data, deleted);
    }
  }
  return root;
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
