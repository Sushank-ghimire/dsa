#include <stdio.h>
#define MAX 50

int sequentialSearch(int arr[MAX], int, int);
void swap(int *arr, int i, int j);
void bubbleSort(int arr[MAX], int);
int binarySearch(int arr[], int, int, int);
int iterativeBinarySearch(int arr[], int, int);

int main() {
  int choice, size;
  do {
    printf("1. Binary Search\n");
    printf("2. Sequential Search\n");
    printf("3. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    int arr[MAX];

    if(choice < 3 && choice >= 1) {
      printf("Enter size of array : ");
      scanf("%d", &size);
      printf("Enter elements of the array : \n");
      for(int i=0; i<size; i++) {
        printf("Element for index[%d] : ", i);
        scanf("%d", &arr[i]);
      }

      if(choice == 1 || choice == 2){
        if(choice == 1) {
          bubbleSort(arr, size);
          printf("The sorted array is : \n");
          for(int i=0; i<size; i++)
            printf("Element of index[%d] is %d.\n", i, arr[i]);
          printf("\n");
        }
        int target = 1;
        while(target) {
          printf("Enter your choice (0 to exit || search target) : ");
          scanf("%d", &target);
          if(!target) break;
          int index = choice == 1 ? binarySearch(arr, 0, size-1, target) : sequentialSearch(arr, size, target);
          if(index == -1) {
            printf("Element %d not found.\n", target);
          } else {
            printf("Element %d found at index %d.\n", target, index);
          }
        }
      }
    } else if (choice == 3) {
      printf("Exiting program...\n");
      break;
    } else {
      printf("Invalid choice!\n");
    }
  } while (choice != 3);
  return 0;
}

int sequentialSearch(int arr[MAX], int size, int target) {
  int index = -1;
  for(int i=0; i<size; i++) {
    if(arr[i] == target) {
      index = i;
      break;
    }
  }
  return index;
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
  if (high >= low) {
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    if (arr[mid] > target)
      return binarySearch(arr, low, mid - 1, target);
    return binarySearch(arr, mid + 1, high, target);
  }
  return -1;
}

int iterativeBinarySearch(int arr[], int size, int target) {
  int low = 0;
  int high = size - 1;

  while(low <= high) {
    int mid = (low + high) / 2;

    if(arr[mid] == target)
      return mid;
    else if (arr[mid] > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}
