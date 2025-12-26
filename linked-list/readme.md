# Linked List in DSA

## 📌 What is a Linked List?

A **linear data structure** where elements (nodes) are stored in non-contiguous memory locations. Each node contains:

- **Data**: The actual value
- **Pointer/Reference**: Link to the next node (and previous in doubly linked list)

---

## 🔗 Types of Linked Lists

### 1. **Singly Linked List**

- Each node points to the **next node** only
- Last node points to `NULL`
- Traversal: **One direction** (forward only)

### 2. **Doubly Linked List**

- Each node has **two pointers**: next and previous
- Traversal: **Both directions** (forward & backward)
- Extra memory for previous pointer

### 3. **Circular Linked List**

- Last node points back to the **first node** (no NULL)
- Can be singly or doubly circular
- Useful for round-robin scheduling

---

## ⚙️ How It Works

```
[Data|Next] -> [Data|Next] -> [Data|Next] -> NULL
   HEAD           Node           TAIL
```

- **HEAD**: Pointer to first node
- Nodes connected via pointers
- Dynamic size (grows/shrinks at runtime)

---

## ⏱️ Time Complexity

| Operation              | Array | Linked List    |
| ---------------------- | ----- | -------------- |
| **Access**             | O(1)  | O(n)           |
| **Search**             | O(n)  | O(n)           |
| **Insert (Beginning)** | O(n)  | O(1)           |
| **Insert (End)**       | O(1)  | O(n) or O(1)\* |
| **Insert (Middle)**    | O(n)  | O(n)           |
| **Delete (Beginning)** | O(n)  | O(1)           |
| **Delete (End)**       | O(1)  | O(n)           |
| **Delete (Middle)**    | O(n)  | O(n)           |

\*O(1) if tail pointer is maintained

---

## ✅ Pros (Advantages)

1. **Dynamic Size**: Grows/shrinks as needed (no fixed size)
2. **Efficient Insertion/Deletion**: O(1) at beginning
3. **No Memory Waste**: Allocates memory only when needed
4. **Easy Implementation**: Of stacks, queues, graphs
5. **No Shifting Required**: Unlike arrays

---

## ❌ Cons (Disadvantages)

1. **No Random Access**: Must traverse from head (O(n))
2. **Extra Memory**: Pointers take additional space
3. **Cache Unfriendly**: Non-contiguous memory (poor locality)
4. **Traversal Overhead**: Sequential access only
5. **Reverse Traversal**: Difficult in singly linked list

---

## 🔑 Key Operations

### Basic Operations:

- `insertAtBeginning()` - Add node at start
- `insertAtEnd()` - Add node at end
- `deleteNode()` - Remove a node
- `search()` - Find a node
- `display()` - Print all nodes
- `reverse()` - Reverse the list

---

## 💡 When to Use?

**Use Linked List when:**

- Frequent insertions/deletions at beginning
- Size is unknown or changes frequently
- No need for random access

**Use Array when:**

- Need random access (index-based)
- Size is fixed or known
- Memory locality is important

---

## 📝 Quick Revision Points

- **Non-contiguous** memory allocation
- **First node** = HEAD, **Last node** → NULL
- **Doubly LL** = bidirectional traversal
- **Circular LL** = last → first (no NULL)
- **Insert at head** = O(1), **Access** = O(n)
- **Dynamic** vs Array (static)
- **Extra memory** for pointers

---

## Program Implementation

