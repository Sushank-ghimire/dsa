#include "shared.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

void reverseString(char *str)
{
  int length = strlen(str), i;
  for (i = 0; i < length / 2; i++)
  {
    char temp = str[i];
    str[i] = str[length - 1 - i];
    str[length - 1 - i] = temp;
  }
}

int main()
{
  char expression[MAX];
  int operand1, operand2, i;
  Stack stack = {NULL, 0, -1};
  printf("Enter a prefix expression to trace it's value : ");
  scanf("%99s", expression);
  reverseString(expression);
  int length = strlen(expression);
  createStack(&stack, length);

  for (i = 0; i < length; i++)
  {
    char c = expression[i];
    if (isdigit(c))
    {
      push(&stack, c);
    }
    else if (checkIsOperation(c) == 1)
    {
      operand1 = pop(&stack) - '0';
      operand2 = pop(&stack) - '0';
      int result;
      switch (c)
      {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
      }
      push(&stack, result + '0');
    }
    else
    {
      printf("Invalid expression provided.\n");
    }
  }
  int finalResult = pop(&stack) - '0';
  printf("The value of the prefix expression is: %d\n", finalResult);
  freeMemory(&stack);
  return 0;
}
