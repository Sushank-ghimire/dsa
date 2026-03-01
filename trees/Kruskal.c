#include <stdio.h>
#include <stdlib.h>

/* Structure */
typedef struct {
  int u, v, weight;
} Edge;

typedef struct {
  int parent, rank;
} Subset;

/* Utility Functions */
int compare(const void *a, const void *b);
int find(Subset[], int);
void unionSet(Subset[], int, int);

void kruskalMST(int, int);

int main() {
  int choice;
  int v, e;
  while(1) {
    printf("1. Kruskal Algorithm\n");
    printf("2. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the number of vertices : ");
        scanf("%d", &v);
        printf("Enter the number of edges : ");
        scanf("%d", &e);
        kruskalMST(v, e);
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

int compare(const void *a, const void *b) {
  const Edge *e1 = (const Edge *)a;
  const Edge *e2 = (const Edge *)b;

  if (e1->weight < e2->weight) return -1;
  if (e1->weight > e2->weight) return 1;
  return 0;
}

int find(Subset subsets[], int i) {
  if(subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void unionSet(Subset subsets[], int x, int y) {
  int rootX = find(subsets, x);
  int rootY = find(subsets, y);

  if(subsets[rootX].rank < subsets[rootY].rank)
    subsets[rootX].parent = rootY;
  else if (subsets[rootX].rank > subsets[rootY].rank)
    subsets[rootY].parent = rootX;
  else {
    subsets[rootY].parent = rootX;
    subsets[rootX].rank++;
  }
}

void kruskalMST(int v, int e) {
  Edge edges[e];
  printf("\nEnter each edge in format:\n");
  printf("source destination weight\n");
  printf("(Vertices must be between 0 and %d)\n\n", v - 1);

  for(int i = 0; i < e; i++) {
    printf("Edge %d: ", i + 1);
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    if(edges[i].u >= v || edges[i].v >= v || edges[i].u < 0 || edges[i].v < 0) {
      printf("Invalid vertex! Try again.\n");
      i--;
    }
  }
  qsort(edges, e, sizeof(edges[0]), compare);

  Subset subsets[v];
  for(int i=0; i<v; i++) {
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }
  int count = 0, totalCost = 0;

  printf("\nEdges in MST (Kruskal) : \n");
  for(int i=0; i<e && count < v-1; i++) {
    int x = find(subsets, edges[i].u);
    int y = find(subsets, edges[i].v);

    if(x != y) {
      printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].weight);
      totalCost += edges[i].weight;
      unionSet(subsets, x, y);
      count++;
    }
  }
  printf("Total Cost = %d\n", totalCost);
}
