#include "shared.h"
#include <stdio.h>

int isFullCircular(Queue queue)
{
  return (queue.rear + 1) % queue.size == queue.front;
}

int isEmptyCircular(Queue queue)
{
  return queue.front == -1;
}

void Enqueue(Queue *queue)
{
  if (isFullCircular(*queue))
  {
    printf("Queue is full.\n");
    return;
  }
  int data;
  printf("Enter the value to insert : ");
  scanf("%d", &data);
  if (queue->front == -1)
    queue->front = 0;
  queue->rear = (queue->rear + 1) % queue->size;
  queue->items[queue->rear] = data;
  printf("Element %d inserted\n", data);
}

void Dequeue(Queue *queue)
{
  if (isEmptyCircular(*queue))
  {
    printf("Queue is empty.\n");
    return;
  }
  int data = queue->items[queue->front];
  if (queue->front == queue->rear)
  {
    queue->front = queue->rear = -1;
  }
  else
  {
    queue->front = (queue->front + 1) % queue->size;
  }
  printf("The element %d is dequed.\n", data);
}

void displayCircularQueue(Queue queue)
{
  if (isEmptyCircular(queue))
  {
    printf("Queue is empty.\n");
    return;
  }
  printf("Queue elements: ");
  int i = queue.front;
  while (1)
  {
    printf("%d ", queue.items[i]);
    if (i == queue.rear)
      break;
    i = (i + 1) % queue.size;
  }
  printf("\n");
}

int main()
{
  Queue circularQueue = {NULL, -1, -1, 0};
  int choice, size;
  do
  {
    printf("1. Initialize Queue (Circular Queue)\n");
    printf("2. Enque\n");
    printf("3. Deque\n");
    printf("4. Display Items\n");
    printf("5. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      if (circularQueue.size && circularQueue.items != NULL)
      {
        printf("Queue is already initialized.\n");
        break;
      }
      printf("Enter the size of the queue : ");
      scanf("%d", &size);
      createQueue(&circularQueue, size);
      printf("Queue initialized successfully.\n");
      break;
    case 2:
      Enqueue(&circularQueue);
      break;
    case 3:
      Dequeue(&circularQueue);
      break;
    case 4:
      displayCircularQueue(circularQueue);
      break;
    case 5:
      printf("Exiting program...\n");
      break;
    default:
      printf("Invalid choice.\n");
      break;
    }
  } while (choice != 5);
  freeQueue(&circularQueue);
  return 0;
}
