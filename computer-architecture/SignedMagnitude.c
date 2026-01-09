#include <stdio.h>

void signedMagnitudeAddition() {
  int signA, signB;
  int magnitudeA, magnitudeB;
  int resultSign, resultMagnitude;

  printf("Enter sign of first number (0 for +, 1 for -): ");
  scanf("%d", &signA);
  printf("Enter magnitude of first number: ");
  scanf("%d", &magnitudeA);

  printf("Enter sign of second number (0 for +, 1 for -): ");
  scanf("%d", &signB);
  printf("Enter magnitude of second number: ");
  scanf("%d", &magnitudeB);

  if (signA == signB) {
    resultMagnitude = magnitudeA + magnitudeB;
    resultSign = signA;
  } else {
    if (magnitudeA > magnitudeB) {
      resultMagnitude = magnitudeA - magnitudeB;
      resultSign = signA;
    } else if (magnitudeB > magnitudeA) {
      resultMagnitude = magnitudeB - magnitudeA;
      resultSign = signB;
    } else {
      resultMagnitude = 0;
      resultSign = 0;
    }
  }

  printf("Result (Signed Magnitude Addition):\n");
  printf("Sign: %d, Magnitude: %d\n", resultSign, resultMagnitude);
}

void signedMagnitudeSubtraction() {
  int signA, signB;
  int magnitudeA, magnitudeB;
  int resultSign, resultMagnitude;

  printf("Enter sign of first number (0 for +, 1 for -): ");
  scanf("%d", &signA);
  printf("Enter magnitude of first number: ");
  scanf("%d", &magnitudeA);

  printf("Enter sign of second number (0 for +, 1 for -): ");
  scanf("%d", &signB);
  printf("Enter magnitude of second number: ");
  scanf("%d", &magnitudeB);

  // A - B = A + (-B)
  signB = (signB == 0) ? 1 : 0;

  if (signA == signB) {
    resultMagnitude = magnitudeA + magnitudeB;
    resultSign = signA;
  } else {
    if (magnitudeA > magnitudeB) {
      resultMagnitude = magnitudeA - magnitudeB;
      resultSign = signA;
    } else if (magnitudeB > magnitudeA) {
      resultMagnitude = magnitudeB - magnitudeA;
      resultSign = signB;
    } else {
      resultMagnitude = 0;
      resultSign = 0;
    }
  }

  printf("Result (Signed Magnitude Subtraction):\n");
  printf("Sign: %d, Magnitude: %d\n", resultSign, resultMagnitude);
}

void signedMagnitudeMultiplication() {
  int signA, signB;
  int magnitudeA, magnitudeB;
  int resultSign, resultMagnitude;

  printf("Enter sign of first number (0 for +, 1 for -): ");
  scanf("%d", &signA);
  printf("Enter magnitude of first number: ");
  scanf("%d", &magnitudeA);

  printf("Enter sign of second number (0 for +, 1 for -): ");
  scanf("%d", &signB);
  printf("Enter magnitude of second number: ");
  scanf("%d", &magnitudeB);

  resultSign = (signA == signB) ? 0 : 1;

  resultMagnitude = magnitudeA * magnitudeB;

  if(resultMagnitude == 0)
    resultSign = 0;

  printf("Result (Signed Magnitude Multiplication):\n");
  printf("Sign: %d, Magnitude: %d\n", resultSign, resultMagnitude);
}

void signedMagnitudeDivision() {
  int signA, signB;
  int magnitudeA, magnitudeB;
  int resultSign, resultMagnitude;

  printf("Enter sign of numerator (0 for +, 1 for -): ");
  scanf("%d", &signA);
  printf("Enter magnitude of numerator: ");
  scanf("%d", &magnitudeA);

  printf("Enter sign of denominator (0 for +, 1 for -): ");
  scanf("%d", &signB);
  printf("Enter magnitude of denominator: ");
  scanf("%d", &magnitudeB);

  if (magnitudeB == 0) {
    printf("Error: Division by zero is not allowed!\n");
    return;
  }

  resultSign = (signA == signB) ? 0 : 1;

  resultMagnitude = magnitudeA / magnitudeB;

  if(resultMagnitude == 0)
    resultSign = 0;

  printf("Result (Signed Magnitude Division):\n");
  printf("Sign: %d, Magnitude: %d\n", resultSign, resultMagnitude);
}

int main() {
  int choice;

  do {
    printf("\n--- Signed Magnitude Operations ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        signedMagnitudeAddition();
        break;
      case 2:
        signedMagnitudeSubtraction();
        break;
      case 3:
        signedMagnitudeMultiplication();
        break;
      case 4:
        signedMagnitudeDivision();
        break;
      case 5:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);

  return 0;
}
