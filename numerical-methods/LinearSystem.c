#include <stdio.h>
#include <math.h>

#define MAX 50
#define EPSILON 1e-6

int input(const char *msg);

// Function Prototypes
void doLittleLU();
void choleskyMethod();
void jacobiMethod();
void gaussSeidelMethod();

int main() {
  int choice;
  do {
    printf("1. Do-Little LU Decomposition\n");
    printf("2. Cholesky Method\n");
    printf("3. Jacobi Iteration Method\n");
    printf("4. Gauss-Seidel Method\n");
    printf("5. Exit\n");

    choice = input("Enter your choice : ");
    switch (choice) {
      case 1:
        doLittleLU();
        break;
      case 2:
        choleskyMethod();
        break;
      case 3:
        jacobiMethod();
        break;
      case 4:
        gaussSeidelMethod();
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);
  return 0;
}

int input(const char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}

// Do Little LU
/*
 * Input: Enter the order of the square matrix: 3
 *        2 -1 -2
 *       -4  6  3
 *       -4 -2  8
 * Lower Triangular Matrix (L):
 *        1.00  0.00  0.00
 *       -2.00  1.00  0.00
 *       -2.00 -1.00  1.00
 * Upper Triangular Matrix (U):
 *        2.00 -1.00 -2.00
 *        0.00  4.00 -1.00
 *        0.00  0.00  3.00
 */
void doLittleLU() {
  int n;
  float A[MAX][MAX];
  float L[MAX][MAX];
  float U[MAX][MAX];

  n = input("Enter the order of the square matrix : ");
  printf("Enter the matrix elements (row-wise):\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("A[%d][%d]: ", i+1, j+1);
      scanf("%f", &A[i][j]);
    }
  }

  /* Initialize L and U to zero */
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      L[i][j] = 0;
      U[i][j] = 0;
    }
  }

  /* Do-Little LU Decomposition */
  for(int i = 0; i < n; i++) {
    /* Compute U matrix */
    for(int k = i; k < n; k++) {
      float sum = 0;
      for(int j = 0; j < i; j++)
        sum += L[i][j] * U[j][k];

      U[i][k] = A[i][k] - sum;
    }

    /* Check for zero pivot */
    if(fabs(U[i][i]) < EPSILON) {
      printf("Mathematical Error: Division by zero.\n");
      return;
    }

    /* Compute L matrix */
    for(int k = i; k < n; k++) {
      if(i == k)
        L[i][i] = 1;  // Diagonal = 1
      else {
        float sum = 0;
        for(int j = 0; j < i; j++)
          sum += L[k][j] * U[j][i];

        L[k][i] = (A[k][i] - sum) / U[i][i];
      }
    }
    }

  /* Display L matrix */
  printf("\nLower Triangular Matrix (L):\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      printf("%8.2f ", L[i][j]);
    printf("\n");
  }

  /* Display U matrix */
  printf("\nUpper Triangular Matrix (U):\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      printf("%8.2f ", U[i][j]);
    printf("\n");
  }
}

// Cholesky Method
/*
 * Input Example:
 * Enter the order of the square matrix: 3
 * Enter the matrix elements (row-wise):
 * A[1][1]: 4
 * A[1][2]: 12
 * A[1][3]: -16
 * A[2][1]: 12
 * A[2][2]: 37
 * A[2][3]: -43
 * A[3][1]: -16
 * A[3][2]: -43
 * A[3][3]: 98
 *
 * Output:
 * Lower Triangular Matrix (L):
 *  2.00  0.00  0.00
 *  6.00  1.00  0.00
 * -8.00  5.00  3.00
 */
void choleskyMethod() {
  int n;
  float A[MAX][MAX], L[MAX][MAX];

  n = input("Enter the order of the square matrix : ");
  printf("Enter the matrix elements (row-wise):\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("A[%d][%d]: ", i+1, j+1);
      scanf("%f", &A[i][j]);
    }
  }

  /* Initialize L to zero */
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      L[i][j] = 0;

  /* Cholesky Decomposition */
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      float sum = 0;
      for(int k = 0; k < j; k++)
        sum += L[i][k] * L[j][k];

      if(i == j) {
        float val = A[i][i] - sum;
        if(val < 0) {
          printf("Matrix is not positive definite.\n");
          return;
        }
        L[i][j] = sqrt(val);
      } else {
        if(fabs(L[j][j]) < EPSILON) {
          printf("Mathematical Error: Division by zero.\n");
          return;
        }
        L[i][j] = (A[i][j] - sum) / L[j][j];
      }
    }
  }

  /* Display L matrix */
  printf("\nLower Triangular Matrix (L):\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      printf("%8.2f ", L[i][j]);
    printf("\n");
  }
}

