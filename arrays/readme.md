# Arrays as ADT's (Abstract Data Types)

### Primary Operations Used In Arrays as ADT's

1. **Traversal**: Going or iterating through all the elements of the array at least once
2. **Insertion**: Inserting any elements in the array with the value and the insertion index
3. **Deletion**: Deleting any element from the dynamically allocated memory
4. **Searching**: Searching any specific element from the array
5. **Sorting**: Sorting the given array in ascending or descending order

## Program Implementation

```c
// structure for the custom array
typedef struct {
	int total_array_size;
	int total_used_size;
	int *ptr;
} Array;

// Function to create dynamic array at heap storage
void createArray(Array* arr, int totalSize, int usedSize) {
	arr->total_array_size = totalSize;
	arr->total_used_size = usedSize;
	arr->ptr = (int *) malloc(totalSize * sizeof(int));
}

// Function to insert values in the array
void setValue(Array *arr) {
	int i, n;
	for(i=0; i<arr->total_used_size; i++) {
		printf("Enter element at %d position : ", i);
		scanf("%d", &n);
		(arr->ptr)[i] = n;
	}
}

// Function to insert element in a specific index
void insertElement(Array *arr, int index, int value) {
	if(index < 0 || index > arr->total_array_size) {
		printf("Invalid index provided\n");
		return;
	}

	if(arr->total_used_size >= arr->total_array_size) {
		printf("The array is already full\n");
		return;
	}

	int i;
	// Shifting the elements to one step right
	for(i= arr->total_used_size - 1; i>=index; i--) {
		arr->ptr[i+1] = arr->ptr[i];
	}

	// Inserting new element to the index
	arr->ptr[index] = value;

	arr->total_used_size++;
}

// Function to delete element given by the user
void deleteElement(Array *arr, int element) {
	int index = -1, i;
	for(i=0; i<arr->total_used_size; i++) {
		if(arr->ptr[i] == element) {
			index = i;
			break;
		}
	}
	if(index == -1) {
		printf("Element not found in the array!\n");
		return;
	}
	for(i=index; i<arr->total_used_size - 1; i++) {
		arr->ptr[i] = arr->ptr[i+1];
	}
	arr->total_used_size = arr->total_used_size - 1;
	printf("Element deleted successfully!\n");
}

// functin to search element linearly from the array
void searchElement(Array *arr, int element) {
	int flag = 0, i;
	for(i=0; i<arr->total_used_size; i++) {
		if(arr->ptr[i] == element) {
			printf("The index of the element is : %d\n", i);
			flag = 1;
			break;
		}
	}

	if(!flag) {
		printf("Element not found in the array!\n");
		return;
	}
}

// Function to sort array (bubble sort)
void sortArrayAndPrint(Array *arr) {
	int i, j;
	for(i = 0; i < arr->total_used_size - 1; i++) {
        for(j = 0; j < arr->total_used_size - i - 1; j++) {
            if(arr->ptr[j] > arr->ptr[j + 1]) {
                int temp = arr->ptr[j];
                arr->ptr[j] = arr->ptr[j + 1];
                arr->ptr[j + 1] = temp;
            }
        }
    }
}

// Function to free heap memory after completion of work
void freeArray(Array *arr) {
	free(arr->ptr);
	arr->ptr = NULL;
}
```
