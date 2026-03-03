#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int[], int[], int);

void PrimsMST(int v);

int main() {
  int choice;
  int v, e;
  while(1) {
    printf("1. Prim's Algorithm\n");
    printf("2. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the number of vertices : ");
        scanf("%d", &v);
        PrimsMST(v);
        break;
      case 2:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
    printf("\n");
  }
  return 0;
}

int minKey(int key[], int mstSet[], int v) {
  int min = INT_MAX, min_index = -1;
  for(int i = 0; i < v; i++) {
    if(!mstSet[i] && key[i] < min) {
      min = key[i];
      min_index = i;
    }
  }
  return min_index;
}

void PrimsMST(int v) {
  int graph[v][v];
  printf("\nEnter adjacency matrix: \n");
  printf("For no edge between two vertices, enter 0.\n");
  printf("Vertices are numbered from 0 to %d\n", v-1);

  for(int i=0; i<v; i++) {
    for(int j=0; j<v; j++) {
      printf("Edge weight from vertex %d to vertex %d: ", i, j);
      scanf("%d", &graph[i][j]);
      if(graph[i][j] == 0)
        graph[i][j] = INT_MAX; // treating 0 as no edge
    }
  }
  int parent[v], key[v], mstSet[v];

  for(int i=0; i<v; i++) {
    key[i] = INT_MAX;
    mstSet[i] = 0;
  }

  key[0] = 0;     // Start from vertex 0
  parent[0] = -1; // Root of MST

  for(int count = 0; count < v-1; count++) {
    int u = minKey(key, mstSet, v);
    if(u == -1) {
      printf("Graph is disconnected. MST not possible.\n");
      return;
    }
    mstSet[u] = 1;

    for(int j = 0; j < v; j++) {
      if(!mstSet[j] && graph[u][j] != INT_MAX && graph[u][j] < key[j]) {
          key[j] = graph[u][j];
          parent[j] = u;
      }
    }
  }

  int totalCost = 0;
  printf("\nEdges in MST (Prim's): \n");
  for(int i = 1; i < v; i++) {
    printf("%d -- %d == %d\n", parent[i], i, key[i]);
    totalCost += key[i];
  }
  printf("Total cost = %d\n", totalCost);
}
