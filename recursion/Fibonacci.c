#include <stdio.h>

int fibonacci(int x)
{
  if (x == 1)
    return 0;
  else if (x == 2)
    return 1;
  else
    return fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
  int i, n;
  printf("Enter a number to print the fibonacci upto that position :");
  scanf("%d", &n);
  printf("The fibonacci series is : \n");
  for (i = 1; i <= n; i++)
  {
    printf("%d ", fibonacci(i));
  }
  printf("\n");
  return 0;
}
