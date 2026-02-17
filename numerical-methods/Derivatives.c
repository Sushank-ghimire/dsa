#include <stdio.h>

int input(const char *msg);

int main() {
  int choice;
  do {
    printf("1. Forward Difference\n");
    printf("2. Forward Divided Difference\n");
    printf("3. Backward Difference\n");
    printf("4. Backward Divided Difference\n");
    printf("5. Central Difference\n");
    printf("6. Exit\n");
    choice = input("Enter your choice : ");

    switch (choice) {
      case 6:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 6);
}

int input(const char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}
