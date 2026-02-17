#include <stdio.h>

// Helper Functions
int input(const char *msg);
double func(double x);

// Simpson's method functions
void simpsonsOneThird();
void compositeSimpsonsOneThird();
void simpsonsThreeEighth();
void compositeSimpsonsThreeEighth();

int main() {
  int choice;
  do {
    printf("1. Simpson's 1/3\n");
    printf("2. Composite Simpson's 1/3\n");
    printf("3. Simpson's 3/8\n");
    printf("4. Composite Simpson's 3/8\n");
    printf("5. Exit\n");
    choice = input("Enter your choice : ");

    switch (choice) {
      case 1:
        simpsonsOneThird();
        break;
      case 2:
        compositeSimpsonsOneThird();
        break;
      case 3:
        simpsonsThreeEighth();
        break;
      case 4:
        compositeSimpsonsThreeEighth();
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
    printf("\n");
  } while (choice != 5);
}

int input(const char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}

double func(double x) {
  // Example: f(x) = x^2
  return x * x;
}

/*
 * Formula: ∫[a to b] f(x) dx ≈ (h/3) * [f(a) + 4f((a+b)/2) + f(b)]
 * where h = (b-a)/2
 */
void simpsonsOneThird() {
  double a = input("Enter lower limit a: ");
  double b = input("Enter upper limit b: ");

  double h = (b - a) / 2.0;
  double result = (h / 3.0) * (func(a) + 4 * func(a + h) + func(b));
  printf("Approximate integral using Simpson's 1/3 rule: %.2lf\n", result);
}

/*
 * Formula: ∫[a to b] f(x) dx ≈ (h/3) * [f(x0) + 4(f(x1) + f(x3) + ...) + 2(f(x2) + f(x4) + ...) + f(xn)]
 * where n is even, h = (b-a)/n, xi = a + i*h
 */


void compositeSimpsonsOneThird() {
  double a, b;
  int n;

  a = input("Enter lower limit a: ");
  b = input("Enter upper limit b: ");
  printf("Enter subintervals n (must be even): ");
  scanf("%d", &n);

  if (n % 2 != 0) {
    printf("Error: n must be even.\n");
    return;
  }

  double h = (b - a) / n;
  double sum = func(a) + func(b);

  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    if (i % 2 == 0)
      sum += 2 * func(x); // even indices
    else
      sum += 4 * func(x); // odd indices
  }

  double result = (h / 3.0) * sum;
  printf("Approximate integral using Composite Simpson's 1/3 rule: %.2lf\n", result);
}

/*
 * Formula: ∫[a to b] f(x) dx ≈ (3h/8) * [f(a) + 3f(a+h) + 3f(a+2h) + f(b)]
 * where h = (b-a)/3
 */
void simpsonsThreeEighth() {
  double a = input("Enter lower limit a: ");
  double b = input("Enter upper limit b: ");

  double h = (b - a) / 3.0;
  double result = (3 * h / 8.0) * (func(a) + 3 * func(a + h) + 3 * func(a + 2 * h) + func(b));

  printf("Approximate integral using Simpson's 3/8 rule: %.2lf\n", result);
}

/*
 * ∫[a to b] f(x) dx ≈ (3h/8) * [f(x0) + 3(f(x1)+f(x2)+f(x4)+f(x5)+...) + 2(f(x3)+f(x6)+...) + f(xn)]
 * where n is multiple of 3, h = (b-a)/n, xi = a + i*h
 */
 void compositeSimpsonsThreeEighth() {
  double a, b;
  int n;

  printf("Enter lower limit a: ");
  scanf("%lf", &a);
  printf("Enter upper limit b: ");
  scanf("%lf", &b);
  printf("Enter subintervals n (must be multiple of 3): ");
  scanf("%d", &n);

  if (n % 3 != 0) {
    printf("Error: n must be a multiple of 3.\n");
    return;
  }

  double h = (b - a) / n;
  double sum = func(a) + func(b);

  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    if (i % 3 == 0)
      sum += 2 * func(x); // multiples of 3
    else
      sum += 3 * func(x); // others
  }

  double result = (3 * h / 8.0) * sum;
  printf("Approximate integral using Composite Simpson's 3/8 rule: %.2lf\n", result);
}
