#include <stdio.h>

int mask(int x, int bits) {
  int m = (1 << bits) - 1;
  x &= m;
  if (x & (1 << (bits - 1)))
    x |= ~m;
  return x;
}

void boothsMultiplication() {
  int M, Q;
  int A = 0, Q_1 = 0;
  int n = 4;          // FIXED 4-bit Booth
  int count = n;

  printf("Enter multiplicand (decimal): ");
  scanf("%d", &M);
  printf("Enter multiplier (decimal): ");
  scanf("%d", &Q);

  M = mask(M, n);
  Q = mask(Q, n);
  A = 0;

  printf("\nStarting Booth's Algorithm:\n");
  printf("A=%d Q=%d Q-1=%d M=%d\n\n", A, Q, Q_1, M);

  while (count--) {
    int Q0 = Q & 1;

    if (Q0 == 0 && Q_1 == 1) {
      A = mask(A + M, n);
      printf("A = A + M → A = %d\n", A);
    } else if (Q0 == 1 && Q_1 == 0) {
      A = mask(A - M, n);
      printf("A = A - M → A = %d\n", A);
    }

    // Arithmetic right shift of (A,Q,Q-1)
    Q_1 = Q & 1;
    Q = (Q >> 1) | ((A & 1) << (n - 1));
    A = A >> 1;

    A = mask(A, n);
    Q = mask(Q, n);

    printf("After shift: A=%d Q=%d Q-1=%d\n\n", A, Q, Q_1);
  }

  // Combine A and Q → 2n-bit result
  int product = (A << n) | (Q & ((1 << n) - 1));

  printf("Booth's Multiplication Result: %d\n", product);
}

int main() {
  int choice;

  do {
    printf("\n1. Booth's Multiplication\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        boothsMultiplication();
        break;
      case 2:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 2);

  return 0;
}
