#include <stdio.h>

int linearSearch(int size, int array[size], int search) {
	int i;
	for(i=0; i<size; i++) {
		if(array[i] == search) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n, i, search, choice;
	
	printf("Enter the number or elements for the array : ");
	scanf("%d", &n);
	
	int array[n];
	for(i=0; i<n; i++) {
		printf("Enter element for index %d:", i);
		scanf("%d", &array[i]);
	}

	do {
		printf("1. Exit\n");
		printf("2. Search Element\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		if(choice == 1) {
			printf("Exiting program...");
		} else if (choice == 2) {
			printf("Enter the element to search : ");
			scanf("%d", &search);
		
			int index = linearSearch(n, array, search);
			if(index < 0) {
				printf("The element is not found in the array.\n");
			} else {
				printf("The element is at index %d.\n", index);
			}
		} else {
			printf("Invalid choice\n");
		}
	} while (choice != 1);
	return 0;
}
