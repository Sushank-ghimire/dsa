#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared.h"
#define MAX 100

// Function to reverse a string and swap parentheses
void reverseExpression(char *exp, char *rev)
{
  int length = strlen(exp), i;
  for (i = 0; i < length; i++)
  {
    if (exp[i] == '(')
      rev[length - 1 - i] = ')';
    else if (exp[i] == ')')
      rev[length - 1 - i] = '(';
    else
      rev[length - 1 - i] = exp[i];
  }
  rev[length] = '\0';
}

// Function to convert reversed infix to postfix
void infixToPostfix(char *revExp, char *postfix)
{
  Stack opStack;
  int k = 0, i;
  createStack(&opStack, strlen(revExp));

  for (i = 0; i < strlen(revExp); i++)
  {
    char c = revExp[i];

    if (checkIsOperation(c) == -1)
    { // operand
      postfix[k++] = c;
    }
    else if (c == '(')
    { // left parenthesis
      push(&opStack, c);
    }
    else if (c == ')')
    { // right parenthesis
      while (opStack.index != -1 && opStack.items[opStack.index] != '(')
      {
        postfix[k++] = pop(&opStack);
      }
      pop(&opStack); // discard '('
    }
    else
    { // operator
      while (opStack.index != -1 && precedence(c) < precedence(opStack.items[opStack.index]))
      {
        postfix[k++] = pop(&opStack);
      }
      push(&opStack, c);
    }
  }

  // Pop any remaining operators
  while (opStack.index != -1)
  {
    postfix[k++] = pop(&opStack);
  }
  postfix[k] = '\0';

  freeMemory(&opStack);
}

// Function to reverse string
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
  printf("Enter expression to convert to the prefix annotation : ");
  scanf("%99s", expression);

  int length = strlen(expression);

  char revExp[MAX];
  reverseExpression(expression, revExp);
  printf("The reversed expression is : %s\n", revExp);

  char postfix[MAX];
  infixToPostfix(revExp, postfix);
  printf("The postfix of reversed expression is : %s\n", postfix);

  reverseString(postfix);
  printf("The prefix expression is : %s\n", postfix);

  return 0;
}
