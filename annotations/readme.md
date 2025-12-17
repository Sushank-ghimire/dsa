# Expression Annotations in C

Expression Annotations are techniques to **convert and evaluate mathematical expressions** in different notations. This repository contains implementations of three major annotation systems and their conversions.

---

## What Are Expression Annotations?

An **annotation** (or **notation**) is a way of writing mathematical expressions. Different notations have different rules for operator placement and evaluation order.

### The Three Main Notations

| Notation | Example      | Description                          |
| -------- | ------------ | ------------------------------------ |
| Infix    | `2 + 3 * 4`  | Operator between operands (Normal)   |
| Prefix   | `+ 2 * 3 4`  | Operator before operands (Polish)    |
| Postfix  | `2 3 4 * +`  | Operator after operands (RPN)        |

---

## 1. Infix Notation

### Description

**Infix** is the standard mathematical notation where operators are placed **between operands**.

### Characteristics

- **Most readable** for humans
- Requires **operator precedence** rules
- Requires **parentheses** for grouping
- Requires **associativity** rules

### Example

```
2 + 3 * 4 = 14  (not 20, because * has higher precedence)
```

### Operator Precedence (High to Low)

```
^ (Exponent)       → Priority 3
* / (Multiply/Divide) → Priority 2
+ - (Add/Subtract)    → Priority 1
```

### Program Implementation

The infix notation is used as **input** in both postfix and prefix conversion programs.

---

## 2. Postfix Notation (Reverse Polish Notation - RPN)

### Description

**Postfix** notation places the **operator after its operands**. Also known as **Reverse Polish Notation (RPN)**.

### Characteristics

- **No parentheses needed** (unambiguous)
- **No operator precedence needed** (order is explicit)
- **Easy to evaluate** with a stack
- Used in calculators and compilers

### Example

```
Infix:   2 + 3 * 4
Postfix: 2 3 4 * +

Evaluation:
Step 1: Push 2 → Stack: [2]
Step 2: Push 3 → Stack: [2, 3]
Step 3: Push 4 → Stack: [2, 3, 4]
Step 4: * (pop 4 and 3, compute 3*4=12) → Stack: [2, 12]
Step 5: + (pop 12 and 2, compute 2+12=14) → Stack: [14]
Result: 14
```

### How to Convert Infix to Postfix

**Algorithm (Shunting Yard Algorithm)**

1. Scan the infix expression from **left to right**
2. If operand → add to postfix output
3. If `(` → push to operator stack
4. If `)` → pop all operators until `(` is found
5. If operator → pop operators with **higher or equal precedence**, then push current operator
6. At end → pop all remaining operators

### Program Implementation

```c
// Infix to Postfix Conversion using Shunting Yard Algorithm
int main() {
    Stack postStack, opStack;
    char expression[MAX];
    printf("Enter the expression : ");
    scanf("%99s", expression);

    int length = strlen(expression);
    createStack(&postStack, length);
    createStack(&opStack, length);

    // For each character in infix expression
    for (i = 0; i < length; i++) {
        char c = expression[i];

        // If operand → goes to postfix output
        if (checkIsOperation(c) == -1 && c != '(' && c != ')') {
            push(&postStack, c);
        }
        // If left parenthesis → push to operator stack
        else if (c == '(') {
            push(&opStack, c);
        }
        // If right parenthesis → pop until '(' found
        else if (c == ')') {
            while(opStack.index != -1 && opStack.items[opStack.index] != '(') {
                push(&postStack, pop(&opStack));
            }
            pop(&opStack);  // Discard '('
        }
        // If operator → handle precedence
        else {
            while (opStack.index != -1 &&
                   precedence(opStack.items[opStack.index]) >= precedence(c)) {
                push(&postStack, pop(&opStack));
            }
            push(&opStack, c);
        }
    }

    // Pop remaining operators
    while (opStack.index != -1) {
        push(&postStack, pop(&opStack));
    }

    printf("\nPostfix Expression : ");
    traverseStack(postStack);
    return 0;
}
```

### Evaluation of Postfix Expression

```c
int main() {
    char expression[MAX];
    Stack stack;
    printf("Enter a postfix expression : ");
    scanf("%99s", expression);

    createStack(&stack, strlen(expression));

    for (i = 0; i < strlen(expression); i++) {
        char c = expression[i];

        // If digit → push to stack
        if (isdigit(c)) {
            push(&stack, c);
        }
        // If operator → pop two operands, compute, push result
        else if (checkIsOperation(c) == 1) {
            int operand1 = pop(&stack) - '0';
            int operand2 = pop(&stack) - '0';
            int result;

            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(&stack, result + '0');
        }
    }

    int finalResult = pop(&stack) - '0';
    printf("Result: %d\n", finalResult);
    return 0;
}
```

### Advantages of Postfix

✔ No precedence rules needed
✔ No parentheses needed
✔ Simple stack-based evaluation
✔ Used in calculators and compilers

### Disadvantages of Postfix

✗ Less readable for humans
✗ Conversion from infix required

---

