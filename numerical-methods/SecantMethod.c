#include <stdio.h>
#include <math.h>

// Function
double f(double x) {
    return x * x - 2;
}

int main() {
    double x0, x1, x, error;
    int iteration = 0, maxIterations;

    printf("Enter the initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter the initial guess x1: ");
    scanf("%lf", &x1);

    printf("Enter maximum iterations and allowed error: ");
    scanf("%d %lf", &maxIterations, &error);

    do {
        if (f(x1) == f(x0)) {
            printf("Error: Division by zero.\n");
            return 0;
        }

        x = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));

        printf("Iteration No-%d    x = %lf\n", ++iteration, x);

        if (iteration >= maxIterations)
            break;

        x0 = x1;
        x1 = x;

    } while (fabs(x1 - x0) > error);

    printf("\nThe required solution is %.5lf\n", x);

    return 0;
}

