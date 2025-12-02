#include <stdio.h>
#include <math.h>


// define the function for the root finding
double f(double x) {
	return x*x - 4; // function f(x) = x^2-4
}

// define the derative of the function
double fd(double x) {
	return 2*x;
}

int main() {
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
			return 0;
		}
		x0 = x1;
	}
	return 0;
}
