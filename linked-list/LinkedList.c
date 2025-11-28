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

// Function to delete a specific node
void deleteNode(Node **head) {
	if(*head == NULL) {
		printf("The list is empth. Nothing can be deleted.\n");
		return;
	}
	int value;
	printf("Enter value to delete : ");
	scanf("%d", &value);

	Node *temp = *head;
	Node *prev = NULL;
	// If head node is to be deleted
	if(temp != NULL && temp->data == value) {
		*head = temp->next;
		free(temp);
		printf("Node deleted.\n");
		return;
	}
	// Loop to search the node
	while(temp != NULL && temp->data != value) {
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) {
		printf("The required value not found in the list.\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
	printf("Node deleted.\n");
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
		printf("1. Insert Node\n");
		printf("2. Display Nodes\n");
		printf("3. Delete Node\n");
		printf("4. Search Node\n");
		printf("5. Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				insertNode(&head);
				break;
			case 2:
				traverseNode(head);
				break;
			case 3:
				deleteNode(&head);
				break;
			case 4:
				searchNode(head);
				break;
			case 5:
				printf("Exiting program...");
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 5);
	freeNodes(head);
	return 0;
}
