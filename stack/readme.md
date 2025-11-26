# Stack Data Structure in DSA

## 1. Definition

**Stack**: Stack is a linear data structure that follows the **LIFO (Last In First Out)** principle. The element inserted last is the first one to be removed. Think of it like a stack of plates - you can only add or remove plates from the top.

## 2. Types of Stack

### a) **Fixed Size Stack (Static Stack)**

- Implemented using **arrays**
- Size is fixed at compile time
- Memory efficient but inflexible
- Risk of **stack overflow** if full

### b) **Dynamic Stack**

- Implemented using **linked lists**
- Size can grow dynamically
- More flexible but uses extra memory for pointers
- No size limitation (until system memory is full)

## 3. Basic Operations

| Operation    | Description                             |
| ------------ | --------------------------------------- |
| **Push**     | Add an element to the top of stack      |
| **Pop**      | Remove and return the top element       |
| **Peek/Top** | View the top element without removing   |
| **isEmpty**  | Check if stack is empty                 |
| **isFull**   | Check if stack is full (for fixed size) |

## 4. Time Complexity

| Operation   | Array Implementation | Linked List Implementation |
| ----------- | -------------------- | -------------------------- |
| **Push**    | O(1)                 | O(1)                       |
| **Pop**     | O(1)                 | O(1)                       |
| **Peek**    | O(1)                 | O(1)                       |
| **isEmpty** | O(1)                 | O(1)                       |
| **Search**  | O(n)                 | O(n)                       |

**Space Complexity**:

- Array: O(n) where n is the maximum size
- Linked List: O(n) where n is the number of elements

## 5. Applications

- Function call management (recursion)
- Expression evaluation (infix, postfix, prefix)
- Undo/Redo operations in editors
- Browser history (back button)
- Backtracking algorithms

## Program Implementation

```c
// Structure of the stack
typedef struct {
	int *items;
	int index;
	int size;
} Stack;

// Function to create stack with required size
void create_stack(Stack *stack, int size) {
	stack->size = size;
	stack->index = -1;
	stack->items = (int *) malloc(size* sizeof(int));
	if(!stack->items) {
		printf("Memory allocation failed\n");
		exit(1);
	}
}

// Function to check the stack is empty or not
int isEmpty(Stack *stack) {
	return stack->index == -1;
}

// Function to check the stack is full or not
int isFull(Stack *stack) {
	return stack->index == stack->size - 1;
}

// Function to push items to the stack
void push(Stack *stack, int item) {
	if(isFull(stack)) {
		printf("The stack is full can't push items.\n");
		return;
	}
	stack->items[++stack->index] = item;
	printf("Item pushed to the stack\n");
}

// Function to pop item from the stack
void pop(Stack *stack) {
	if(isEmpty(stack)) {
		printf("The stack is empty can't pop items.\n");
		return;
	}
	int popped = stack->items[stack->index--];
	printf("Item popped: %d\n", popped);
}

// Function to show the stack values
void traverse(Stack *stack) {
	int i;
	printf("Bottom to top : \n");
	for(i=0; i<=stack->index; i++) {
		printf(" %d ", stack->items[i]);
	}
	printf("\n");
}

// Function to get the top item from the stack
void peekStack(Stack *stack) {
	if(isEmpty(stack)) {
		printf("The stack is empty.\n");
	} else {
		printf("The top item is : %d\n", stack->items[stack->index]);
	}
}

// Function to free the heap memory after completing the work
void freeStack(Stack *stack) {
	free(stack->items);
	stack->items = NULL;
}
```
