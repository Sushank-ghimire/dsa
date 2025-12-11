# Queue Data Structure in DSA

## 1. Definition

**Queue**: A Queue is a linear data structure that follows the **FIFO (First In First Out)** principle. The element inserted first is the first one to be removed. Think of it like a line of people waiting for a ticket — the person who joins the line first gets served first.

## 2. Types of Queues

### a) **Simple Queue (Linear Queue)**

- Insertions happen at one end (**Rear**).
- Deletions happen at the other end (**Front**).
- **Drawback**: Suffers from "False Overflow" (if items are deleted, space at the front is created but cannot be reused in a standard array implementation without shifting).

### b) **Circular Queue**

- The last position is connected back to the first position to make a circle.
- Solves the memory wastage problem of linear queues by reusing empty spaces.

### c) **Priority Queue**

- Elements are arranged based on priority rather than arrival time.
- Higher priority elements are dequeued before lower priority ones.

### d) **Double Ended Queue (Deque)**

- Insertions and deletions can be performed from both the **Front** and **Rear** ends.

## 3. Basic Operations

| Operation      | Description                                  |
| :------------- | :------------------------------------------- |
| **Enqueue**    | Add an element to the rear of the queue      |
| **Dequeue**    | Remove and return the element from the front |
| **Peek/Front** | View the front element without removing      |
| **isEmpty**    | Check if the queue is empty                  |
| **isFull**     | Check if the queue is full (for fixed size)  |

## 4. Time Complexity

| Operation   | Array Implementation | Linked List Implementation |
| :---------- | :------------------- | :------------------------- |
| **Enqueue** | O(1)                 | O(1)                       |
| **Dequeue** | O(1)                 | O(1)                       |
| **Peek**    | O(1)                 | O(1)                       |
| **isEmpty** | O(1)                 | O(1)                       |

**Space Complexity**:

- O(n) where n is the number of elements.

## 5. Applications

- **CPU Scheduling** (FCFS - First Come First Serve).
- **Disk Scheduling**.
- **Data Buffers** (IO Buffers, CD Player buffers).
- **Breadth-First Search (BFS)** in graphs.
- **Print Spooling**.

## 6. Program Implementation

This project implements a **Linear Queue** using a dynamic array in C.

### Code Snippets (Linear queue)

#### Shared Code For All Queue Types

```c
// Structure of the Queue
typedef struct
{
  int *items; // Dynamic array
  int rear;
  int front;
  int size;
} Queue;

// Initialization
void createQueue(Queue *linearQueue, int size)
{
  linearQueue->size = size;
  linearQueue->front = -1;
  linearQueue->rear = -1;
  linearQueue->items = malloc(size * sizeof(int));
  if (linearQueue->items == NULL)
  {
    printf("Failed to allocate memory for queue.\n");
    exit(1);
  }
}

// To free the heap memory
void freeQueue(Queue *queue)
{
  free(queue->items);
}
```

#### Linear Queue

```c
// To check Queue is empty or not
int isEmpty(Queue queue)
{
  return queue.rear == -1;
}

// To check Queue is full or not
int isFull(Queue queue)
{
  if (queue.rear == queue.size - 1)
  {
    return 1;
  }
  return 0;
}

// Enqueue Operation
void Enqueue(Queue *queue, int data)
{
  if (isFull(*queue))
  {
    printf("Queue is full, cannot enqueue.\n");
    return;
  }
  if (queue->front == -1)
  {
    queue->front = 0;
  }
  queue->items[++(queue->rear)] = data;
}

// Dequeue Operation
void Dequeue(Queue *queue)
{
  if (isEmpty(*queue))
  {
    printf("Queue is empty can't dequeue items.\n");
    return;
  }
  if (queue->front == queue->rear)
  {
    queue->front = -1;
    queue->rear = -1;
  }
  else
  {
   queue->items[queue->front++];
  }
}
```

#### Circular Queue
