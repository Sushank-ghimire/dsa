#include <stdio.h>

void signedTwosComplementAddition() {
  int num1, num2, sum;

  printf("Enter first number (signed, 2's complement): ");
  scanf("%d", &num1);
  printf("Enter second number (signed, 2's complement): ");
  scanf("%d", &num2);

  sum = num1 + num2; // Direct addition

  printf("Addition(2's complement addition) of %d and %d is %d\n", num1, num2, sum);
}

void signedTwosComplementSubtraction() {
  int num1, num2, diff;

  printf("Enter first number (signed, 2's complement): ");
  scanf("%d", &num1);
  printf("Enter second number (signed, 2's complement): ");
  scanf("%d", &num2);

  diff = num1 - num2; // Direct subtraction

  printf("Subtraction (2's complement subtraction) of %d and %d is %d\n", num1, num2, diff);
}

int main() {
  int choice;

  do {
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        signedTwosComplementAddition();
        break;
      case 2:
        signedTwosComplementSubtraction();
        break;
      case 3:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice! Please enter 1, 2, or 3.\n");
      }
  } while (choice != 3);

  return 0;
}
