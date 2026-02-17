#include <stdio.h>

int input(const char *msg);
double func(double);

// Functions for the trapezoidal different methods
void TrapezoidalRule();
void CompositeTrapezoidalRule();

int main() {
  int choice;
  do {
    printf("1. Trapezoidal Rule\n");
    printf("2. Composite Trapezoidal Rule\n");
    printf("3. Exit\n");
    choice = input("Enter your choice : ");

    switch (choice) {
      case 1:
        TrapezoidalRule();
        break;
      case 2:
        CompositeTrapezoidalRule();
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 3);
}

int input(const char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}

/* Example Function: f(x) = x^2 */
double func(double x) {
  return x * x;
}

void TrapezoidalRule() {
  double a, b, h, result;

  printf("Enter lower limit (a): ");
  scanf("%lf", &a);

  printf("Enter upper limit (b): ");
  scanf("%lf", &b);

  h = b - a;

  result = (h / 2) * (func(a) + func(b));

  printf("Approximate integral = %.2lf\n", result);
}

void CompositeTrapezoidalRule() {
  double a, b, h, sum = 0, result;
  int n;

  printf("Enter lower limit (a): ");
  scanf("%lf", &a);

  printf("Enter upper limit (b): ");
  scanf("%lf", &b);

  printf("Enter number of subintervals (n): ");
  scanf("%d", &n);

  h = (b - a) / n;

  sum = func(a) + func(b);

  for (int i = 1; i < n; i++) {
    sum += 2 * func(a + i * h);
  }

  result = (h / 2) * sum;

  printf("Approximate integral = %.2lf\n", result);
}
