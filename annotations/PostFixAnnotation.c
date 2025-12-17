#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared.h"

#define MAX 100

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
