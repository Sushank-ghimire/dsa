// Write a program to perform binary addition and binary subtraction of two binary numbers.
#include <stdio.h>

void binaryAddition() {
  int num1, num2, sum = 0, carry = 0, rem1, rem2, place = 1;
  printf("Enter first binary number: ");
  scanf("%d", &num1);
  printf("Enter second binary number: ");
  scanf("%d", &num2);

  int temp1 = num1, temp2 = num2;

  while (num1 > 0 || num2 > 0 || carry > 0) {
    rem1 = num1 % 10;
    rem2 = num2 % 10;

    int s = rem1 + rem2 + carry;
    sum = sum + (s % 2) * place;
    carry = s / 2;

    place = place * 10;
    num1 = num1 / 10;
    num2 = num2 / 10;
  }
  printf("The binary sum of %d and %d is %d.\n", temp1, temp2, sum);
}

void binarySubtraction() {
  int num1, num2, ones = 0, place = 1, rem;
  printf("Enter first binary number: ");
  scanf("%d", &num1);
  printf("Enter second binary number: ");
  scanf("%d", &num2);

  int temp1 = num1, temp2 = num2;

  int temp = num2;
  while (temp > 0) {
    rem = temp % 10;
    if (rem == 0)
        ones = ones + 1 * place;
    else
        ones = ones + 0 * place;

    place = place * 10;
    temp = temp / 10;
  }
  int twos = ones + 1;

  int result = 0, carry = 0;
  place = 1;

  while (num1 > 0 || twos > 0) {
    int r1 = num1 % 10;
    int r2 = twos % 10;

    int s = r1 + r2 + carry;
    result = result + (s % 2) * place;
    carry = s / 2;

    place = place * 10;
    num1 = num1 / 10;
    twos = twos / 10;
  }

  printf("The binary difference of %d and %d is %d\n", temp1, temp2, result);
}

int main() {
  int choice;
  do {
    printf("1. Binary Addition\n");
    printf("2. Binary Subtraction\n");
    printf("3. Exit\n");

    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        binaryAddition();
        break;
      case 2:
        binarySubtraction();
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  }while (choice != 3);
  return 0;
}
