#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

// Node insertion at end
void insertNode(Node **head) {
	int data;
	printf("Enter the data to insert in the node : ");
	scanf("%d", &data);
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = newNode;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  Node *temp = *head;

  while (temp->next != *head)
    temp = temp->next;

  temp->next = newNode;
  newNode->next = *head;
}

// Node insertion at head
void insertHeadNode(Node **head) {
  int value;
  printf("Enter value to insert at head: ");
  scanf("%d", &value);

  Node *newNode = malloc(sizeof(Node));
  newNode->data = value;

  if (*head == NULL) {
    newNode->next = newNode;
    *head = newNode;
    printf("Head node created.\n");
    return;
  }

  Node *temp = *head;
  while (temp->next != *head)
    temp = temp->next;

  newNode->next = *head;
  temp->next = newNode;
  *head = newNode;

  printf("Node inserted at head.\n");
}

// Node insertion at a indexed position
void insertNodeAtIndex(Node **head) {
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }

  int index, data, i;

  printf("Enter the index to insert at : ");
  scanf("%d", &index);
  printf("Enter the data to insert : ");
  scanf("%d", &data);

  if (index == 0) {
    insertHeadNode(head);
    return;
  }

  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;

  Node *temp = *head;
  for (i = 0; i < index - 1 && temp->next != *head; i++)
    temp = temp->next;

  if (temp->next == *head && i < index - 1) {
    printf("Invalid index.\n");
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;

  printf("Node inserted at index %d.\n", index);
}

// Deletion of last node
void deleteNode(Node **head) {
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }

  Node *temp = *head;
  Node *prev = NULL;

  if (temp->next == temp) {
    free(temp);
    *head = NULL;
    printf("Node deleted.\n");
    return;
  }

  while (temp->next != *head) {
    prev = temp;
    temp = temp->next;
  }

  prev->next = *head;
  free(temp);
  printf("Last node deleted.\n");
}

// Deleting node from head
void deleteHeadNode(Node **head) {
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }

  Node *temp = *head;

  if (temp->next == temp) {
    free(temp);
    *head = NULL;
    printf("Head node deleted.\n");
    return;
  }

  Node *last = *head;
  while (last->next != *head)
    last = last->next;

  *head = temp->next;
  last->next = *head;
  free(temp);

  printf("Head node deleted.\n");
}

// Showing elements from node
void traverseNode(Node *head) {
	if(head == NULL) {
		printf("List is empty.\n");
		return;
	}
	Node *temp = head;
	do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("(back to head)\n");
}

// Releasing the memory from heap
void freeNodes(Node *head) {
	if (head == NULL) return;
	Node *temp = head, *nextNode;
	do{
		nextNode = temp->next;
		free(temp);
		temp = nextNode;
	} while(temp != head);
}

int main() {
	Node *head = NULL;
	int choice;
	do {
    printf("1. Insert Node (At End)\n");
    printf("2. Insert Node (At Head)\n");
    printf("3. Insert Node (Via Index)\n");
    printf("4. Delete Node (At End)\n");
    printf("5. Delete Node (At Head)\n");
    printf("6. Display Nodes\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insertNode(&head);
        break;
      case 2:
        insertHeadNode(&head);
        break;
      case 3:
        insertNodeAtIndex(&head);
        break;
      case 4:
        deleteNode(&head);
        break;
      case 5:
        deleteHeadNode(&head);
        break;
      case 6:
        traverseNode(head);
        break;
      case 7:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 7);
	freeNodes(head);
}
