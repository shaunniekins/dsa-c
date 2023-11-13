#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a graph with an array of linked lists
struct Graph {
    int V;            // Number of vertices
    struct Node** adjList; // Array of adjacency lists
};

// Create a new node with the given data
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode1 = newNode(dest);
    newNode1->next = graph->adjList[src];
    graph->adjList[src] = newNode1;

    struct Node* newNode2 = newNode(src);
    newNode2->next = graph->adjList[dest];
    graph->adjList[dest] = newNode2;
}

// Perform BFS traversal starting from a given vertex
void BFS(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Create a queue for BFS
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    printf("Breadth-First Traversal starting from vertex 0: ");
    BFS(graph, 0);

    return 0;
}
