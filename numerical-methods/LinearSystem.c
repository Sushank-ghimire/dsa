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
void jacobiMethod(){}

// Gauss Seidel Method
void gaussSeidelMethod(){}
