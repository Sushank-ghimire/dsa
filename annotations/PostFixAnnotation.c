#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

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

int main() {
	Stack postStack = {NULL, -1}, opStack = {NULL, -1};
	char expression[MAX];
	printf("Enter the expression : ");
	scanf("%99s", expression);
	
	int length = strlen(expression), i;
	createStack(&postStack, length);
	createStack(&opStack, length);
	
	// For the postfix anotation algorithm
	for (i = 0; i < length; i++) {
    	char c = expression[i];

    	// If operand ? goes straight to postfix
    	if (checkIsOperation(c) == -1 && c != '(' && c != ')') {  
        	push(&postStack, c);
    	} else if (c == '(') {
    		push(&opStack, c);
		} else if (c == ')') {
			while(opStack.index != -1 && opStack.items[opStack.index] != '(') {
				push(&postStack, pop(&opStack));
			}
			pop(&opStack);
		} else {
        	while (opStack.index != -1 && precedence(opStack.items[opStack.index]) >= precedence(c)) {
            	push(&postStack, pop(&opStack));
        	}
        	// Push current operator
        	push(&opStack, c);
    	}
	}

	while (opStack.index != -1) {
    	push(&postStack, pop(&opStack));
	}
	printf("\nPostfix Expression : ");
	traverseStack(postStack);
	
	// Releasing memory after work
	freeMemory(&postStack);
	freeMemory(&opStack);
	return 0;
}
