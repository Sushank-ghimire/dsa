#include <stdio.h>

int GCD(int n1, int n2)
{
  if (n2 == 0)
    return n1;
  else
    return GCD(n2, n1 % n2);
}

int main()
{
  int num1, num2;
  printf("Enter the two number's to find the GCD : ");
  scanf("%d %d", &num1, &num2);

  int gcd = GCD(num1, num2);
  printf("The gcd between %d and %d is %d.\n", num1, num2, gcd);
  return 0;
}
