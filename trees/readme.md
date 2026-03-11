# Trees in DSA

A **Tree** is a non-linear hierarchical data structure consisting of nodes connected by edges. It has a **root** node at the top, and each node can have zero or more child nodes. Trees are used for efficient searching, sorting, and hierarchical data representation.

**Key Terms:**

- **Root:** Topmost node of the tree
- **Parent/Child:** A node that has sub-nodes is parent; sub-nodes are children
- **Leaf:** A node with no children
- **Height:** Longest path from root to a leaf
- **Depth:** Distance from root to a node

---

## 1. Binary Tree

A tree data structure where each node has at most two children (left and right). Insertion is done using **level-order** traversal.

**Time Complexity:** Insertion - O(n), Traversal - O(n)

## 2. Binary Search Tree (BST)

A binary tree where left child < parent < right child. Enables efficient searching, insertion, and deletion.

**Time Complexity:** Average - O(log n), Worst - O(n)

## 3. AVL Tree

A self-balancing BST where the height difference between left and right subtrees is at most 1. Uses rotations (LL, RR, LR, RL) to maintain balance.

**Time Complexity:** Search, Insert, Delete - O(log n)

## 4. Graph Traversals (DFS & BFS)

- **DFS (Depth First Search):** Explores as far as possible along each branch before backtracking. Uses recursion/stack.
- **BFS (Breadth First Search):** Explores all neighbors at current depth before moving to next level. Uses queue.

**Time Complexity:** O(V + E) where V = vertices, E = edges

## 5. Dijkstra's Algorithm

Finds shortest path from a source vertex to all other vertices in a weighted graph with non-negative edges.

**Time Complexity:** O(V²) with adjacency matrix

## 6. Prim's Algorithm

Finds Minimum Spanning Tree (MST) by growing the tree one vertex at a time, always adding the minimum weight edge.

**Time Complexity:** O(V²) with adjacency matrix

## 7. Kruskal's Algorithm

Finds MST by sorting all edges and adding them if they don't form a cycle. Uses Union-Find data structure.

**Time Complexity:** O(E log E)

---

## Tree Traversals

```c
// Inorder (Left, Root, Right)
void inorder(Node* root) {
  if(root == NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

// Preorder (Root, Left, Right)
void preorder(Node* root) {
  if(root == NULL) return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

// Postorder (Left, Right, Root)
void postorder(Node* root) {
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}
```

## Graph Traversals

```c
// DFS - Depth First Search (Recursive)
void DFS(int v, int visited[]) {
  visited[v] = 1;
  printf("%d ", v);
  for(int i = 0; i < V; i++)
    if(graph[v][i] && !visited[i])
      DFS(i, visited);
}

// BFS - Breadth First Search (Using Queue)
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
}
```
