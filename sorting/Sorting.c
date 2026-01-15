#include <stdio.h>

void swap(int *arr, int i, int j);
void bubbleSort();

int main() {
  int choice;
  do {
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Shell Sort\n");
    printf("7. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        bubbleSort();
        break;
      case 7:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  }while (choice != 7);
  return 0;
}

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void bubbleSort() {
  int i, j, size;
  printf("Enter the size of the array : ");
  scanf("%d", &size);
  printf("Enter %d elements of the array : \n", size);
  int arr[size];
  for(i=0; i<size; i++) {
    printf("Enter element of index [%d]: ", i);
    scanf("%d", &arr[i]);
  }
  // Bubble sort algorithm
  for(i=0; i<size - 1; i++) {
    for(j=0; j<size - i - 1; j++) {
      if(arr[j] > arr[j+1])
        swap(arr, j, j+1);
    }
  }
  printf("The sorted array is : \n");
  for(i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
