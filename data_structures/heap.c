#include <stdio.h>

#define MAX_HEAP_SIZE 100

// Structure to represent a binary max-heap
struct MaxHeap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

// Function to initialize an empty max-heap
void initializeMaxHeap(struct MaxHeap* heap) {
    heap->size = 0;
}

// Function to swap two elements in the max-heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with the root at the given index
void maxHeapify(struct MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compare the left child with the current largest
    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }

    // Compare the right child with the current largest
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and heapify the affected subtree
    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

// Function to insert a new element into the max-heap
void insert(struct MaxHeap* heap, int data) {
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert %d.\n", data);
        return;
    }

    // Insert the new element at the end of the heap
    int index = heap->size;
    heap->arr[index] = data;
    heap->size++;

    // Heapify the tree by comparing the element with its parent
    while (index > 0 && heap->arr[(index - 1) / 2] < heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to extract the maximum element from the max-heap
int extractMax(struct MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    // The maximum element is at the root
    int max = heap->arr[0];

    // Replace the root with the last element in the heap
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify the tree to maintain the max-heap property
    maxHeapify(heap, 0);

    return max;
}

int main() {
    struct MaxHeap heap;
    initializeMaxHeap(&heap);

    insert(&heap, 10);
    insert(&heap, 30);
    insert(&heap, 20);
    insert(&heap, 40);
    insert(&heap, 5);

    printf("Max-Heap: ");
    for (int i = 0; i < heap.size; i++) {
        printf("%d ", heap.arr[i]);
    }
    printf("\n");

    int max = extractMax(&heap);
    printf("Extracted Max: %d\n", max);

    return 0;
}
