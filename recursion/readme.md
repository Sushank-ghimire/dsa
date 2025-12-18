# Recursion in DSA

## 1. Definition

**Recursion**: Recursion is a programming technique where a function calls itself to solve smaller instances of the same problem until a **base case** is reached. Think of it like a mirror reflecting another mirror — the function keeps calling itself with simpler inputs until it hits a stopping point.

---

## 2. Types of Recursion

### a) **Linear Recursion**

- Function makes **one recursive call** per invocation
- Examples: Factorial, GCD
- Time: O(n), Space: O(n) stack

### b) **Binary/Tree Recursion**

- Function makes **two or more recursive calls** per invocation
- Examples: Fibonacci (naive), Tree traversals
- Time: O(2^n) for naive binary recursion

### c) **Tail Recursion**

- Recursive call is the **last operation** in the function
- Can be optimized by compilers to iteration (not guaranteed in C)
- More memory efficient when optimized

### d) **Indirect Recursion**

- Function A calls Function B, and Function B calls Function A
- Less common, used in mutual dependencies

---

## 3. Key Concepts

| Concept             | Description                                                                |
| ------------------- | -------------------------------------------------------------------------- |
| **Base Case**       | The simplest instance that can be solved directly (stops recursion)        |
| **Recursive Case**  | The function calls itself with smaller/simpler arguments                   |
| **Recursion Depth** | Number of nested calls; each uses stack memory                             |
| **Recurrence**      | Mathematical relation describing time complexity (e.g., T(n) = T(n-1) + 1) |

---

## 4. Time & Space Complexity

| Recursion Type       | Time Complexity      | Space Complexity (Stack) |
| -------------------- | -------------------- | ------------------------ |
| **Linear**           | O(n)                 | O(n)                     |
| **Binary (naive)**   | O(2^n)               | O(n)                     |
| **Divide & Conquer** | O(n log n) typically | O(log n) to O(n)         |
| **Tail (optimized)** | O(n)                 | O(1) if optimized        |

---

## 5. Applications

- Mathematical computations (factorial, Fibonacci, GCD, power)
- Tree and graph traversals (DFS, inorder, preorder, postorder)
- Divide and conquer algorithms (merge sort, quick sort, binary search)
- Backtracking (N-Queens, maze solving, permutations)
- Dynamic programming (top-down memoization)
- Tower of Hanoi puzzle

---

## 6. Pitfalls & How to Avoid Them

| Pitfall                     | Solution                                           |
| --------------------------- | -------------------------------------------------- |
| Missing base case           | Always define a clear stopping condition           |
| Stack overflow              | Limit depth, use iteration, or increase stack size |
| Exponential time complexity | Use memoization or convert to dynamic programming  |
| Integer overflow            | Use larger data types (long long, unsigned)        |

---

## 7. Program Implementations

---

### Factorial.c — Computes n! using Linear Recursion

**Description**: Reads an integer n (non-negative) and computes factorial recursively.

**Mathematical Definition**: n! = n × (n-1)!; 0! = 1

```c
int factorial(int num)
{
  if (num == 0)
    return 1;
  else
    return num * factorial(num - 1);
}
```

**Key Points**:

- Base case: `num == 0` returns 1
- Recursive case: `num * factorial(num - 1)`
- Time: O(n), Space: O(n)
- Watch for overflow: 13! exceeds int range

---

### Fibonacci.c — Prints Fibonacci Series using Binary Recursion

**Description**: Reads n and prints the first n Fibonacci numbers using naive recursion.

**Mathematical Definition**: F(1) = 0, F(2) = 1, F(n) = F(n-1) + F(n-2)

```c
int fibonacci(int x)
{
  if (x == 1)
    return 0;
  else if (x == 2)
    return 1;
  else
    return fibonacci(x - 1) + fibonacci(x - 2);
}
```

**Key Points**:

- Base cases: `x == 1` returns 0, `x == 2` returns 1
- Recursive case: `fibonacci(x-1) + fibonacci(x-2)`
- Time: O(2^n) — exponential (very slow for large n)
- Space: O(n) stack depth
- Optimization: Use memoization or iterative approach for large n

---

### GCD.c — Euclid's Algorithm using Recursion

**Description**: Computes the Greatest Common Divisor of two numbers using Euclid's algorithm.

**Mathematical Definition**: GCD(a, b) = GCD(b, a % b); GCD(a, 0) = a

```c
int GCD(int n1, int n2)
{
  if (n2 == 0)
    return n1;
  else
    return GCD(n2, n1 % n2);
}
```

**Key Points**:

- Base case: `n2 == 0` returns n1
- Recursive case: `GCD(n2, n1 % n2)`
- Time: O(log min(a, b)) — very efficient
- Space: O(log min(a, b)) stack depth
- Handles large numbers efficiently

---

### TowerOfHanoi.c — Classic Puzzle using Recursion

**Description**: Prints the sequence of moves to transfer n disks from source peg to destination peg using an auxiliary peg.

**Rules**:

1. Only one disk can be moved at a time
2. A larger disk cannot be placed on a smaller disk
3. All disks start on source peg and must end on destination peg

```c
void towerOfHanoi(int n, char source, char dest, char auxiliary)
{
  if (n == 1)
  {
    printf("Move disk 1 from %c to %c\n", source, dest);
    return;
  }
  // Step 1: Move n-1 disks from source to auxiliary stack
  towerOfHanoi(n - 1, source, auxiliary, dest);

  // Step 2: Move the nth disk from source to destination stack
  printf("Move disk %d from %c to %c.\n", n, source, dest);

  // Step 3: Move n-1 disks from auxiliary to destination stack
  towerOfHanoi(n - 1, auxiliary, dest, source);
}
```

**Key Points**:

- Base case: `n == 1` — move single disk directly
- Recursive case: Move n-1 disks to auxiliary, move nth disk to destination, move n-1 disks to destination
- Time: O(2^n) — exponential (2^n - 1 moves required)
- Space: O(n) stack depth
- Classic example of divide-and-conquer recursion

---

## 8. Complexity Cheatsheet

| Program        | Time Complexity | Space Complexity | Recursion Type       |
| -------------- | --------------- | ---------------- | -------------------- |
| Factorial      | O(n)            | O(n)             | Linear               |
| Fibonacci      | O(2^n)          | O(n)             | Binary (naive)       |
| GCD            | O(log min(a,b)) | O(log min(a,b))  | Linear (logarithmic) |
| Tower of Hanoi | O(2^n)          | O(n)             | Binary               |

---

## 9. One-Line Conclusion

> Recursion expresses solutions clearly and concisely for many problems, but watch for base cases, stack use, and repeated work — optimize with memoization or convert to iterative/Dynamic Programming when needed.
