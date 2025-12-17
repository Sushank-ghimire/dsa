#ifndef SHARED_H
#define SHARED_H

typedef struct {
	char *items;
	int size;
	int index;
} Stack;

void createStack(Stack *stack, int size);
int checkIsOperation(char c);
void push(Stack *stack, char data);
char pop(Stack *stack);
void freeMemory(Stack *stack);
void traverseStack(Stack stack);
int precedence(char op);

#endif
