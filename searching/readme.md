# Searching in DSA

1. **Linear Searching**: Search by traversal of each elements of the array. It's time complexity is **O(n)**
2. **Binary Searching**: Search by breaking the array into multiple small sizes. It's only applied in **sorted** arrays. It's time complexity is **O(log(n))**

## Program Implementation

```c
// Function implementation of linear search
int linearSearch(int size, int array[size], int search) {
	int i;
	for(i=0; i<size; i++) {
		if(array[i] == search) {
			return i;
		}
	}
	return -1;
}

// Function implementation of binary search
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
```
