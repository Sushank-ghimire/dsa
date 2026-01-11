#include <stdio.h>
#define MAX_SIZE 4

void HornersMethod();
void displayPolynomial(int degree, float coeff[MAX_SIZE]);

int main() {
  int choice;

  do {
    printf("\n1. Horner's Method");
    printf("\n2. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        HornersMethod();
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

void displayPolynomial(int degree, float coeff[MAX_SIZE]) {
  int i;
  for (i = degree; i >= 0; i--)
  {
    if (coeff[i] != 0)
    {
      if (i != degree && coeff[i] > 0)
        printf(" + ");
      else if (coeff[i] < 0)
        printf(" - ");
      printf("%.0f", coeff[i] < 0 ? -coeff[i] : coeff[i]);
      if (i > 0)
        printf("x");
      if (i > 1)
        printf("^%d", i);
    }
  }
  printf("\n");
}

void HornersMethod() {
  int degree, i;
  float coefficient[MAX_SIZE], result, x;

  printf("\nEnter degree of polynomial (max %d): ", MAX_SIZE - 1);
  scanf("%d", &degree);

  if (degree >= MAX_SIZE) {
    printf("Degree exceeds maximum allowed.\n");
    return;
  }
  for(i=degree; i>=0; i--) {
    printf("Enter coefficient for x^%d: ", i);
    scanf("%f", &coefficient[i]);
  }

  printf("\nPolynomaial: ");
  displayPolynomial(degree, coefficient);

  printf("Enter the value of x: ");
  scanf("%f", &x);

  result = coefficient[degree];
  for (i = degree - 1; i >= 0; i--) {
    result = result * x + coefficient[i];
  }

  printf("\nValue of polynomial at x = %.2f is %.2f\n", x, result);
}
