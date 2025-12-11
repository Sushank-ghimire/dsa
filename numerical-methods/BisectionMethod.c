#include <stdio.h>
#include <math.h>

float f(float x) {
    return (x * x - 4);   // Function: x^2 - 4
}

int main() {
    float a, b, mid;
    int iteration = 0;
    float tolerance = 0.0001;  // desired accuracy

    // Taking user input
    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);

    // Check if the given interval is valid
    if (f(a) * f(b) > 0) {
        printf("Invalid interval! f(a) and f(b) must have opposite signs.\n");
        return 0;
    }

    if (f(a) == 0.0)
    {
      printf("\nRoot of the equation is: %.5f\n", a);
      return 0;
    }
    if (f(b) == 0.0)
    {
      printf("\nRoot of the equation is: %.5f\n", b);
      return 0;
    }

    printf("\nIter \t   a\t\t   b\t\t   mid\t\t f(mid)\n");

    // Bisection Method
    do {
        mid = (a + b) / 2.0;
        iteration++;

        printf("%d\t%f\t%f\t%f\t%f\n", iteration, a, b, mid, f(mid));

        if (f(a) * f(mid) < 0)
            b = mid;
        else
            a = mid;

    } while (fabs(f(mid)) > tolerance);

    printf("\nRoot of the equation is approximately: %.5f\n", mid);

    return 0;
}

