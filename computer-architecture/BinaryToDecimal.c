// Write a program to convert a binary number into its decimal equivalent and vice versa.

#include <stdio.h>

void convertToDecimal() {
  int num, decimal = 0, base = 1, rem;
  printf("Enter a binary number to convert to the decimal : ");
  scanf("%d", &num);

  int temp = num;

  while (num > 0) {
    rem = num % 10;
    decimal = decimal + rem * base;
    base = base * 2;
    num = num / 10;
  }

  printf("The decimal of the binary number %d is %d.\n", temp, decimal);
}

void convertToBinary() {
  int decimal, arr[32], i = 0, temp;
  printf("Enter a decimal number to convert to binary : ");
  scanf("%d", &decimal);
  temp = decimal;
  if (decimal == 0) {
    printf("The binary of the decimal number 0 is 0.\n");
    return;
  }
  while (decimal > 0) {
    arr[i] = decimal % 2;
    decimal = decimal / 2;
    i++;
  }

  printf("The binary of the decimal number %d is : ", temp);
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", arr[j]);
  }
  printf("\n");
}

int main() {
  int choice;
  do {
    printf("\n1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      convertToBinary();
      break;
    case 2:
      convertToDecimal();
      break;
    case 3:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice!\n");
      break;
    }

  } while (choice != 3);
  return 0;
}