## 3. Prefix Notation (Polish Notation)

### Description

**Prefix** notation places the **operator before its operands**. Also known as **Polish Notation**.

### Characteristics

- **No parentheses needed** (unambiguous)
- **No precedence needed** (order is explicit)
- **Evaluated right-to-left** using a stack
- Used in some programming languages and compilers

### Example

```
Infix:   2 + 3 * 4
Prefix:  + 2 * 3 4

Evaluation (right to left):
Step 1: Push 4 → Stack: [4]
Step 2: Push 3 → Stack: [4, 3]
Step 3: * (pop 3 and 4, compute 3*4=12) → Stack: [12]
Step 4: Push 2 → Stack: [12, 2]
Step 5: + (pop 2 and 12, compute 2+12=14) → Stack: [14]
Result: 14
```

### How to Convert Infix to Prefix

**Algorithm**

1. **Reverse** the infix expression
2. **Swap** parentheses: `(` ↔ `)`
3. Convert to postfix using shunting yard
4. **Reverse** the result

### Program Implementation

```c
void reverseExpression(char *exp, char *rev) {
    int length = strlen(exp);
    for (int i = 0; i < length; i++) {
        if (exp[i] == '(')
            rev[length - 1 - i] = ')';
        else if (exp[i] == ')')
            rev[length - 1 - i] = '(';
        else
            rev[length - 1 - i] = exp[i];
    }
    rev[length] = '\0';
}

int main() {
    char expression[MAX];
    printf("Enter expression : ");
    scanf("%99s", expression);

    // Step 1: Reverse and swap parentheses
    char revExp[MAX];
    reverseExpression(expression, revExp);
    printf("Reversed: %s\n", revExp);

    // Step 2: Convert reversed infix to postfix
    char postfix[MAX];
    infixToPostfix(revExp, postfix);
    printf("Postfix of reversed: %s\n", postfix);

    // Step 3: Reverse the result
    reverseString(postfix);
    printf("Prefix: %s\n", postfix);

    return 0;
}
```

### Evaluation of Prefix Expression

```c
int main() {
    char expression[MAX];
    Stack stack;
    printf("Enter a prefix expression : ");
    scanf("%99s", expression);

    // Scan RIGHT to LEFT for prefix
    reverseString(expression);
    createStack(&stack, strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];

        if (isdigit(c)) {
            push(&stack, c);
        }
        else if (checkIsOperation(c) == 1) {
            int operand1 = pop(&stack) - '0';
            int operand2 = pop(&stack) - '0';
            int result;

            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(&stack, result + '0');
        }
    }

    printf("Result: %d\n", pop(&stack) - '0');
    return 0;
}
```

### Advantages of Prefix

✔ Unambiguous (no precedence needed)
✔ No parentheses needed
✔ Simple evaluation algorithm
✔ Used in LISP and some compilers

### Disadvantages of Prefix

✗ Less intuitive than infix
✗ Requires right-to-left scanning
✗ Conversion from infix is complex

---

## Comparison of Notations

| Feature           | Infix          | Postfix       | Prefix        |
| ----------------- | -------------- | ------------- | ------------- |
| Readability       | High           | Medium        | Low           |
| Parentheses       | Required       | Not needed    | Not needed    |
| Precedence rules  | Required       | Not needed    | Not needed    |
| Evaluation        | Complex        | Stack-based   | Stack-based   |
| Scanning order    | Left to right  | Left to right | Right to left |
| Calculator use    | Less common    | Common (RPN)  | Rare          |

---

## Helper Functions (Shared Stack Operations)

```c
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
```

### Key Helper Functions

**Operator Precedence**
```c
int precedence(char op) {
    switch (op) {
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
```

**Check if Character is Operation**
```c
int checkIsOperation(char c) {
    char operations[] = "+-()*/$^";
    for (int i = 0; i < strlen(operations); i++) {
        if (operations[i] == c)
            return 1;
    }
    return -1;
}
```

---

## Conversion Flow

```
Infix Expression
        ↓
    [Input]
        ↓
    ┌───────────────────┐
    │  Postfix          │  ← Shunting Yard Algorithm
    └───────────────────┘
        ↓
    [Stack Evaluation]
        ↓
    Result


Infix Expression
        ↓
    [Reverse]
    [Swap ( and )]
        ↓
    [Convert to Postfix]
        ↓
    [Reverse Result]
        ↓
    Prefix Expression
        ↓
    [Stack Evaluation]
        ↓
    Result
```

---

## Exam Notes Summary

- **Infix**: Standard notation, needs precedence rules
- **Postfix**: No precedence, easy evaluation, scan left-to-right
- **Prefix**: No precedence, scan right-to-left
- **Shunting Yard**: Converts infix to postfix
- **Precedence**: `^` > `*/` > `+-`
- **Associativity**: All operators are left-associative

---

## One-Line Conclusion

> Expression Annotations provide three different ways to write and evaluate mathematical expressions: **Infix** (human-readable), **Postfix** (easy evaluation), and **Prefix** (operator first), with conversion algorithms to switch between them.
