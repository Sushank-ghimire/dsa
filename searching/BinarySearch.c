#include <stdio.h>

// Binary search is only for the sorted arrays
int binarySearch(int array[], int size, int element) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == element)
            return mid;
        if (array[mid] < element)
            low = mid + 1;
        else
            high = high - 1;
    }
    return -1;
}

int main() {
    int index, n, i, choice, search;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int array[n];
    for(i = 0; i < n; i++) {
        printf("Enter element for index %d:", i);
        scanf("%d", &array[i]);
    }

    do {
        printf("1. Exit\n");
        printf("2. Search Element\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Exiting program...\n");
            break;

        case 2:
            printf("Enter a element to search : ");
            scanf("%d", &search);
            index = binarySearch(array, n, search);

            if(index < 0)
                printf("The element is not found in the array.\n");
            else
                printf("The element is at index %d.\n", index);
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while(choice != 1);

    return 0;
}

