#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

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
		printf("1. Insert Node\n");
		printf("2. Traverse List\n");
		printf("3. Insert Node At Head\n");
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
				break;
			case 5:
				printf("Exiting program...");
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 5);
	freeNodes(head);
}
