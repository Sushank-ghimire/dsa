#include <stdio.h>
#define MAX 50

void swap(int *arr, int i, int j);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void heapSort(int arr[], int size);
void heapify(int arr[], int size, int i);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
  int choice;
  int i, j, size;
  int arr[MAX];
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
    if(choice != 7) {
      printf("Enter the size of the array : ");
      scanf("%d", &size);
      printf("Enter %d elements of the array : \n", size);
      for(i=0; i<size; i++) {
        printf("Enter element of index [%d]: ", i);
        scanf("%d", &arr[i]);
      }
    }
    switch (choice) {
      case 1:
        bubbleSort(arr, size);
        break;
      case 2:
        selectionSort(arr, size);
        break;
      case 3:
        heapSort(arr, size);
        break;
      case 5:
        quickSort(arr, 0, size - 1);;
        break;
      case 7:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
    if(choice != 7) {
      printf("The sorted array is : \n");
      for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
    }
  }while (choice != 7);
  return 0;
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

void selectionSort(int arr[], int size) {
  int i, j;
  // Selection sort algorithm
  for(i=0; i<size - 1; i++) {
    int min_index = i;
    for(j=i+1; j<size; j++) {
      if(arr[j] < arr[min_index])
        min_index = j;
    }
    swap(arr, min_index, i);
  }
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  // left index
  int l = 2 * i + 1;
  // right index
  int r = 2 * i + 2;

  // if left child is larger than root
  if(l < n && arr[l] > arr[largest])
    largest = l;

  // if right child is larger than largest so far
  if(r < n && arr[r] > arr[largest])
    largest = r;

  // if largest is not root
  if(largest != i) {
    swap(arr, i, largest);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int size) {
  int i, j;
  // Heap sort algorithm
  for (i = size / 2 - 1; i >= 0; i--)
    heapify(arr, size, i);

  // One by one extract an element from heap
  for (i = size - 1; i > 0; i--) {
    // Move current root to end
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    // Call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for(int j=low; j<=high - 1; j++) {
    if(arr[j] < pivot) {
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, i+1, high);
  return i+1;
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int partitionIndex = partition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
  }
}
