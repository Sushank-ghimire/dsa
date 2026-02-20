#include <stdio.h>
#include <stdlib.h>

#define T_SIZE 200

/* Structure Definations */
typedef struct {
  int key;
} DataItem;

typedef struct {
  int size;
  DataItem* table[T_SIZE];
} HashTable;

/* Helper Functions */
int input(char *);

/* Hash table methods declarations */
void initTable(HashTable*);
int hashFunction(HashTable*, int);
void insert(HashTable*);
int search(HashTable*);
void display(HashTable*);
void freeMemory(HashTable*);

int main() {
  HashTable ht;
  int choice, pos;

  initTable(&ht);
  do {
    printf("\n--- Hash Table (Linear Probing) ---\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    choice = input("Enter your choice : ");
    switch (choice) {
      case 1:
        insert(&ht);
        break;
      case 2:
        pos = search(&ht);
        if(pos == -1)
          printf("Key not found.\n");
        else
          printf("Key found at index %d.\n", pos);
        break;
      case 3:
        display(&ht);
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 4);
  freeMemory(&ht);
  return 0;
}

int input(char *msg) {
  int data;
  printf("%s", msg);
  scanf("%d", &data);
  return data;
}

void initTable(HashTable* ht) {
  int size = input("Enter the size of the hash table (max 200) : ");
  ht->size = size;
  for(int i=0; i<ht->size; i++)
    ht->table[i] = NULL;
}

int hashFunction(HashTable *ht, int key) {
  return key % ht->size;
}

void insert(HashTable* ht) {
  int key = input("Enter key to insert : ");
  int index = hashFunction(ht, key);
  int i = 0;

  while(ht->table[(index + i) % ht->size] != NULL) {
    i++;
    if(i == ht->size) {
      printf("Hash table is full\n");
      return;
    }
  }

  int insertIndex = (index+i) % ht->size;
  DataItem *item = (DataItem *) malloc(sizeof(DataItem));
  item->key = key;
  ht->table[insertIndex] = item;
  printf("Inserted at index %d.\n", insertIndex);
}

int search(HashTable* ht) {
  int key = input("Enter key to search : ");
  int index = hashFunction(ht, key);

  int i = 0;
  while (ht->table[(index+i) % ht->size] != NULL) {
    if(ht->table[(index+i) % ht->size]->key == key)
      return (index+i) % ht->size;

    i++;
    if(i == ht->size)
      break;
  }
  return -1;
}

void display(HashTable* ht) {
  printf("\nHash Table : \n");
  for(int i=0; i<ht->size; i++) {
    if(ht->table[i] != NULL)
      printf("[%d] --> %d\n", i, ht->table[i]->key);
    else
      printf("[%d] --> EMPTY\n", i);
  }
}

void freeMemory(HashTable *ht) {
  for(int i=0; i<ht->size; i++) {
    free(ht->table[i]);
  }
}
