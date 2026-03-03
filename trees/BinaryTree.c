#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

int input(char *);
Node* createNode(int);
Node* insertLevelOrder(Node*, int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
void deleteTree(Node*);

int main() {
  Node *root = NULL;
  int choice, data;
  do {
    printf("1. Insert\n");
    printf("2. Pre-order Traversal\n");
    printf("3. In-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Exit\n");
    choice = input("Enter your choice : ");

    switch (choice) {
      case 1:
        data = input("Enter data to insert : ");
        root = insertLevelOrder(root, data);
        break;
      case 2:
        if(root == NULL){
          printf("Tree is empty\n");
          break;
        }
        printf("Pre-order Traversal: ");
        preorder(root);
        printf("\n");
        break;
      case 3:
        if(root == NULL){
          printf("Tree is empty\n");
          break;
        }
        printf("In-order Traversal: ");
        inorder(root);
        printf("\n");
        break;
      case 4:
        if(root == NULL){
          printf("Tree is empty\n");
          break;
        }
        printf("Post-order Traversal: ");
        postorder(root);
        printf("\n");
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
    printf("\n");
  } while (choice != 5);
  deleteTree(root);
  return 0;
}

int input(char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}

Node* createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node* insertLevelOrder(Node* root, int data) {
  if(root == NULL)
    return createNode(data);

  Node* queue[MAX];
  int front = 0, rear = 0;

  queue[rear++] = root;

  while (front < rear) {
    Node *temp = queue[front++];
    if(temp->left == NULL) {
      temp->left = createNode(data);
      return root;
    } else {
      queue[rear++] = temp->left;
    }

    if(temp->right == NULL) {
      temp->right = createNode(data);
      return root;
    } else {
      queue[rear++] = temp->right;
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

void deleteTree(Node* root) {
  if(root == NULL) return;
  deleteTree(root->left);
  deleteTree(root->right);
  free(root);
}
