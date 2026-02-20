# Hashing in DSA

## 1. Definition

**Hashing**: Hashing is a technique used to map data (keys) to fixed-size values (hash codes) using a **hash function**. It enables fast data retrieval, insertion, and deletion in **O(1)** average time. Think of it like a library index — instead of searching every book, you go directly to the shelf using a catalog number.

---

## 2. Types of Collision Resolution

### a) **Open Addressing**

- All elements stored directly in the hash table
- On collision, probe for next available slot
- Types: Linear Probing, Quadratic Probing, Double Hashing

### b) **Separate Chaining**

- Each slot contains a linked list (or other data structure)
- Colliding elements are appended to the list
- Simpler to implement, but uses extra memory

---

## 3. Open Addressing Techniques

### a) **Linear Probing**

- On collision, check the **next consecutive slot**
- Formula: `h(k, i) = (h(k) + i) % size`
- Problem: **Primary clustering** — long runs of occupied slots

### b) **Quadratic Probing**

- On collision, check slots at **quadratic intervals**
- Formula: `h(k, i) = (h(k) + i²) % size`
- Problem: **Secondary clustering** — keys with same hash follow same probe sequence

### c) **Double Hashing**

- Uses a **second hash function** to determine step size
- Formula: `h(k, i) = (h1(k) + i * h2(k)) % size`
- Best distribution, minimizes clustering

---

## 4. Key Concepts

| Concept             | Description                                                    |
| ------------------- | -------------------------------------------------------------- |
| **Hash Function**   | Maps keys to indices; should distribute keys uniformly         |
| **Collision**       | When two keys map to the same index                            |
| **Load Factor (α)** | Ratio of elements to table size (n/m); affects performance     |
| **Probing**         | Searching for an empty slot after a collision                  |
| **Clustering**      | Groups of consecutive occupied slots that slow down operations |

---

## 5. Time & Space Complexity

| Operation  | Average Case | Worst Case (all collisions) |
| ---------- | ------------ | --------------------------- |
| **Insert** | O(1)         | O(n)                        |
| **Search** | O(1)         | O(n)                        |
| **Delete** | O(1)         | O(n)                        |

| Probing Technique  | Clustering Issue     | Distribution Quality |
| ------------------ | -------------------- | -------------------- |
| **Linear**         | Primary clustering   | Poor                 |
| **Quadratic**      | Secondary clustering | Moderate             |
| **Double Hashing** | Minimal clustering   | Best                 |

**Space Complexity**: O(n) where n is the table size

---

## 6. Applications

- Database indexing and fast lookups
- Symbol tables in compilers
- Caches (LRU cache, memoization)
- Dictionaries and sets in programming languages
- Password storage (with cryptographic hashing)
- Detecting duplicates in data streams
- Implementing associative arrays

---

## 7. Pitfalls & How to Avoid Them

| Pitfall                     | Solution                                              |
| --------------------------- | ----------------------------------------------------- |
| Poor hash function          | Use well-tested hash functions with good distribution |
| High load factor            | Resize table when α > 0.7 (rehashing)                 |
| Clustering (linear probing) | Use quadratic probing or double hashing               |
| Infinite loop in probing    | Track probe count, stop at table size                 |
| Memory leaks                | Free allocated memory before program exit             |

---

## 8. Program Implementations

### LinearProbing.c — Hash Table with Linear Probing

**Description**: Implements a hash table using linear probing for collision resolution. On collision, sequentially checks next slots.

**Probing Formula**: `index = (h(key) + i) % size` where `i = 0, 1, 2, ...`

**Key Points**:

- Hash function: `key % size`
- Probes linearly: `(index + i) % size`
- Stops when table is full (`i == size`)
- Time: O(1) average, O(n) worst case
- Space: O(n) for table
- Suffers from primary clustering

---

### QuadraticProbing.c — Hash Table with Quadratic Probing

**Description**: Implements a hash table using quadratic probing. On collision, checks slots at quadratic intervals to reduce clustering.

**Probing Formula**: `index = (h(key) + i²) % size` where `i = 0, 1, 2, ...`

**Key Points**:

- Hash function: `key % size`
- Probes quadratically: `(index + i²) % size`
- Better distribution than linear probing
- Time: O(1) average, O(n) worst case
- Space: O(n) for table
- May not find empty slot even if table isn't full (depends on table size)

---

### DoubleHashing.c — Hash Table with Double Hashing

**Description**: Implements a hash table using two hash functions. The second hash determines the step size, providing better distribution.

**Probing Formula**: `index = (h1(key) + i * h2(key)) % size`

**Key Points**:

- Primary hash: `key % size`
- Secondary hash: `R - (key % R)` where `R = size - 1`
- Best distribution among open addressing methods
- Time: O(1) average, O(n) worst case
- Space: O(n) for table
- Minimizes both primary and secondary clustering

---

## 9. Complexity Cheatsheet

| Program           | Probing Formula            | Average Time | Clustering |
| ----------------- | -------------------------- | ------------ | ---------- |
| Linear Probing    | `(h(k) + i) % size`        | O(1)         | Primary    |
| Quadratic Probing | `(h(k) + i²) % size`       | O(1)         | Secondary  |
| Double Hashing    | `(h1(k) + i*h2(k)) % size` | O(1)         | Minimal    |

---

## 10. Comparison of Techniques

| Feature               | Linear Probing | Quadratic Probing | Double Hashing |
| --------------------- | -------------- | ----------------- | -------------- |
| **Implementation**    | Simplest       | Moderate          | Complex        |
| **Cache Performance** | Best           | Good              | Moderate       |
| **Clustering**        | Worst          | Moderate          | Best           |
| **Distribution**      | Poor           | Better            | Best           |
| **Extra Hash Func**   | No             | No                | Yes            |

---

## 11. One-Line Conclusion

> Hashing provides O(1) average-time operations for insert, search, and delete — choose linear probing for simplicity, quadratic probing for moderate improvement, or double hashing for best distribution when collisions are frequent.
