#include <stdio.h>

int input(const char *msg);
double func(double x);

// Forward method functions
void forwardDifference();
void forwardDividedDifference();

// Backward method functions
void backwardDifference();
void backwardDividedDifference();

int main() {
  int choice;
  do {
    printf("1. Forward Difference\n");
    printf("2. Forward Divided Difference\n");
    printf("3. Backward Difference\n");
    printf("4. Backward Divided Difference\n");
    printf("5. Central Difference\n");
    printf("6. Exit\n");
    choice = input("Enter your choice : ");

    switch (choice) {
      case 1:
        forwardDifference();
        break;
      case 2:
        forwardDividedDifference();
        break;
      case 3:
        backwardDifference();
        break;
      case 4:
        backwardDividedDifference();
        break;
      case 6:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
    printf("\n");
  } while (choice != 6);
}

int input(const char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}

/* Function whose derivative is calculated */
double func(double x) {
  // f(x) = x^3 + 2x^2 - x + 1
  return (x*x*x + 2*x*x - x+1);
}

/*
 * Input:
 *      Enter the value of x: 2
 *      Enter the value of h (step size): 0.001
 * Output:
 *      Derivative at x = 2.00000 is 19.01
*/
void forwardDifference() {
  double x, h;

  printf("Enter the value of x: ");
  scanf("%lf", &x);

  printf("Enter the value of h (step size): ");
  scanf("%lf", &h);

  double derivative = (func(x+h) - func(x)) / h;
  printf("Derivative at x = %.2lf is %.2lf\n", x, derivative);
}

/*
 * Input:
 *      Enter x0 and y0: 1 2
 *      Enter x1 and y1: 2 5
 * Output:
 *      Derivative at x = 1.00 is 3.00
 */
void forwardDividedDifference() {
  double x0, x1, y0, y1;

  printf("Enter x0 and y0: ");
  scanf("%lf %lf", &x0, &y0);

  printf("Enter x1 and y1: ");
  scanf("%lf %lf", &x1, &y1);

  double derivative = (y1-y0) / (x1-x0);

  printf("Derivative at x = %.2lf is %.2lf\n", x0, derivative);
}

/*
 * Backward Divided Difference Formula:
 * f'(x) ≈ (f(x) - f(x - h)) / h
*/
void backwardDifference() {
  double x, h;

  printf("Enter the value of x: ");
  scanf("%lf", &x);

  printf("Enter the value of h (step size): ");
  scanf("%lf", &h);

  double derivative = (func(x) - func(x-h)) / h;
  printf("Derivative at x = %.2lf is %.2lf\n", x, derivative);
}

void backwardDividedDifference() {
  int n;

  n = input("Enter number of data points: ");
  scanf("%d", &n);
  if (n < 2) {
    printf("At least two data points are required.\n");
    return;
  }

  double x[n], y[n];
  printf("Enter the values of x and y:\n");
  for (int i = 0; i < n; i++) {
    printf("x[%d] y[%d]: ", i, i);
    scanf("%lf %lf", &x[i], &y[i]);
  }
  double derivative = (x[n-1] - x[n-2]) / (y[n-1] - y[n-2]);
  printf("Derivative at x = %.2lf is %.2lf\n", x[n-1], derivative);
}
