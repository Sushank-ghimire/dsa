# Dynamic Memory Allocation (DMA) in C

**Dynamic Memory Allocation (DMA)** allows memory to be allocated **at runtime** from the **heap**, instead of compile-time allocation from the stack.

DMA is mainly used when:

- The size of data is **not known in advance**
- Memory needs to **grow or shrink**
- Efficient memory utilization is required

---

## Heap vs Stack (Quick Reminder)

| Stack                  | Heap                |
| ---------------------- | ------------------- |
| Compile-time           | Runtime             |
| Fixed size             | Dynamic size        |
| Automatic deallocation | Manual deallocation |
| Fast                   | Slightly slower     |

---

## What This Program Demonstrates

This program demonstrates **Dynamic Memory Allocation (DMA)** in C using:

- `malloc()`
- `calloc()`
- `realloc()`
- `free()`

The program dynamically allocates, resizes, uses, and deallocates memory at **runtime** using a structure.

---

## Structure Used for DMA

```c
typedef struct
{
  int size;
  int *items;
} Data;
```

### Explanation

- `size` → Stores the number of elements allocated in heap memory
- `items` → Pointer that points to dynamically allocated memory (heap)

This structure helps **track memory size and pointer together**, which is good DMA practice.

---

## Memory Allocation Using `malloc()`

```c
int allocateMalloc(Data *data, int size)
{
  data->items = malloc(size * sizeof(int));
  if (!data->items)
    return 0;
  data->size = size;
  return 1;
}
```

### Key Points

- `malloc()` allocates **uninitialized memory**
- Memory is allocated at **runtime**
- Returns `NULL` if allocation fails
- The size is stored to avoid overflow or invalid access

---

## Memory Allocation Using `calloc()`

```c
int allocateCalloc(Data *data, int size)
{
  data->items = calloc(size, sizeof(int));
  if (!data->items)
    return 0;
  data->size = size;
  return 1;
}
```

### Key Points

- `calloc()` allocates memory and **initializes all bytes to zero**
- Useful when default initialization is required
- Safer than `malloc()` for beginners

---

## Memory Reallocation Using `realloc()`

```c
int reallocate(Data *data, int size)
{
  if (!data->items)
  {
    printf("Memory not allocated yet.\n");
    return 0;
  }

  int *temp = realloc(data->items, size * sizeof(int));
  if (!temp)
    return 0;

  data->items = temp;
  data->size = size;
  return 1;
}
```

### Key Points

- `realloc()` resizes previously allocated memory
- Uses a **temporary pointer** to avoid memory leaks
- Old data is preserved up to the minimum of old and new size
- Prevents reallocation when memory is not allocated

---

## Filling Data into Dynamically Allocated Memory

```c
void fillData(Data *data)
{
  for (int i = 0; i < data->size; i++)
  {
    data->items[i] = (i + 1) * 2;
  }
}
```

### Explanation

- Demonstrates how heap memory is accessed using pointers
- Values are stored using array indexing
- `(i + 1) * 2` ensures predictable test data

---

## Displaying Dynamically Allocated Data

```c
void printData(const Data *data)
{
  printf("Data items: ");
  for (int i = 0; i < data->size; i++)
  {
    printf("%d ", data->items[i]);
  }
  printf("\n");
}
```

### Key Points

- Reads data from heap memory
- Uses `const` pointer to prevent accidental modification
- Demonstrates traversal of dynamically allocated memory

---

## Freeing Heap Memory

```c
void freeMemory(Data *data)
{
  free(data->items);
  data->items = NULL;
  data->size = 0;
}
```

### Explanation

- `free()` releases heap memory
- Pointer is set to `NULL` to avoid dangling pointer
- Size reset prevents invalid access

---

## Main Function (Menu-Driven DMA Program)

```c
Data data = {0, NULL};
```

### Why This Is Important

- Initializes pointer to `NULL`
- Prevents undefined behavior
- Safe starting state for DMA

---

### Menu Options

| Choice | Operation                        |
| ------ | -------------------------------- |
| 1      | Allocate memory using `malloc()` |
| 2      | Allocate memory using `calloc()` |
| 3      | Resize memory using `realloc()`  |
| 4      | Free memory and exit             |

---

## DMA Flow in This Program

1. User selects allocation method
2. Memory is allocated on heap
3. Data is filled into allocated memory
4. Data is printed
5. Memory can be resized
6. Memory is freed before exit

---

## Common DMA Errors Prevented in This Code

✔ Checking allocation failure
✔ Using `realloc()` safely
✔ Avoiding dangling pointers
✔ Preventing use of unallocated memory
✔ Proper cleanup before exit

---

## Important Exam Notes

- `malloc()` → allocates garbage values
- `calloc()` → allocates zero-initialized memory
- `realloc()` → resizes existing memory block
- `free()` → releases heap memory
- DMA memory exists until explicitly freed

---

## One-Line Conclusion

> This program demonstrates Dynamic Memory Allocation in C by allocating, resizing, using, and freeing heap memory safely using `malloc`, `calloc`, `realloc`, and `free`.
