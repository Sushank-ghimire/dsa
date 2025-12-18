#include <stdio.h>

int factorial(int num)
{
  if (num == 0)
    return 1;
  else
    return num * factorial(num - 1);
}

int main()
{
  int n;
  printf("Enter a number to find factorial : ");
  scanf("%d", &n);

  if (n < 0)
  {
    printf("Invalid input.\n");
    return 1;
  }
  int fact = factorial(n);
  printf("The factorial of %d is %d.\n", n, fact);
  return 0;
}
