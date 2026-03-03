#include <limits.h>
#include <stdio.h>

int minDistance(int[], int[], int);
void Dijkstra(int);

int main() {
  int choice, V;
  while(1) {
    printf("1. Dijkstra's Algorithm\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter number of vertices: ");
        scanf("%d", &V);
        Dijkstra(V);
        break;
      case 2:
        return 0;
      default:
        printf("Invalid choice!\n");
    }
    printf("\n");
  }
  return 0;
}

int minDistance(int dist[], int visited[], int V) {
  int min = INT_MAX, min_index;

  for(int i = 0; i < V; i++)
    if(!visited[i] && dist[i] <= min) {
      min = dist[i];
      min_index = i;
    }
  return min_index;
}

void Dijkstra(int V) {
  int graph[V][V];
  printf("\nEnter adjacency matrix (0 = no edge) : \n");

  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      printf("Edge weight from %d to %d : ", i, j);
      scanf("%d", &graph[i][j]);
      if(graph[i][j] == 0)
        graph[i][j] = INT_MAX;
    }
  }

  int src;
  printf("Enter souce vertex (0 to %d) : ", V-1);
  scanf("%d", &src);

  int dist[V], visited[V];

  for(int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }

  dist[src] = 0;

  for(int count = 0; count < V-1; count++) {
    int u = minDistance(dist, visited, V);
    visited[u] = 1;

    for(int v = 0; v < V; v++) {
      if(!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printf("\nShortest distances from vertex %d : \n", src);
  for(int i = 0; i < V; i++) {
    if(dist[i] == INT_MAX)
      printf("%d --> %d = INF\n", src, i);
    else
      printf("%d --> %d = %d\n", src, i, dist[i]);
  }
}
