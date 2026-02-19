#include <stdio.h>

// Helper functions
int inputInt(const char *msg);
double inputDouble(const char *msg);

// Partial Differential Equation Methods Prototype
void ellipticPDE(int m, int n, double left, double right, double top, double bottom, int iterations);
void poissonEquation(int m, int n, double left, double right, double top, double bottom, int iterations);

int main() {
  int choice, m, n, iterations = 0;
  double left, right, top, bottom;
  do {
    printf("1. Elliptic PDE (Laplace Equation)\n");
    printf("2. Poisson Equation\n");
    printf("3. Exit\n");

    choice = inputInt("Enter your choice: ");
    if(choice < 3 && choice >= 1) {
      // Grid size input
      m = inputInt("Enter grid size in x-direction (rows): ");
      n = inputInt("Enter grid size in y-direction (columns): ");

      left = inputDouble("Enter left boundary value: ");
      right = inputDouble("Enter right boundary value: ");
      top = inputDouble("Enter top boundary value: ");
      bottom = inputDouble("Enter bottom boundary value: ");

      // Number of iterations
      iterations = inputInt("Enter number of iterations: ");
    }
    switch (choice) {
      case 1:
        ellipticPDE(m, n, left, right, top, bottom, iterations);
        break;
      case 2:
        poissonEquation(m, n, left, right, top, bottom, iterations);
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 3);
  printf("\n");
  return 0;
}

int inputInt(const char *msg) {
  int val;
  printf("%s", msg);
  scanf("%d", &val);
  return val;
}

double inputDouble(const char *msg) {
  double val;
  printf("%s", msg);
  scanf("%lf", &val);
  return val;
}

/* Elliptic PDE (Laplace equation) using Jacobi method */
/* Input:
 *      Enter grid size in x-direction (rows): 3
 *      Enter grid size in y-direction (columns): 3
 *      Enter left boundary value: 0
 *      Enter right boundary value: 100
 *      Enter top boundary value: 0
 *      Enter bottom boundary value: 0
 *      Enter number of iterations: 10
 * Output:
 *      Solution after 10 iterations:
 *      0.00    0.00   100.00
 *      0.00   25.00    50.00
 *      0.00    0.00   100.00

 */
void ellipticPDE(int m, int n, double left, double right, double top, double bottom, int iterations) {
  double u[m][n], u_new[m][n];

  // Initialize grid to 0
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      u[i][j] = 0;

  // Apply boundary conditions
  for(int i = 0; i < m; i++){
    u[i][0] = left;
    u[i][n-1] = right;
  }
  for(int j = 0; j < n; j++){
    u[0][j] = top;
    u[m-1][j] = bottom;
  }

  // Jacobi iteration
  for(int it = 0; it < iterations; it++){
    for(int i = 1; i < m-1; i++){
      for(int j = 1; j < n-1; j++){
        u_new[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]);
      }
    }
    // Update values
    for(int i = 1; i < m-1; i++)
      for(int j = 1; j < n-1; j++)
        u[i][j] = u_new[i][j];
  }

  // Print final solution
  printf("Solution after %d iterations:\n", iterations);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)
      printf("%6.2lf ", u[i][j]);
    printf("\n");
  }
}


/* Poisson Equation: ∇²u = f(x,y) using Jacobi method */
void poissonEquation(int m, int n, double left, double right, double top, double bottom, int iterations) {
  double u[m][n], u_new[m][n], f[m][n];

  // Initialize u to 0
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      u[i][j] = 0;

  for(int i = 0; i < m; i++){
    u[i][0] = left;
    u[i][n-1] = right;
  }
  for(int j = 0; j < n; j++){
    u[0][j] = top;
    u[m-1][j] = bottom;
  }

  // Input source term f(x,y)
  printf("Enter source term f(x,y) for each grid point:\n");
  for(int i = 1; i < m-1; i++){
    for(int j = 1; j < n-1; j++){
      printf("f[%d][%d] = ", i, j);
      scanf("%lf", &f[i][j]);
    }
  }

  // Jacobi iteration
  for(int it = 0; it < iterations; it++){
    for(int i = 1; i < m-1; i++){
      for(int j = 1; j < n-1; j++){
        u_new[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1] - f[i][j]);
      }
    }
    // Update grid values
    for(int i = 1; i < m-1; i++)
      for(int j = 1; j < n-1; j++)
        u[i][j] = u_new[i][j];
  }

  // Print solution
  printf("Poisson equation solution after %d iterations:\n", iterations);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)
      printf("%8.3lf ", u[i][j]);
    printf("\n");
  }
}
