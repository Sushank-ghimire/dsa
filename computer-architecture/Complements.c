// Write a program to find the 1’s complement and 2’s complement of a given binary number.
#include <stdio.h>

void onesComplement() {
  int binary, remainder, result = 0, place = 1;
  printf("Enter a binary number: ");
  scanf("%d", &binary);

  int temp = binary;

  while (temp > 0) {
    remainder = temp % 10;
    if(remainder == 0)
      result = result + 1 * place;
    else
      result = result + 0 * place;
    place *= 10;
    temp /= 10;
  }
  printf("1's complement of %d is %d.\n", binary, result);
}

void twosComplement() {
  int binary, rem, ones = 0, place = 1, carry = 1;
  printf("Enter a binary number: ");
  scanf("%d", &binary);

  int temp = binary;

  while (temp > 0) {
    rem = temp % 10;
    if(rem == 0)
      ones = ones + 1 * place;
    else
     ones = ones + 0 * place;
    place *= 10;
    temp /= 10;
  }
  int twos = ones;
  place = 1;

  while(carry) {
    if((twos/place) % 10 == 0) {
      twos += place;
      carry = 0;
    } else {
      twos -= place;
      place *= 10;
    }
  }
  printf("2's Complement of %d is %d\n", binary, twos);
}

int main() {
  int choice;
  do {
    printf("\n1. 1's Complement\n");
    printf("2. 2's Complement\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        onesComplement();
        break;
      case 2:
        twosComplement();
        break;
      case 3:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 3);
  return 0;
}
