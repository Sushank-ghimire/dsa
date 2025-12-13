#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int size;
  int *items;
} Data;

int allocateMalloc(Data *data, int size)
{
  data->items = malloc(size * sizeof(int));
  if (!data->items)
    return 0;
  data->size = size;
  return 1;
}

int allocateCalloc(Data *data, int size)
{
  data->items = calloc(size, sizeof(int));
  if (!data->items)
    return 0;
  data->size = size;
  return 1;
}

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

void fillData(Data *data)
{
  for (int i = 0; i < data->size; i++)
  {
    data->items[i] = (i + 1) * 2;
  }
}

void printData(const Data *data)
{
  printf("Data items: ");
  for (int i = 0; i < data->size; i++)
  {
    printf("%d ", data->items[i]);
  }
  printf("\n");
}

void freeMemory(Data *data)
{
  free(data->items);
  data->items = NULL;
  data->size = 0;
}

int main()
{
  int choice, size;
  Data data = {0, NULL};

  do
  {
    printf("\n1. malloc\n2. calloc\n3. realloc\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter size to allocate memory: ");
      scanf("%d", &size);
      if (!allocateMalloc(&data, size))
        printf("Allocation failed\n");
      break;

    case 2:
      printf("Enter size to allocate memory: ");
      scanf("%d", &size);
      if (!allocateCalloc(&data, size))
        printf("Allocation failed\n");
      break;

    case 3:
      printf("Enter the new size to reallocate memory: ");
      scanf("%d", &size);
      if (!reallocate(&data, size))
        printf("Reallocation failed\n");
      break;

    case 4:
      freeMemory(&data);
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid choice\n");
    }

    if (data.items)
    {
      fillData(&data);
      printData(&data);
    }

  } while (choice != 4);

  return 0;
}