// Jacobi Method
/*
 * Solves Ax = b iteratively using Jacobi method.
 * Input Example same for (Gauss-Seidel Method):
 * Enter the order of the system: 3
 * Enter the coefficients row-wise:
 * A[1][1]: 10
 * A[1][2]: -1
 * A[1][3]: 2
 * A[2][1]: -1
 * A[2][2]: 11
 * A[2][3]: -1
 * A[3][1]: 2
 * A[3][2]: -1
 * A[3][3]: 10
 * Enter the constants (b):
 * b[1]: 6
 * b[2]: 25
 * b[3]: -11
 *
 * Output:
 * Solution vector x:
 * x1 = 1.00
 * x2 = 2.00
 * x3 = -1.00
 */
void jacobiMethod() {
  int n, i, j, iter = 0;
  float A[MAX][MAX], b[MAX], x[MAX], x_new[MAX];

  n = input("Enter the order of the system: ");
  printf("Enter the coefficients row-wise:\n");
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) {
      printf("A[%d][%d]: ", i+1, j+1);
      scanf("%f", &A[i][j]);
    }

  printf("Enter the constants (b):\n");
  for(i = 0; i < n; i++) {
    printf("b[%d]: ", i+1);
    scanf("%f", &b[i]);
    x[i] = 0;  // Initial guess
  }

  while(1) {
    for(i = 0; i < n; i++) {
      float sum = 0;
      for(j = 0; j < n; j++) {
        if(j != i)
          sum += A[i][j] * x[j];
      }
      if(fabs(A[i][i]) < EPSILON) {
        printf("Mathematical Error: Division by zero.\n");
        return;
      }
      x_new[i] = (b[i] - sum) / A[i][i];
    }

    // Check for convergence
    float max_diff = 0;
    for(i = 0; i < n; i++) {
      float diff = fabs(x_new[i] - x[i]);
      if(diff > max_diff)
        max_diff = diff;
      x[i] = x_new[i];
    }

    iter++;
    if(max_diff < EPSILON || iter > 1000) break;  // Max iterations to avoid infinite loop
    printf("\nSolution vector x:\n");
    for(i = 0; i < n; i++)
      printf("x%d = %.2f\n", i+1, x[i]);
  }
}

// Gauss Seidel Method
/*
 * Solves Ax = b iteratively using Gauss-Seidel method.
 * Input and output similar to Jacobi.
 */
void gaussSeidelMethod (){
  int n, i, j, iter = 0;
  float A[MAX][MAX], b[MAX], x[MAX];

  n = input("Enter the order of the system: ");
  printf("Enter the coefficients row-wise:\n");
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) {
      printf("A[%d][%d]: ", i+1, j+1);
      scanf("%f", &A[i][j]);
    }

  printf("Enter the constants (b):\n");
  for(i = 0; i < n; i++) {
    printf("b[%d]: ", i+1);
    scanf("%f", &b[i]);
    x[i] = 0;  // Initial guess
  }

  while(1) {
    float max_diff = 0;
    for(i = 0; i < n; i++) {
      float sum = 0;
      for(j = 0; j < n; j++) {
        if(j != i)
            sum += A[i][j] * x[j];
      }
      if(fabs(A[i][i]) < EPSILON) {
        printf("Mathematical Error: Division by zero.\n");
        return;
      }
      float x_old = x[i];
      x[i] = (b[i] - sum) / A[i][i];
      float diff = fabs(x[i] - x_old);
      if(diff > max_diff)
        max_diff = diff;
    }
    iter++;
    if(max_diff < EPSILON || iter > 1000) break;  // Convergence or max iterations
  }
  printf("\nSolution vector x:\n");
  for(i = 0; i < n; i++)
    printf("x%d = %.2f\n", i+1, x[i]);
}
