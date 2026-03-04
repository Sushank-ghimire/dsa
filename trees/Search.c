#include <stdio.h>
#define MAX 100

/* Global Variables */
int graph[MAX][MAX], V;

/* Function Declarations */
void DFS(int, int[]);
void BFS(int);

int main() {
  int choice, start;

  while(1) {
    printf("1. DFS Traversal\n");
    printf("2. BFS Traversal\n");
    printf("3. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    if(choice == 3) break;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 = No edge, 1 = Edge):\n");
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        printf("Edge between %d and %d: ", i, j);
        scanf("%d", &graph[i][j]);
      }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if(start < 0 || start >= V) {
      printf("Invalid vertex!\n");
      continue;
    }

    if(choice == 1) {
      int visited[MAX] = {0};
      printf("DFS Traversal: ");
      DFS(start, visited);
    } else if(choice == 2) {
      printf("BFS Traversal: ");
      BFS(start);
    } else {
      printf("Invalid choice!\n");
    }
    printf("\n");
  }

  return 0;
}

/* Function Definations */
void DFS(int v, int visited[]) {
  visited[v] = 1;
  printf("%d ", v);

  for(int i = 0; i < V; i++)
    if(graph[v][i] && !visited[i])
      DFS(i, visited);
}


void BFS(int start) {
  int visited[MAX] = {0};
  int queue[MAX], front = 0, rear = 0;

  visited[start] = 1;
  queue[rear++] = start;

  while(front < rear) {
    int v = queue[front++];
    printf("%d ", v);

    for(int i = 0; i < V; i++) {
      if(graph[v][i] && !visited[i]) {
        visited[i] = 1;
        queue[rear++] = i;
      }
    }
  }
  printf("\n");
}
