#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create an empty queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int main() {
    struct Queue* queue = createQueue(MAX_QUEUE_SIZE);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued item: %d\n", dequeue(queue));

    enqueue(queue, 40);

    printf("Queue Front: %d, Queue Rear: %d\n", queue->array[queue->front], queue->array[queue->rear]);

    return 0;
}
