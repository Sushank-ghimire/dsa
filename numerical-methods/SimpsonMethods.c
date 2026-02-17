#include <stdio.h>

int input(const char *msg);

int main() {
  int choice;
  do {
    printf("1. Simpson's 1/3\n");
    printf("2. Composite Simpson's 1/3\n");
    printf("3. Simpson's 3/8\n");
    printf("4. Composite Simpson's3/8\n");
    printf("5. Exit\n");
    choice = input("Enter your choice : ");

    switch (choice) {
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);
}

int input(const char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}
