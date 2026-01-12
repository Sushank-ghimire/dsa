#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next; // self referencing structure
} Node;

// Printing data of the each node
void traverseNode(Node *node) {
	if(node == NULL) {
		printf("List is empty\n");
		return;
	}
	printf("Linked List Elements are : \n");
	while(node != NULL) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

// Inserting new Node in the list
void insertNode(Node **head) {
	int value;
	printf("Enter value to insert : ");
	scanf("%d", &value);

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	if(*head == NULL) {
		*head = newNode;
		printf("Head node created\n");
		return;
	}

	Node *temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	printf("Node inserted\n");
}

// Function to insert a head node
void insertHeadNode(Node **head) {
  int value;
	printf("Enter value to insert : ");
	scanf("%d", &value);

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	if(*head == NULL) {
		*head = newNode;
		printf("Head node created\n");
		return;
	}
	Node *temp = *head;
	newNode->next = temp;
	*head= newNode;
	printf("Node inserted successfully!\n");
}

// Function to add a node at specific index
void insertNodeAtIndex(Node **head) {
  traverseNode(*head);
  int index, i, data;
  printf("Enter the index to insert at : ");
  scanf("%d", &index);
  printf("Enter the data to insert : ");
  scanf("%d", &data);

  Node *newNode = (Node *) malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;

  Node *temp = *head;
  for(i=0; i<index-1 && temp != NULL; i++) {
    temp = temp->next;
  }
  if(temp == NULL) {
    printf("Invalid index.\n");
    free(newNode);
    return;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  printf("Node inserted at index %d successfully!\n", index);
}

// function to search node element position
void searchNode(Node *head) {
	int value;
	printf("Enter value to search : ");
	scanf("%d", &value);

	int position = 1;
	Node *temp = head;
	while(temp != NULL) {
		if(temp->data == value) {
			printf("Value %d found at position %d.\n", value, position);
			return;
		}
		temp = head->next;
		position++;
	}
	printf("The value %d not found in the list.\n", value);
}

// Function to delete the last tail node
void deleteNode(Node **head) {
	if(*head == NULL) {
		printf("The list is empth. Nothing can be deleted.\n");
		return;
	}
	Node *temp = *head;
	Node *prev = NULL;

	while(temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}

	prev->next = NULL;
	free(temp);
	printf("Node deleted.\n");
}

// Function to delete head node
void deleteHeadNode(Node **head) {
  if(*head == NULL) {
    printf("Node is empty can't delete.\n");
    return;
  }
  Node *temp = *head;
  *head = temp->next;
  free(temp);
  printf("Head node deleted successfully!\n");
}

// Function to release heap memory
void freeNodes(Node *head) {
	Node *temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main() {
	int choice;

	Node *head = NULL;

	do {
		printf("1. Insert Node (At end)\n");
		printf("2. Insert Node (At Head)\n");
		printf("3. Display Nodes\n");
		printf("4. Delete Node (At end)\n");
		printf("5. Delete Node (At first)\n");
		printf("6. Insert Node (via index)\n");
		printf("7. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				insertNode(&head);
				break;
			case 2:
			  insertHeadNode(&head);
				break;
			case 3:
				traverseNode(head);
				break;
			case 4:
				deleteNode(&head);
				break;
			case 5:
        deleteHeadNode(&head);
    		break;
      case 6:
        insertNodeAtIndex(&head);
        break;
			case 7:
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 7);
	freeNodes(head);
	return 0;
}
