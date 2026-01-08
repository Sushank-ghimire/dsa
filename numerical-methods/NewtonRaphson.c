#include <stdio.h>
#include <math.h>

// Function Declarations
double f(double x);
double fd(double x);
void NewtonRaphsonMethod();

int main() {
  int choice;

  do {
    printf("\n1. Newton Raphson Method");
    printf("\n2. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        NewtonRaphsonMethod();
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

// Function definations
double f(double x) {
  return x * x * x - x - 1;
}

double fd(double x) {
  return 3*x*x - 1;
}

void NewtonRaphsonMethod() {
	int iteration, maxIterations;
	double x0, x1, error, h;
	printf("Enter x0 and allowed error : ");
	scanf("%lf %lf", &x0, &error);

	printf("Enter the value of maximum iterations : ");
	scanf("%d", &maxIterations);

	for(iteration=1; iteration <= maxIterations; iteration++) {
		h = f(x0)/fd(x0);
		x1 = x0 - h;
		printf("Iterations : %d, Root : %lf\n", iteration, x1);

		if(fabs(h) < error) {
			printf("\nAfter %d iterations, root = %.5lf\n", iteration, x1);
			return;
		}
		x0 = x1;
	}
}
