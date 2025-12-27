#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node ;

void freeNodes(Node *front) {
	Node *temp;
	while(front != NULL) {
		temp = front;
		front = front->next;
		free(temp);
	}
}

int inputData(char *message) {
  int data;
  printf("%s", message);
  scanf("%d", &data);
  return data;
}

void insertData(Node **rear, Node **front) {
  Node *temp = *rear;
  int data = inputData("Enter element to insert : ");
  Node *newNode = (Node *) malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  if(*rear == NULL) {
    *rear = *front = newNode;
    return;
  } else {
   (*rear)->next = newNode;
   *rear = newNode;
  }
  printf("Data inserted.\n");
}

void displayNode(Node *front) {
  if(front == NULL) {
    printf("Queue is empty.\n");
    return;
  }
  while (front != NULL) {
    printf("%d -> ", front->data);
    front = front->next;
  }
  printf("NULL\n");
}

void deleteNode(Node **front, Node **rear) {
  if(*front == NULL) {
    printf("Queue is empty.\n");
    return;
  }
  Node *temp = *front;
  printf("Element %d deleted successfully.\n", temp->data);
  *front = temp->next;

  if (*front == NULL) {
    *rear = NULL;
  }
  free(temp);
}

int main() {
  Node *front = NULL, *rear = NULL;
  int choice;
  do {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    choice = inputData("Enter your choice : ");

    switch (choice) {
      case 1:
        insertData(&rear, &front);
        break;
      case 2:
        deleteNode(&front, &rear);
        break;
      case 3:
        displayNode(front);
        break;
      case 4:
        freeNodes(front);
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  }while (choice != 4);
  return 0;
}
