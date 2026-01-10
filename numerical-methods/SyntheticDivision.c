#include <stdio.h>
#define MAX_SIZE 4

void displayPolynomial(int degree, float coefficient[MAX_SIZE]);
void syntheticDivision();

int main() {
  int choice;

  do {
    printf("\n1. Synthetic Division");
    printf("\n2. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        syntheticDivision();
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

void displayPolynomial(int degree, float coeff[MAX_SIZE])
{
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

void syntheticDivision()
{
  int degree, i, choice;
  float coefficients[MAX_SIZE]; // degree <= 3
  float divisor;                // divisor x-c

  // Taking the degree from the user
  do
  {
    printf("Enter the degree of the polynomial (max 3): ");
    scanf("%d", &degree);
    if (degree < 0 || degree > 3)
      printf("Please enter a valid degree! Enter a degree between 0 and 3.\n");
  } while (degree < 0 || degree > 3);

  // Taking coefficients from user
  for (i = degree; i >= 0; i--)
  {
    printf("Enter the coefficient of x^%d: ", i);
    scanf("%f", &coefficients[i]);
  }

  // Displaying the polynomial
  printf("Your polynomial is : ");
  displayPolynomial(degree, coefficients);

  // Input divisor from the user
  printf("Enter the value of c for divisor (x-c): ");
  scanf("%f", &divisor);

  // Synthetic Division
  float quotient[degree - 1];
  float temp = coefficients[degree];
  quotient[degree - 1] = temp;

  for (i = degree - 1; i >= 0; i--)
  {
    if (i != 0)
    {
      temp = temp * divisor + coefficients[i];
      quotient[i - 1] = temp;
    }
    else
      temp = temp * divisor + coefficients[i]; // remainder
  }

  // Quotient
  printf("Quotient : ");
  displayPolynomial(degree - 1, quotient);

  // Remainder
  printf("Remainder : %.0f\n", temp);
}
