#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the Fibonacci Heap
struct Node {
    int key;
    int degree;
    bool marked;
    struct Node* parent;
    struct Node* child;
    struct Node* left;
    struct Node* right;
};

// Structure to represent a Fibonacci Heap
struct FibonacciHeap {
    struct Node* min;
    int size;
};

// Function to create a new node with the given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->degree = 0;
    newNode->marked = false;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->left = newNode;
    newNode->right = newNode;
    return newNode;
}

// Function to initialize an empty Fibonacci Heap
struct FibonacciHeap* initializeFibonacciHeap() {
    struct FibonacciHeap* heap = (struct FibonacciHeap*)malloc(sizeof(struct FibonacciHeap));
    heap->min = NULL;
    heap->size = 0;
    return heap;
}

// Function to link two trees in the Fibonacci Heap
void link(struct Node* min, struct Node* newChild) {
    newChild->left = min;
    newChild->right = min->right;
    min->right = newChild;
    newChild->right->left = newChild;
}

// Function to merge two Fibonacci Heaps
struct FibonacciHeap* merge(struct FibonacciHeap* heap1, struct FibonacciHeap* heap2) {
    if (heap1->min == NULL) {
        return heap2;
    } else if (heap2->min == NULL) {
        return heap1;
    }

    struct Node* min1 = heap1->min;
    struct Node* min2 = heap2->min;
    struct Node* temp = min1->right;
    min1->right = min2->right;
    min2->right = temp;
    min1->right->left = min1;
    min2->right->left = min2;

    if (min2->key < min1->key) {
        heap1->min = min2;
    }

    heap1->size += heap2->size;
    free(heap2);

    return heap1;
}

// Function to insert a node into the Fibonacci Heap
void insert(struct FibonacciHeap* heap, int key) {
    struct Node* newNode = createNode(key);
    if (heap->min == NULL) {
        heap->min = newNode;
    } else {
        heap->min->left->right = newNode;
        newNode->left = heap->min->left;
        heap->min->left = newNode;
        newNode->right = heap->min;

        if (key < heap->min->key) {
            heap->min = newNode;
        }
    }

    heap->size++;
}

// Function to extract the minimum element from the Fibonacci Heap
int extractMin(struct FibonacciHeap* heap) {
    struct Node* min = heap->min;
    if (min != NULL) {
        struct Node* child = min->child;
        if (child != NULL) {
            struct Node* first = child;
            do {
                struct Node* next = child->right;
                min->left->right = child;
                child->left = min->left;
                min->left = child;
                child->right = min;
                if (child->key < min->key) {
                    min = child;
                }
                child->parent = NULL;
                child = next;
            } while (child != first);
        }

        min->left->right = min->right;
        min->right->left = min->left;
        if (min == min->right) {
            heap->min = NULL;
        } else {
            heap->min = min->right;
            consolidate(heap);
        }

        heap->size--;
        int minKey = min->key;
        free(min);
        return minKey;
    }

    return -1; // Heap is empty
}

// Function to consolidate the trees in the Fibonacci Heap
void consolidate(struct FibonacciHeap* heap) {
    int maxDegree = (int)(log(heap->size) / log(2)) + 1;
    struct Node* array[maxDegree];
    for (int i = 0; i < maxDegree; i++) {
        array[i] = NULL;
    }

    struct Node* current = heap->min;
    int numRoots = 0;
    if (current != NULL) {
        numRoots++;
        current = current->right;
        while (current != heap->min) {
            numRoots++;
            current = current->right;
        }
    }

    while (numRoots > 0) {
        int degree = current->degree;
        struct Node* next = current->right;
        while (array[degree] != NULL) {
            struct Node* other = array[degree];
            if (current->key > other->key) {
                struct Node* temp = current;
                current = other;
                other = temp;
            }
            link(current, other);
            array[degree] = NULL;
            degree++;
        }
        array[degree] = current;
        current = next;
        numRoots--;
    }

    heap->min = NULL;
    for (int i = 0; i < maxDegree; i++) {
        if (array[i] != NULL) {
            if (heap->min == NULL) {
                array[i]->left = array[i];
                array[i]->right = array[i];
                heap->min = array[i];
            } else {
                heap->min->left->right = array[i];
                array[i]->left = heap->min->left;
                heap->min->left = array[i];
                array[i]->right = heap->min;
                if (array[i]->key < heap->min->key) {
                    heap->min = array[i];
                }
            }
        }
    }
}

int main() {
    struct FibonacciHeap* heap = initializeFibonacciHeap();

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 5);

    printf("Minimum key: %d\n", heap->min->key);

    int minKey = extractMin(heap);
    printf("Extracted Minimum key: %d\n", minKey);

    return 0;
}
