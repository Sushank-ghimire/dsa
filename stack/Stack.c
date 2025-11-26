#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *items;
	int index;
	int size;
} Stack;

void create_stack(Stack *stack, int size) {
	stack->size = size;
	stack->index = -1;
	stack->items = (int *) malloc(size* sizeof(int));
	if(!stack->items) {
		printf("Memory allocation failed\n");
		exit(1);
	}
}

int isEmpty(Stack *stack) {
	return stack->index == -1;
}

int isFull(Stack *stack) {
	return stack->index == stack->size - 1;
}

void push(Stack *stack, int item) {
	if(isFull(stack)) {
		printf("The stack is full can't push items.\n");
		return;
	}
	stack->items[++stack->index] = item;
	printf("Item pushed to the stack\n");
}

void pop(Stack *stack) {
	if(isEmpty(stack)) {
		printf("The stack is empty can't pop items.\n");
		return;
	}
	int popped = stack->items[stack->index--];
	printf("Item popped: %d\n", popped);
}

void traverse(Stack *stack) {
	int i;
	printf("Bottom to top : \n");
	for(i=0; i<=stack->index; i++) {
		printf(" %d ", stack->items[i]);
	}
	printf("\n");
}

void peekStack(Stack *stack) {
	if(isEmpty(stack)) {
		printf("The stack is empty.\n");
	} else {
		printf("The top item is : %d\n", stack->items[stack->index]);
	}
}

void freeStack(Stack *stack) {
	free(stack->items);
	stack->items = NULL;
}

int main(){
	int choice, size, item;
	Stack stack = {NULL, -1, 0};
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
		
		if (stack.items == NULL && choice != 1 && choice != 8) {
            printf("Error: Create the stack first!\n");
            continue;
        }

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
