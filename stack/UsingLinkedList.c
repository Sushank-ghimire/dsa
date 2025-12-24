#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
}Node;

void push(Node **stack) {
  int data;
  printf("Enter data to push: ");
  scanf("%d", &data);

  Node *newNode = (Node *) malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }
  newNode->data = data;
  newNode->next = *stack;
  *stack = newNode;
}

void display(Node *stack) {
  if(stack == NULL) {
    printf("Stack is empty.\n");
    return;
  }

  Node *temp = stack;
  printf("NULL");
  while(temp != NULL) {
    printf(" <- %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void pop(Node **stack) {
  if(*stack == NULL) {
    printf("Stack is empty can't perform pop operation.\n");
    return;
  }

  Node *temp = *stack;
  *stack = (*stack)->next;
  printf("Item popped successfully (popped item %d).\n", temp->data);
  free(temp);
}

void freeNodes(Node *stack) {
	Node *temp;
	while(stack != NULL) {
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int main() {
  int choice;
  Node *stack = NULL;
  do {
    printf("1. Push Item \n");
    printf("2. Pop Item \n");
    printf("3. Display Item \n");
    printf("4. Exit \n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        push(&stack);
        break;
      case 2:
        pop(&stack);
        break;
      case 3:
        display(stack);
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 4);
  freeNodes(stack);
  return 0;
}
