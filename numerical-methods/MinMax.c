#include <stdio.h>
#define MAX 30

void findMinMax(float x[], float y[], int n);

int main() {
  int choice;
  float x[MAX], y[MAX];
  int terms, i, dataAvailable = 0, dataChoice = 2;
  do {
    printf("1. Find Maxima/Minima\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (dataAvailable && choice == 1) {
      printf("\n1. Use previous table\n");
      printf("2. Enter new table\n");
      printf("Enter your choice: ");
      scanf("%d", &dataChoice);
    }
    if((!dataAvailable || dataChoice == 2) && choice == 1) {
      printf("Enter the number of terms of the table : ");
      scanf("%d", &terms);
      printf("Enter the corresponding values of x & y: \n");

      for (i = 0; terms > i; i++) {
        printf("Enter the value for x[%d]: ", i+1);
        scanf("%f", &x[i]);
        printf("Enter the value for y[%d]: ", i+1);
        scanf("%f", &y[i]);
      }

      dataAvailable = 1;
      printf("\nThe table values you entered are as follows : \n");
      printf("x\t\ty\n");
      for (i=0; i<terms; i++) {
        printf("%.2f\t\t%.2f\n", x[i], y[i]);
      }
    }

    switch (choice) {
      case 1:
        findMinMax(x, y, terms);
        break;
      case 2:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 2);
  return 0;
}

void findMinMax(float x[], float y[], int n) {
  int i;
  float maxY = y[0], minY = y[0];
  float maxX = x[0], minX = x[0];

  for (i = 1; i < n; i++) {
    if (y[i] > maxY) {
      maxY = y[i];
      maxX = x[i];
    }
    if (y[i] < minY) {
      minY = y[i];
      minX = x[i];
    }
  }

  printf("\nMaximum Value: y = %.4f at x = %.4f\n", maxY, maxX);
  printf("Minimum Value: y = %.4f at x = %.4f\n", minY, minX);
}
