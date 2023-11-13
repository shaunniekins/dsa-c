#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create an empty stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to get the top item of the stack without popping it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->array[stack->top];
}

int main() {
    struct Stack* stack = createStack(MAX_STACK_SIZE);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top item: %d\n", peek(stack));

    printf("Popped item: %d\n", pop(stack));

    printf("Stack is empty: %s\n", isEmpty(stack) ? "true" : "false");

    return 0;
}
