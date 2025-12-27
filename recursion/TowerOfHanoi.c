#include <stdio.h>
#include <math.h>

void towerOfHanoi(int n, char source, char dest, char auxiliary)
{
  if (n == 1)
  {
    printf("Move disk 1 from %c to %c\n", source, dest);
    return;
  }
  // Step 1: Move n-1 disks from source to auxiliary stack
  towerOfHanoi(n - 1, source, auxiliary, dest);

  // Step 2: Move the nth disk from source to destination stack
  printf("Move disk %d from %c to %c.\n", n, source, dest);

  // Step 3: Move n-1 disks from auxiliary to destination stack
  towerOfHanoi(n - 1, auxiliary, dest, source);
}

int main()
{
  int disks, choice;
  do {
    printf("1. Find Solution For n Disks.\n");
    printf("2. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the number of disks : ");
        scanf("%d", &disks);
        if (disks <= 0)
        {
          printf("Invalid input! \n");
          return 1;
        }
        printf("Total steps required are : %d.\n", (int)pow(2, disks) - 1);
        // A, B, C (Source, Destination, Auxiliary) stacks
        towerOfHanoi(disks, 'A', 'C', 'B');
        break;
      case 2:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice\n");

    }
  }while (choice != 2);
  return 0;
}
