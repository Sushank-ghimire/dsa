# Sorting Algorithms in Data Structures & Algorithms

This repository contains implementations of various sorting algorithms.

---

## 1. Bubble Sort

### Description

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### How It Works

1. Start from the first element
2. Compare adjacent elements
3. If the current element is greater than the next, swap them
4. Move to the next pair and repeat
5. After each pass, the largest unsorted element "bubbles up" to its correct position
6. Repeat until no swaps are needed

### Formula

For each pass i (0 to n-2):
$$\text{Compare } arr[j] \text{ with } arr[j+1] \text{ for } j = 0 \text{ to } n-i-2$$

### Complexity

- **Time Complexity (Best)**: O(n) - when array is already sorted
- **Time Complexity (Average/Worst)**: O(n²)
- **Space Complexity**: O(1) - in-place sorting

### Advantages

- Simple to understand and implement
- No additional memory required
- Stable sorting algorithm
- Detects already sorted list in O(n)

### Disadvantages

- Very slow for large datasets
- O(n²) comparisons in average/worst case
- Not suitable for large unsorted arrays

---

### Program Implementation

```c
// Helper common function to swap elements of the array
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
```

**Key Points**:

- Input: Unsorted array of integers
- Output: Sorted array in ascending order
- Time: O(n²) worst/average, O(n) best
- Space: O(1) - in-place
- Stable: Yes

---

## 2. Selection Sort

### Description

Selection Sort divides the array into sorted and unsorted regions. It repeatedly selects the minimum element from the unsorted region and places it at the end of the sorted region.

### How It Works

1. Find the minimum element in the unsorted portion
2. Swap it with the first unsorted element
3. Move the boundary of sorted region one element forward
4. Repeat until the entire array is sorted

### Formula

$$\text{For } i = 0 \text{ to } n-2: \text{ find } \min(arr[i...n-1]) \text{ and swap with } arr[i]$$

### Complexity

- **Time Complexity**: O(n²) for all cases
- **Space Complexity**: O(1)

### Advantages

- Simple implementation
- Performs well on small lists
- Minimal memory usage

### Disadvantages

- O(n²) time complexity in all cases
- Not stable
- Slower than insertion sort for nearly sorted data

---

### Program Implementation

```c
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
```

---

## 3. Heap Sort

### Description

Heap Sort uses a binary heap data structure to sort elements. It first builds a max-heap, then repeatedly extracts the maximum element and rebuilds the heap.

### How It Works

1. Build a max-heap from the input array
2. Swap the root (maximum) with the last element
3. Reduce heap size by one
4. Heapify the root
5. Repeat until heap size is 1

### Formula

$$\text{Heapify: } parent = \lfloor(i-1)/2\rfloor, \quad left = 2i+1, \quad right = 2i+2$$

### Complexity

- **Time Complexity**: O(n log n) for all cases
- **Space Complexity**: O(1)

### Advantages

- Guaranteed O(n log n) performance
- In-place sorting
- No quadratic worst-case

### Disadvantages

- Not stable
- Poor cache performance
- Slower in practice than quicksort

---

### Program Implementation

```c
// To be implemented
```

---

## 4. Merge Sort

### Description

Merge Sort is a divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves.

### How It Works

1. Divide the array into two halves
2. Recursively sort each half
3. Merge the two sorted halves into one sorted array

### Formula

$$T(n) = 2T(n/2) + O(n)$$

### Complexity

- **Time Complexity**: O(n log n) for all cases
- **Space Complexity**: O(n)

### Advantages

- Guaranteed O(n log n) performance
- Stable sorting algorithm
- Excellent for linked lists

### Disadvantages

- Requires O(n) additional space
- Slower for small datasets
- Not in-place

---

### Program Implementation

```c
// To be implemented
```

---

## 5. Quick Sort

### Description

Quick Sort is a divide-and-conquer algorithm that selects a pivot element and partitions the array around the pivot, placing smaller elements before it and larger elements after it.

### How It Works

1. Choose a pivot element
2. Partition: rearrange elements so that elements < pivot come before, elements > pivot come after
3. Recursively apply to sub-arrays before and after pivot

### Formula

$$T(n) = T(k) + T(n-k-1) + O(n)$$

Where k is the number of elements smaller than pivot.

### Complexity

- **Time Complexity (Best/Average)**: O(n log n)
- **Time Complexity (Worst)**: O(n²) - when pivot is always min/max
- **Space Complexity**: O(log n)

### Advantages

- Fastest in practice for most inputs
- In-place (low memory)
- Cache-friendly

### Disadvantages

- O(n²) worst case
- Not stable
- Poor pivot selection degrades performance

---

### Program Implementation

```c
// To be implemented
```

---

## 6. Shell Sort

### Description

Shell Sort is an optimization of insertion sort that allows exchange of elements that are far apart. It uses a gap sequence to compare and sort elements at specific intervals.

### How It Works

1. Start with a large gap
2. Perform gapped insertion sort
3. Reduce the gap
4. Repeat until gap = 1 (regular insertion sort)

### Formula

Common gap sequence (Shell's original):
$$gap = \lfloor n/2 \rfloor, \lfloor n/4 \rfloor, ..., 1$$

### Complexity

- **Time Complexity**: O(n log n) to O(n²) depending on gap sequence
- **Space Complexity**: O(1)

### Advantages

- Better than insertion sort for large arrays
- In-place sorting
- Adaptive to partially sorted data

### Disadvantages

- Complexity depends on gap sequence
- Not stable
- Analysis is complex

---

### Program Implementation

```c
// To be implemented
```

---

## Comparison Table

| Algorithm      | Best Time  | Average Time | Worst Time | Space    | Stable |
| -------------- | ---------- | ------------ | ---------- | -------- | ------ |
| Bubble Sort    | O(n)       | O(n²)        | O(n²)      | O(1)     | Yes    |
| Selection Sort | O(n²)      | O(n²)        | O(n²)      | O(1)     | No     |
| Heap Sort      | O(n log n) | O(n log n)   | O(n log n) | O(1)     | No     |
| Merge Sort     | O(n log n) | O(n log n)   | O(n log n) | O(n)     | Yes    |
| Quick Sort     | O(n log n) | O(n log n)   | O(n²)      | O(log n) | No     |
| Shell Sort     | O(n log n) | O(n^1.25)    | O(n²)      | O(1)     | No     |

---

## Complexity Cheatsheet

| Algorithm      | Time Complexity     | Space Complexity | Notes                      |
| -------------- | ------------------- | ---------------- | -------------------------- |
| Bubble Sort    | O(n²)               | O(1)             | Simple, stable, slow       |
| Selection Sort | O(n²)               | O(1)             | Simple, unstable           |
| Heap Sort      | O(n log n)          | O(1)             | In-place, not stable       |
| Merge Sort     | O(n log n)          | O(n)             | Stable, extra space needed |
| Quick Sort     | O(n log n) avg      | O(log n)         | Fastest in practice        |
| Shell Sort     | O(n log n) to O(n²) | O(1)             | Gap sequence dependent     |

---
