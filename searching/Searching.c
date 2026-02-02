#include <stdio.h>
#define MAX 50

void sequentialSearch(int arr[MAX], int size);
void swap(int *arr, int i, int j);
void bubbleSort(int arr[MAX], int size);
int binarySearch(int arr[], int low, int high, int target);

int main() {
  int choice, size;
  do {
    printf("1. Binary Search\n");
    printf("2. Sequential Search\n");
    printf("3. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    int arr[MAX];
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
          bubbleSort(arr, size);
          printf("The sorted array is : \n");
          for(int i=0; i<size; i++)
            printf("Element of index[%d] is %d.\n", i, arr[i]);
          printf("\n");
          int search, target;
          while(search) {
            printf("Enter element to search in array : ");
            scanf("%d", &target);
            int index = binarySearch(arr, 0, size-1, target);
            if(index == -1) {
              printf("Element %d not found in provided array.\n", target);
            } else {
              printf("Element %d found at index %d.\n", target, index);
            }
            printf("Enter your choice (0 to exit) : ");
            scanf("%d", &search);
          }
        } else if (choice == 2)
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

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void bubbleSort(int arr[], int size) {
  int i, j;
  // Bubble sort algorithm
  for(i=0; i<size - 1; i++) {
    for(j=0; j<size - i - 1; j++) {
      if(arr[j] > arr[j+1])
        swap(arr, j, j+1);
    }
  }
}

int binarySearch(int arr[], int low, int high, int target) {
  int mid = (low + high) / 2;
  if(high >= low) {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;

    if(arr[mid] > target)
      return binarySearch(arr, low, mid - 1, target);

    return binarySearch(arr, low, mid - 1, target);
  }
  return -1;
}
