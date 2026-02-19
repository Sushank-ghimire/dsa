#include <stdio.h>

// Helper functions
int inputInt(const char *msg);
double inputDouble(const char *msg);
double func(double x, double y);

// Ordinary Differential Equation Methods Prototype
void eulerMethod();
void heunMethod();
void taylorMethod();
void rungeKuttaMethod();
void picardMethod();

int main() {
  int choice;
  do {
    printf("1. Euler's Method\n");
    printf("2. Heun's Method\n");
    printf("3. Taylor Series Method\n");
    printf("4. Runge-Kutta Method (4th order)\n");
    printf("5. Picard’s Method\n");
    printf("6. Exit\n");

    choice = inputInt("Enter your choice: ");
    switch (choice) {
      case 1:
        eulerMethod();
        break;
      case 2:
        heunMethod();
        break;
      case 3:
        taylorMethod();
        break;
      case 4:
        rungeKuttaMethod();
        break;
      case 5:
        picardMethod();
        break;
      case 6:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
    printf("\n");
  } while (choice != 6);
  return 0;
}

int inputInt(const char *msg) {
  int val;
  printf("%s", msg);
  scanf("%d", &val);
  return val;
}

// Example differential function: dy/dx = f(x, y)
double func(double x, double y) {
  // Example: dy/dx = x + y
  return x + y;
}

double inputDouble(const char *msg) {
  double val;
  printf("%s", msg);
  scanf("%lf", &val);
  return val;
}

/* Euler's Method */
/*  Input:
 *      Enter initial x0: 0
 *      Enter initial y0: 1
 *      Enter x to find y at: 0.2
 *      Enter step size h: 0.1
 * Output:
 *      Approximate solution at x = 0.20 is y = 1.22
 */
void eulerMethod() {
  double x0 = inputDouble("Enter initial x0: ");
  double y0 = inputDouble("Enter initial y0: ");
  double xn = inputDouble("Enter x to find y at: ");
  double h = inputDouble("Enter step size h: ");

  double x = x0, y = y0;
  while (x < xn) {
    y = y + h * func(x, y);
    x += h;
  }
  printf("Approximate solution at x = %.2lf is y = %.2lf\n", x, y);
}

/* Heun's Method */
void heunMethod() {
  double x0 = inputDouble("Enter initial x0: ");
  double y0 = inputDouble("Enter initial y0: ");
  double xn = inputDouble("Enter x to find y at: ");
  double h = inputDouble("Enter step size h: ");

  double x = x0, y = y0;
  while (x < xn) {
    double k1 = func(x, y);
    double k2 = func(x + h, y + h * k1);
    y += (h / 2.0) * (k1 + k2);
    x += h;
  }
  printf("Approximate solution at x = %.2lf is y = %.2lf\n", x, y);
}

/* Taylor Series Method (2nd order) */
void taylorMethod() {
  double x0 = inputDouble("Enter initial x0: ");
  double y0 = inputDouble("Enter initial y0: ");
  double xn = inputDouble("Enter x to find y at: ");
  double h = inputDouble("Enter step size h: ");

  double x = x0, y = y0;
  while (x < xn) {
    double f = func(x, y);
    double f_prime = 1 + f; // Example: derivative of f w.r.t x (dy/dx = x+y => d²y/dx² = 1 + dy/dx)
    y += h * f + (h*h/2.0) * f_prime;
    x += h;
  }
  printf("Approximate solution at x = %.2lf is y = %.2lf\n", x, y);
}

/* Runge-Kutta Method (4th order) */
void rungeKuttaMethod() {
  double x0 = inputDouble("Enter initial x0: ");
  double y0 = inputDouble("Enter initial y0: ");
  double xn = inputDouble("Enter x to find y at: ");
  double h = inputDouble("Enter step size h: ");

  double x = x0, y = y0;
  while (x < xn) {
    double k1 = h * func(x, y);
    double k2 = h * func(x + h/2.0, y + k1/2.0);
    double k3 = h * func(x + h/2.0, y + k2/2.0);
    double k4 = h * func(x + h, y + k3);
    y += (k1 + 2*k2 + 2*k3 + k4)/6.0;
    x += h;
  }
  printf("Approximate solution at x = %.2lf is y = %.2lf\n", x, y);
}

/* Picard’s Method (1st iteration example) */
void picardMethod() {
  double x0 = inputDouble("Enter initial x0: ");
  double y0 = inputDouble("Enter initial y0: ");
  double xn = inputDouble("Enter x to find y at: ");
  int n = inputInt("Enter number of iterations: ");

  double y = y0;
  for (int i = 1; i <= n; i++) {
    // Example for dy/dx = x + y0 (replace y with previous approximation)
    y = y0 + (xn - x0) * func(x0, y0); // simple first iteration
    y0 = y; // update for next iteration
  }
  printf("Approximate solution at x = %.2lf is y = %.2lf\n", xn, y);
}
