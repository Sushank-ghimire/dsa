#include <stdio.h>

#define MAX 50

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
