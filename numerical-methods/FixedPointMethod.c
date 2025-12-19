#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TOL 1.e-6
#define MAX_ITERATION 50

// function g(x)
double g(double x)
{
  return cbrt(1 - x); // cube root of (1-x)
}

int main()
{
  double x0, x1;
  int iteration = 0;
  printf("Enter initial guess : ");
  scanf("%lf", &x0);

  do
  {
    x1 = g(x0);
    printf("Iteration %d: x = %lf\n", iteration + 1, x1);

    if (fabs(x1 - x0) < TOL)
    {
      printf("Root found : %lf\n", x1);
      return 0;
    }
    x0 = x1;
    iteration++;
  } while (iteration < MAX_ITERATION);
  printf("\nMethod did not converge.\n");
  return 0;
}
