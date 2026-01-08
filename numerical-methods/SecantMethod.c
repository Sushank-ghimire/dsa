#include <stdio.h>
#include <math.h>

// Function Declarations
double f(double x);
void secantMethod();


int main() {
  int choice;

  do {
    printf("\n1. Secant Method");
    printf("\n2. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        secantMethod();
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

// function: f(x) = x^3 - x - 1
double f(double x) {
  return x*x*x - x - 1;
}

// Secant Method function
void secantMethod() {
  double x0, x1, x2, tolerance;
  int maxIterations, iteration = 0;

  printf("\nEnter first initial guess x0: ");
  scanf("%lf", &x0);

  printf("Enter second initial guess x1: ");
  scanf("%lf", &x1);

  printf("Enter maximum iterations: ");
  scanf("%d", &maxIterations);

  printf("Enter allowed error (tolerance): ");
  scanf("%lf", &tolerance);

  printf("\nIteration\t x\n");

  do {
    if (f(x1) - f(x0) == 0) {
      printf("Mathematical error (division by zero).\n");
      return;
    }

    x2 = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
    iteration++;

    printf("%d\t\t %.6lf\n", iteration, x2);

    x0 = x1;
    x1 = x2;

  } while (fabs(f(x2)) > tolerance && iteration < maxIterations);

  printf("\nThe approximate root is: %.5lf\n", x2);
}
