#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
} Node;

int inputData() {
  int data;
  printf("Enter data to insert : ");
  scanf("%d", &data);
  return data;
}

int isNull(Node *head) {
  return head == NULL;
}

void displayLinkedList(Node *head) {
  if(head == NULL) {
    printf("Linked list is empty.\n");
    return;
  }
  Node *temp = head;
  while(temp != NULL) {
    printf("Node : %p: [%p | %d | %p] -> \n",(void *)temp, (void *) temp->prev, temp->data,(void *)temp->next);
    temp = temp->next;
  }
  printf("NULL\n");
}

void insertNode(Node **head) {
  int data = inputData();
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  if(isNull(*head)) {
    *head = newNode;
    printf("Head node inserted.\n");
    return;
  }
  Node *temp = *head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  newNode->prev = temp;
  temp->next = newNode;
  printf("Node inserted.\n");
}

void insertNodeAtHead(Node **head) {
  int data = inputData();
  Node *newNode = (Node *) malloc(sizeof(Node));

  if(newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = *head;
  if(*head != NULL) {
    (*head)->prev = newNode;
  }
  *head = newNode;
  printf("Node inserted.\n");
}

void insertNodeAtIndex(Node **head) {
}

void deleteFirstNode(Node **head) {
}

void deleteLastNode(Node **head) {
}

void deleteIndexedNode(Node **head) {
}

void freeMemory(Node *head) {
  Node *temp;
  while(isNull(head)) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main() {
  Node *head = NULL;
  int choice;
  do {
    printf("1. Insert Node (At End)\n");
    printf("2. Delete First Node\n");
    printf("3. Delete Last Node\n");
    printf("4. Delete Indexed Node\n");
    printf("5. Insert Node (At Head)\n");
    printf("6. Insert Node (Via Index)\n");
    printf("7. Exit\n");
    printf("8. Display Linked List\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insertNode(&head);
        break;
      case 2:
        deleteFirstNode(&head);
        break;
      case 3:
        deleteLastNode(&head);
        break;
      case 4:
        deleteIndexedNode(&head);
        break;
      case 5:
        insertNodeAtHead(&head);
        break;
      case 6:
        insertNodeAtIndex(&head);
        break;
      case 7:
        printf("Exiting program...\n");
        break;
      case 8:
        displayLinkedList(head);
        break;
      default:
      printf("Invalid choice!\n");
        break;
    }
  }while (choice != 7);
  freeMemory(head);
  return 0;
}
