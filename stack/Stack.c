#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int top;
	int *items;
	int index;
	int size;
} Stack;

void create_stack(Stack *stack, int size) {
	if(stack->size > 0) {
		printf("Stack is already created.\n");
		return;
	}
	stack->size = size;
	stack->items = (int *) malloc(size* sizeof(int));
	stack->index = -1;
}

int isEmpty(Stack *stack) {
	if(stack->index >= 0) return 0;
	else return 1;
}

int isFull(Stack *stack) {
	if(stack->index == stack->size-1) return 1;
	else return 0;
}

void push(Stack *stack, int item) {
	if(isFull(stack)) {
		printf("The stack is full can't push items.\n'");
		return;
	}
	stack->index++;
	stack->items[stack->index] = item;
	stack->top = item;
	printf("Item pushed to the stack\n");
}

void pop(Stack *stack) {
	if(isEmpty(stack)) {
		printf("The stack is empty can't pop items.\n");
		return;
	}
	stack->index--;
	stack->top = stack->items[stack->index];
	printf("Item poped from the stack\n");
}

void traverse(Stack *stack) {
	int i;
	printf("Top to bottom : \n");
	for(i=0; i<=stack->index; i++) {
		printf(" %d ", stack->items[i]);
	}
	printf("\n");
}

void peekStack(Stack *stack) {
	if(isEmpty(stack)) {
		printf("The stack is empty.\n");
	} else {
		printf("The top item is : %d\n", stack->top);
	}
}

void freeStack(Stack *stack) {
	free(stack->items);
	stack->items = NULL;
}

int main(){
	int choice, size, item;
	Stack stack;
	do {
		printf("1. Create Stack\n");
		printf("2. Push Item\n");
		printf("3. Pop Item\n");
		printf("4. Show Stack Items\n");
		printf("5. Show Top\n");
		printf("6. Check is empty\n");
		printf("7. Check is full\n");
		printf("8. Exit\n");
		
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter the size of stack : ");
				scanf("%d", &size);
				create_stack(&stack, size);
				printf("Stack created successfully!\n");
				break;
			case 2:
				printf("Enter item to push to the stack : ");
				scanf("%d", &item);
				push(&stack, item);
				break;
			case 3:
				pop(&stack);
				break;
			case 4:
				traverse(&stack);
				break;
			case 8:
				printf("Exiting program...");
				break;
			case 5:
				peekStack(&stack);
				break;
			case 6:
				if(isEmpty(&stack)) {
					printf("The stack is empty.\n");
				} else {
					printf("The stack is not empty.\n");
				}
				break;
			case 7:
				if(isFull(&stack)) {
					printf("The stack is full.\n");
				} else {
					printf("The stack is not full.\n");
				}
				break;
			default:
				printf("Invalid choice!\n");
				
		}
	} while (choice != 8);
	freeStack(&stack);
	return 0;
}
