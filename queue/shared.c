#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int *items;
  int rear;
  int front;
  int size;
} Queue;

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

int isEmpty(Queue queue)
{
  return queue.rear == -1;
}

int isFull(Queue queue)
{
  if (queue.rear == queue.size - 1)
  {
    return 1;
  }
  return 0;
}

void freeQueue(Queue *queue)
{
  free(queue);
}

void displayQueue(Queue queue)
{
  if (queue.rear == -1)
  {
    printf("The queue is empty.\n");
    return;
  }
  int i;
  printf("The elements of the queue are : \n");
  for (i = queue.front; i <= queue.rear; i++)
  {
    printf("%d ", queue.items[i]);
  }
  printf("\n");
}
