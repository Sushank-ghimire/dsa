#include <stdio.h>
#include <math.h>

float f(float x);

void bisectionMethod();

int main() {
  int choice;

  do {
    printf("\n1. Bisection Method");
    printf("\n2. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        bisectionMethod();
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

// Function definition: f(x) = x^3 - x - 1
float f(float x) {
  return x * x * x - x - 1;
}

// Bisection Method implementation
void bisectionMethod() {
  float a, b, mid, tolerance;
  int iteration = 0;

  printf("\nEnter the value of a: ");
  scanf("%f", &a);
  printf("Enter the value of b: ");
  scanf("%f", &b);
  printf("Enter tolerance: ");
  scanf("%f", &tolerance);

  // Interval validation
  if (f(a) * f(b) > 0) {
    printf("\nInvalid interval! f(a) and f(b) must have opposite signs.\n");
    return;
  }

  if (f(a) == 0.0) {
    printf("\nRoot of the equation is: %.5f\n", a);
    return;
  }

  if (f(b) == 0.0) {
    printf("\nRoot of the equation is: %.5f\n", b);
    return;
  }

  printf("\nIter\t a\t\t b\t\t mid\t\t f(mid)\n");

  do {
    mid = (a + b) / 2.0;
    iteration++;

    printf("%d\t %.5f\t %.5f\t %.5f\t %.5f\n", iteration, a, b, mid, f(mid));

    if (f(a) * f(mid) < 0)
      b = mid;
    else
      a = mid;

  } while (fabs(f(mid)) > tolerance);

  printf("\nRoot of the equation is approximately: %.5f\n", mid);
}
