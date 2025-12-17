#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *items;
	int size;
	int index;
} Stack;

void createStack(Stack *stack, int size) {
	stack->size = size;
	stack->items = (char *) malloc(size * sizeof(char));
	if(!stack->items) {
		printf("Failed to create stack.\n");
		return;
	}
	stack->index = -1;
}

int checkIsOperation(char c) {
	int i;
	char operations[] = "+-()*/$^";
	for(i=0; i<strlen(operations); i++) {
		if(operations[i] == c) {
			return 1;
		}
	}
	return -1;
}

void push(Stack *stack, char data) {
	if(stack->index == stack->size-1) {
		printf("Stack overflow\n");
		return;
	}
	stack->items[++stack->index] = data;
}

char pop(Stack *stack) {
	if(stack->index == -1) {
		printf("Stack is empty.\n");
		return '\0';
	}
	return stack->items[stack->index--];
}

void freeMemory(Stack *stack) {
	free(stack->items);
}

void traverseStack(Stack stack) {
    int i;
    for(i = 0; i <= stack.index; i++) {
        printf("%c ", stack.items[i]);
    }
}

int precedence(char op) {
	switch(op) {
		case '-':
		case '+':
			return 1;
		case '/':
		case '*':
			return 2;
		case '$':
		case '^':
			return 3;
	}
	return 0;
}
