#include <stdio.h>
#define MAX 50

void sequentialSearch(int arr[MAX], int size);
void binarySearch();

int main() {
  int choice, size;
  do {
    printf("1. Binary Search\n");
    printf("2. Sequential Search\n");
    printf("3. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    int arr[size];
    switch (choice) {
      case 1:
      case 2:
        printf("Enter the size of array : ");
        scanf("%d", &size);
        printf("Enter the elements of the array : \n");
        for(int i=0; i<size; i++) {
          printf("Element for index[%d] : ", i);
          scanf("%d", &arr[i]);
        }
        if(choice == 1){

        }
        else
          sequentialSearch(arr, size);;
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 3);
  return 0;
}


void sequentialSearch(int arr[MAX], int size) {
  int target, index = -1, choice;
  do {
    printf("Enter element to search in array : ");
    scanf("%d", &target);

    for(int i=0; i<size; i++) {
      if(arr[i] == target) {
        index = i;
        break;
      }
    }
    if(index == -1) {
      printf("Element %d not found in provided array.\n", target);
    } else {
      printf("Element %d found at index %d.\n", target, index);
    }
    printf("Enter your choice (0 to exit) : ");
    scanf("%d", &choice);
  } while (choice != 0);
}
