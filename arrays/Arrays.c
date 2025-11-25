#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int total_array_size;
	int total_used_size;
	int *ptr;
} Array;

void createArray(Array* arr, int totalSize, int usedSize) {
	arr->total_array_size = totalSize;
	arr->total_used_size = usedSize;
	arr->ptr = (int *) malloc(totalSize * sizeof(int));
}

void showArray(Array *arr) {
	int i;
	for(i=0; i<arr->total_used_size; i++) {
		printf("%d ", (arr->ptr)[i]);
	}
}

void setValue(Array *arr) {
	int i, n;
	for(i=0; i<arr->total_used_size; i++) {
		printf("Enter element at %d position : ", i);
		scanf("%d", &n);
		(arr->ptr)[i] = n;
	}
}

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
	printf("Element inserted successfully!\n");
}

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
	printf("\nThe sorted array is : \n");
	showArray(arr);
}

void freeArray(Array *arr) {
	free(arr->ptr);
	arr->ptr = NULL;
}

int main() {
	Array arr;
	int choice;
	int total, used, index, value, element;
	do {
		printf("\n");
		printf("1. Create Array (total capacity, using capacity)\n");
		printf("2. Insert Values (user input)\n");
		printf("3. Insert Element (index, value)\n");
		printf("4. Traversal (Show Array)\n");
		printf("5. Exit\n");
		printf("6. Delete Element (element)\n");
		printf("7. Search Element (element)\n");
		printf("8. Sort array and print\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter total array size and the size which is used initially (total, used) : ");
				scanf("%d %d", &total, &used);
				if(used > total) {
					printf("Invalid input combinations\n");
					break;
				}
				createArray(&arr, total, used);
				printf("Array Created Successfully!\n");
				break;
			case 2:
				setValue(&arr);
				break;
			case 3:
				printf("Enter the index and value to insert (index, value): ");
				scanf("%d %d", &index, &value);
				insertElement(&arr, index, value);
				break;
			case 4:
				printf("The elements of the array are :\n");
				showArray(&arr);
				break;
			case 5:
				printf("Exiting program....");
				break;
			case 6:
				printf("Enter a element of the array to delete it : ");
				scanf("%d", &element);
				deleteElement(&arr, element);
				element = 0;
				break;
			case 7:
				printf("Enter element to find the index of element : ");
				scanf("%d", &element);
				searchElement(&arr, element);
				break;
			case 8:
				sortArrayAndPrint(&arr);
				break;
			default:
				printf("Invalid choice!\n");
		}
	} while (choice != 5);

	freeArray(&arr);
	return 0;
}
