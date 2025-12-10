#include "shared.h"
#include <stdio.h>

void Enqueue(Queue *queue)
{
  int data;
  if (isFull(*queue))
  {
    printf("Queue is full, cannot enqueue.\n");
    return;
  }
  printf("Enter a value to insert : ");
  scanf("%d", &data);
  if (queue->front == -1)
  {
    queue->front = 0;
  }
  queue->items[++(queue->rear)] = data;
  printf("Inserted to the queue.\n");
}

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
    int value = queue->items[queue->front++];
    printf("Element %d is removed from queue.\n", value);
  }
}

int main()
{
  Queue linearQueue = {NULL, -1, 0, 0};
  int choice, size;
  do
  {
    printf("1. Initialize Queue\n");
    printf("2. Enque\n");
    printf("3. Deque\n");
    printf("4. Display Items\n");
    printf("5. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the size of the queue : ");
      scanf("%d", &size);
      createQueue(&linearQueue, size);
      printf("Queue initialized successfully.\n");
      break;
    case 2:
      Enqueue(&linearQueue);
      break;
    case 3:
      Dequeue(&linearQueue);
      break;
    case 4:
      displayQueue(linearQueue);
      break;
    case 5:
      printf("Exiting program...\n");
      break;
    default:
      printf("Invalid choice.\n");
      break;
    }
  } while (choice != 5);
  freeQueue(&linearQueue);
  return 0;
}
