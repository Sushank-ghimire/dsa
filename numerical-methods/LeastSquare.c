#include <stdio.h>
#include <math.h>
#define MAX 30

void LinearLeastSq(float x[], float y[], int n);
void PolynomialReg(float x[], float y[], int n);
void ExponentialReg(float x[], float y[], int n);

int main() {
  int choice;
  float x[MAX], y[MAX], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
  int terms, i, j, flag = 1, dataAvailable = 0;
  do {
    printf("\n--- Least Square Approximation ---\n");
    printf("1. Linear Least Square\n");
    printf("2. Polynomial Regression (Quadratic)\n");
    printf("3. Exponential Regression\n");
    printf("4. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    if(choice <= 3 && choice >= 1) {
      int dataChoice = 2;
      if (dataAvailable) {
        printf("\n1. Use previous table\n");
        printf("2. Enter new table\n");
        printf("Enter your choice: ");
        scanf("%d", &dataChoice);
      }
      if(!dataAvailable || dataChoice == 2) {
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
      }
      printf("\nThe table values you entered are as follows : \n");
      printf("x\t\ty\n");
      for (i=0; i<terms; i++) {
        printf("%.2f\t\t%.2f\n", x[i], y[i]);
      }
      switch (choice) {
        case 1:
          LinearLeastSq(x, y, terms);
          break;
        case 2:
          PolynomialReg(x, y, terms);
          break;
        case 3:
          ExponentialReg(x, y, terms);
          break;
      }
    } else if (choice == 4) {
      printf("Exiting program...\n");
    } else {
     printf("Invalid choice!\n");
    }
  } while (choice != 4);
  return 0;
}

void LinearLeastSq(float x[], float y[], int n){
  float sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
  float a, b;
  int i;

  for (i = 0; i < n; i++) {
    sumx += x[i];
    sumy += y[i];
    sumxy += x[i] * y[i];
    sumx2 += x[i] * x[i];
  }
  b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
  a = (sumy - b * sumx) / n;
  printf("\nThe linear least square equation is : \n");
  printf("y = %.4f + %.4fx\n", a, b);
}

void PolynomialReg(float x[], float y[], int n){
  float sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0;
  float sumy = 0, sumxy = 0, sumx2y = 0;
  float a, b, c;
  int i;

  for (i = 0; i < n; i++) {
    sumx += x[i];
    sumx2 += x[i] * x[i];
    sumx3 += x[i] * x[i] * x[i];
    sumx4 += x[i] * x[i] * x[i] * x[i];
    sumy += y[i];
    sumxy += x[i] * y[i];
    sumx2y += x[i] * x[i] * y[i];
  }
  float D = n*(sumx2*sumx4 - sumx3*sumx3) - sumx*(sumx*sumx4 - sumx2*sumx3) + sumx2*(sumx*sumx3 - sumx2*sumx2);

  float Da = sumy*(sumx2*sumx4 - sumx3*sumx3) - sumx*(sumxy*sumx4 - sumx3*sumx2y) + sumx2*(sumxy*sumx3 - sumx2*sumx2y);

  float Db = n*(sumxy*sumx4 - sumx3*sumx2y) - sumy*(sumx*sumx4 - sumx2*sumx3) + sumx2*(sumx*sumx2y - sumx2*sumxy);

  float Dc = n*(sumx2*sumx2y - sumx3*sumxy) - sumx*(sumx*sumx2y - sumx2*sumxy) + sumy*(sumx*sumx3 - sumx2*sumx2);

  a = Da / D;
  b = Db / D;
  c = Dc / D;

  printf("\nThe polynomial regression equation is : \n");
  printf("y = %.4f + %.4fx + %.4fx^2\n", a, b, c);
}

void ExponentialReg(float x[], float y[], int n){
  float sumx = 0, sumlny = 0, sumxlny = 0, sumx2 = 0;
  float a, b;
  int i;

  for (i = 0; i < n; i++) {
    sumx += x[i];
    sumlny += log(y[i]);
    sumxlny += x[i] * log(y[i]);
    sumx2 += x[i] * x[i];
  }

  b = (n * sumxlny - sumx * sumlny) / (n * sumx2 - sumx * sumx);
  a = exp((sumlny - b * sumx) / n);

  printf("\nThe exponential regression equation is : \n");
  printf("y = %.4f * e^(%.4fx)\n", a, b);
}
