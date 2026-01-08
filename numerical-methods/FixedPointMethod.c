#include <stdio.h>
#include <math.h>

// Function declarations
double g(double x);
void fixedPointMethod();

int main() {
  int choice;

  do {
    printf("\n1. Fixed Point Method");
    printf("\n2. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        fixedPointMethod();
        break;
      case 2:
        printf("\nExiting program...\n");
        break;
      default:
        printf("\nInvalid choice! Try again.\n");
    }
  } while (choice != 2);

  return 0;
}

// function g(x)
double g(double x)
{
  return cbrt(1 - x); // cube root of (1-x)
}

void fixedPointMethod()
{
  double x0, x1;
  int iteration = 0, maxIterations;
  float tolerance;
  printf("Enter initial guess : ");
  scanf("%lf", &x0);
  printf("Enter maximum iterations : ");
  scanf("%d", &maxIterations);
  printf("Enter allowed error (tolerance): ");
  scanf("%f", &tolerance);

  do
  {
    x1 = g(x0);
    printf("Iteration %d: x = %lf\n", iteration + 1, x1);

    if (fabs(x1 - x0) < tolerance)
    {
      printf("Root found : %lf\n", x1);
      return;
    }
    x0 = x1;
    iteration++;
  } while (iteration < maxIterations);
  printf("\nMethod did not converge.\n");
  return;
}
