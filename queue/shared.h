#ifndef SHARED_H
#define SHARED_H

typedef struct
{
  int *items;
  int rear;
  int front;
  int size;
} Queue;

void createQueue(Queue *queue, int size);
int isEmpty(Queue queue);
int isFull(Queue queue);
void freeQueue(Queue *queue);
void displayQueue(Queue queue);

#endif