```c
// Singly Linked List
typedef struct Node {
	int data;
	struct Node *next; // self referencing structure
} Node;

void traverseNode(Node *node) {
	if(node == NULL) {
		printf("List is empty\n");
		return;
	}
	printf("Linked List Elements are : \n");
	while(node != NULL) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

void insertNode(Node **head) {
	int value;
	printf("Enter value to insert : ");
	scanf("%d", &value);

	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;

	if(*head == NULL) {
		*head = newNode;
		printf("Head node created\n");
		return;
	}

	Node *temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void searchNode(Node *head) {
	int value;
	printf("Enter value to search : ");
	scanf("%d", &value);

	int position = 1;
	Node *temp = head;
	while(temp != NULL) {
		if(temp->data == value) {
			printf("Value %d found at position %d.\n", value, position);
			return;
		}
		temp = head->next;
		position++;
	}
	printf("The value %d not found in the list.\n", value);
}

void deleteNode(Node **head) {
	if(*head == NULL) {
		printf("The list is empth. Nothing can be deleted.\n");
		return;
	}
	int value;
	printf("Enter value to delete : ");
	scanf("%d", &value);

	Node *temp = *head;
	Node *prev = NULL;
	// If head node is to be deleted
	if(temp != NULL && temp->data == value) {
		*head = temp->next;
		free(temp);
		return;
	}
	// Loop to search the node
	while(temp != NULL && temp->data != value) {
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) {
		printf("The required value not found in the list.\n");
		return;
	}
	prev->next = temp->next;
	free(temp);
}

void freeList(Node *head) {
	Node *temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

// Doubly linked list

typedef struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
} Node;

int inputData(char *message) {
  int data;
  printf("%s", message);
  scanf("%d", &data);
  return data;
}

int isNull(Node *head) {
  return head == NULL;
}

void displayLinkedList(Node *head) {
  if(head == NULL) {
    printf("Linked list is empty.\n");
    return;
  }
  Node *temp = head;
  while(temp != NULL) {
    printf("Node : %p: [%p | %d | %p] -> \n",(void *)temp, (void *) temp->prev, temp->data,(void *)temp->next);
    temp = temp->next;
  }
  printf("NULL\n");
}

void insertNode(Node **head) {
  int data = inputData("Enter data to insert in node : ");
  Node *newNode = (Node *) malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  if(isNull(*head)) {
    *head = newNode;
    return;
  }
  Node *temp = *head;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  newNode->prev = temp;
  temp->next = newNode;
}

void insertNodeAtHead(Node **head) {
  int data = inputData("Enter data to insert in node : ");
  Node *newNode = (Node *) malloc(sizeof(Node));

  if(newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = *head;
  if(*head != NULL) {
    (*head)->prev = newNode;
  }
  *head = newNode;
}

void insertNodeAtIndex(Node **head) {
  int index = inputData("Enter the index for the node : ");
  int data = inputData("Enter data to insert in the node : ");
  Node *newNode = (Node *) malloc(sizeof(Node));
  Node *temp = *head;
  int i = 0;
  while(temp != NULL && i < index) {
    temp = temp->next;
    i++;
  }
  if(temp == NULL) {
    printf("The index provided by the user not found\n");
    return;
  }
  newNode->data = data;
  newNode->prev = temp->prev;
  temp->prev->next = newNode;
  newNode->next = temp;
}

void freeMemory(Node *head) {
  Node *temp;
  while(!isNull(head)) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

void deleteFirstNode(Node **head) {
  if (*head == NULL) return;
  Node *temp = *head;
  *head = temp->next;
  if (*head != NULL)
    (*head)->prev = NULL;
  free(temp);
}


void deleteLastNode(Node **head) {
  if(isNull(*head)) {
    printf("Node is empty.\n");
    return;
  }
  Node *temp = *head;
  if(temp->next == NULL) {
    free(temp);
    *head = NULL;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  temp->prev->next = NULL;
  free(temp);
}

void deleteIndexedNode(Node **head) {
  if(isNull(*head)) {
    printf("Linked list is empty.\n");
    return;
  }
  int index = inputData("Enter index to delete : ");
  Node *temp = *head;
  int i = 0;
  if(index == 0) {
    *head = temp->next;
    if(!isNull(*head)) {
      (*head)->prev = NULL;
    }
    free(temp);
    return;
  }

  while(temp != NULL && i < index - 1) {
    temp = temp->next;
    i++;
  }
  if(temp == NULL) {
    printf("The index provided by the user not found\n");
    return;
  }
  if(temp->prev != NULL)
    temp->prev->next = temp->next;

  if(temp->next != NULL)
    temp->next->prev = temp->prev;
  free(temp);
}

// Circular linked list
```
