#include <stdio.h>
#include <math.h>

#define MAX 50
#define EPSILON 1e-6
/*
 * input: 2
 *        2 1 5
 *        4 4 16
 * Output:
 *        x1 = 1.00
 *        x2 = 3.00
 */

int input(const char *msg);

// Method of gauss elimination
void performGaussElimination();
void gaussElimination(int n, float matrix[MAX][MAX+1], float solution[MAX]);

// Partial pivoting
void swapRows(int n, float matrix[MAX][MAX+1], int row1, int row2);
void performPartialPivoting();
void gaussEliminationWithPivoting(int n, float matrix[MAX][MAX+1], float solution[MAX]);

// Gauss Jordan
void performGaussJordan();
void gaussJordan(int n, float matrix[MAX][MAX+1], float solution[MAX]);

int main() {
  int choice;
  do {
    printf("1. Gauss Elimination\n");
    printf("2. Gauss Elimination (partial pivoting)\n");
    printf("3. Gauss Jordan\n");
    printf("4. Matrix Inversion (Gauss Jordan)\n");
    printf("5. Exit\n");
    choice = input("Enter your choice : ");

    switch(choice) {
      case 1:
        performGaussElimination();
        break;
      case 2:
        performPartialPivoting();
        break;
      case 3:
        performGaussJordan();
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!");
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

// Gauss Elimination
void performGaussElimination() {
  int n;
  float matrix[MAX][MAX+1];
  float solution[MAX];

  n = input("Enter the order of the matrix: ");

  printf("Enter the augmented matrix (row-wise):\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      printf("A[%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matrix[i][j]);
    }
  }

  gaussElimination(n, matrix, solution);

  printf("\nSolution:\n");
  for (int i = 0; i < n; i++)
    printf("x%d = %.2f\n", i + 1, solution[i]);
  printf("\n");
}

void gaussElimination(int n, float matrix[MAX][MAX + 1], float solution[MAX]) {
  float factor, sum;

  /* Forward Elimination */
  for (int i = 0; i < n - 1; i++) {

    if (fabs(matrix[i][i]) < EPSILON) {
      printf("Mathematical Error: Division by zero.\n");
      return;
    }

    for (int j = i + 1; j < n; j++) {
      factor = matrix[j][i] / matrix[i][i];

      for (int k = i; k <= n; k++) {
        matrix[j][k] -= factor * matrix[i][k];
      }
    }
  }

  /* Back Substitution */
  for (int i = n - 1; i >= 0; i--) {
    sum = matrix[i][n];

    for (int j = i + 1; j < n; j++) {
      sum -= matrix[i][j] * solution[j];
    }

    if (fabs(matrix[i][i]) < EPSILON) {
      printf("Mathematical Error: Division by zero.\n");
      return;
    }

    solution[i] = sum / matrix[i][i];
  }
}

// Partial Pivoting (Gauss Elimination)
void swapRows(int n, float matrix[MAX][MAX + 1], int row1, int row2) {
  for (int j = 0; j <= n; j++) {
    float temp = matrix[row1][j];
    matrix[row1][j] = matrix[row2][j];
    matrix[row2][j] = temp;
  }
}

void performPartialPivoting() {
  int n;
  float matrix[MAX][MAX + 1];
  float solution[MAX];

  n = input("Enter the order of the matrix: ");

  printf("Enter the augmented matrix (row-wise):\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      printf("A[%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matrix[i][j]);
    }
  }

  gaussEliminationWithPivoting(n, matrix, solution);

  printf("\nSolution:\n");
  for (int i = 0; i < n; i++) {
      printf("x%d = %.2f\n", i + 1, solution[i]);
  }
}

void gaussEliminationWithPivoting(int n, float matrix[MAX][MAX + 1], float solution[MAX]) {
  float factor, sum;
  int maxRow;

  /* Forward Elimination with Partial Pivoting */
  for (int i = 0; i < n - 1; i++) {

    /* Find row with maximum pivot element */
    maxRow = i;
    for (int k = i + 1; k < n; k++) {
      if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i]))
        maxRow = k;
    }

    /* Swap rows if needed */
    if (maxRow != i) {
      swapRows(n, matrix, i, maxRow);
    }

    if (fabs(matrix[i][i]) < 1e-6) {
      printf("Mathematical Error: Division by zero detected.\n");
      return;
    }

    for (int j = i + 1; j < n; j++) {
      factor = matrix[j][i] / matrix[i][i];

      for (int k = i; k <= n; k++)
        matrix[j][k] -= factor * matrix[i][k];

    }
  }

  /* Back Substitution */
  for (int i = n - 1; i >= 0; i--) {
    sum = matrix[i][n];

    for (int j = i + 1; j < n; j++)
      sum -= matrix[i][j] * solution[j];

    if (fabs(matrix[i][i]) < 1e-6) {
      printf("Mathematical Error: Division by zero detected.\n");
      return;
    }

    solution[i] = sum / matrix[i][i];
  }
}

// Gauss Jordan Method
void performGaussJordan() {
  int n;
  float matrix[MAX][MAX + 1];
  float solution[MAX];

  n = input("Enter the order of the matrix: ");

  printf("Enter the augmented matrix (row-wise):\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      printf("A[%d][%d]: ", i + 1, j + 1);
      scanf("%f", &matrix[i][j]);
    }
  }

  gaussJordan(n, matrix, solution);

  printf("\nSolution:\n");
  for (int i = 0; i < n; i++)
    printf("x%d = %.4f\n", i + 1, solution[i]);
}

void gaussJordan(int n, float matrix[MAX][MAX + 1], float solution[MAX]) {

  for (int i = 0; i < n; i++) {

    if (fabs(matrix[i][i]) < 1e-6) {
      printf("Mathematical Error: Division by zero detected.\n");
      return;
    }

    /* Make pivot element 1 */
    float pivot = matrix[i][i];
    for (int j = 0; j <= n; j++)
      matrix[i][j] /= pivot;

    /* Eliminate other rows */
    for (int k = 0; k < n; k++) {
      if (k != i) {
        float factor = matrix[k][i];
        for (int j = 0; j <= n; j++)
          matrix[k][j] -= factor * matrix[i][j];
      }
    }
  }

  /* Extract solutions */
  for (int i = 0; i < n; i++)
    solution[i] = matrix[i][n];
}
