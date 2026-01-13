#include <stdio.h>
#define MAX 40

void NewtonBackwardDiff();
void NewtonForwardDiff();

int main() {
  int choice;

  do {
    printf("\n1. Newton's Backward Difference");
    printf("\n2. Newton's Forward Difference");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        NewtonBackwardDiff();
        break;
      case 2:
        NewtonForwardDiff();
        break;
      case 3:
        printf("\nExiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 3);

  return 0;
}

void NewtonBackwardDiff() {
  float x[MAX], diffTable[MAX][MAX], point, interpolatedY = 0, productTerm, p, stepSize, factorial;
  int terms, i, j, flag = 1;
  printf("Enter the number of terms of the table : ");
  scanf("%d", &terms);
  printf("Enter the corresponding values of x & y: \n");
  for(i=0; i<terms; i++) {
    printf("Enter the value for x[%d]: ", i+1);
    scanf("%f", &x[i]);
    printf("Enter the value for y[%d]: ", i+1);
    scanf("%f", &diffTable[i][0]);
  }

  // Divided difference table calucation
  for(j=1; j<terms; j++) {
    for(i=terms - 1; i>=j; i--) {
      diffTable[i][j] = (diffTable[i][j-1]) - diffTable[i-1][j-1];
    }
  }

  printf("\nBackward Difference Table:\n");
  for (i = 0; i < terms; i++) {
    for (j=0; j<= i; j++) {
      printf("%8.4f ", diffTable[i][j]);
    }
    printf("\n");
  }

  stepSize = x[1] - x[0];

  while (flag) {
    printf("Enter the value of the x to find value of y: ");
    scanf("%f", &point);

    p = (point - x[terms-1]) / stepSize;
    interpolatedY = diffTable[terms - 1][0];
    productTerm = 1;
    factorial = 1;

    for(i=1; i<terms; i++) {
      productTerm *= (p + (i - 1));
      factorial *= i;
      interpolatedY += (productTerm / factorial) * diffTable[terms - 1][i];
    }

    printf("\nThe interpolated value at x = %.4f is y = %.4f",point, interpolatedY);
    printf("\nDo you want to continue with same data points (0 to exit) ? ");
    scanf("%d", &flag);
  }
}

void NewtonForwardDiff() {
  float x[MAX], diffTable[MAX][MAX], point, interpolatedY = 0, productTerm, p, stepSize, factorial;
  int terms, i, j, flag = 1;
  printf("Enter the number of terms of the table : ");
  scanf("%d", &terms);
  printf("Enter the corresponding values of x & y: \n");
  for(i=0; i<terms; i++) {
    printf("Enter the value for x[%d]: ", i+1);
    scanf("%f", &x[i]);
    printf("Enter the value for y[%d]: ", i+1);
    scanf("%f", &diffTable[i][0]);
  }

  // Divided difference table calucation
  for(j=1; j<terms; j++) {
    for(i=0; i<terms - j; i++) {
      diffTable[i][j] = (diffTable[i+1][j-1]) - diffTable[i][j-1];
    }
  }

  printf("\nForward Difference Table:\n");
  for (i = 0; i < terms; i++) {
    for (j = 0; j < terms - i; j++) {
      printf("%8.4f ", diffTable[i][j]);
    }
    printf("\n");
  }

  stepSize = x[1] - x[0];

  while (flag) {
    printf("Enter the value of the x to find value of y: ");
    scanf("%f", &point);

    p = (point - x[0]) / stepSize;
    interpolatedY = diffTable[0][0];
    productTerm = 1;
    factorial = 1;

    for(i=1; i<terms; i++) {
      productTerm *= (p - (i - 1));
      factorial *= i;
      interpolatedY += (productTerm / factorial) * diffTable[0][i];
    }

    printf("\nThe interpolated value at x = %.4f is y = %.4f",point, interpolatedY);
    printf("\nDo you want to continue with same data points (0 to exit) ? ");
    scanf("%d", &flag);
  }
}
