#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define CAPACITY 8

typedef struct intQueue {
    int size; //no of elements in queue
    int front; //first element of queue
    int back; //last element of queue
    int data[CAPACITY]; //pointer to array
} queue;

void initialise(queue *q) {
    q->front = EMPTY;
    q->back = EMPTY;
    q->size = 0;
}

void enqueue(queue *q, int value) {
    if (q->size == CAPACITY) {
        printf("Warning: Cannot push, queue is full!\n");
        return;
    }
    if (q->size == 0) {
        q->data[q->back] = value;
    }
    else {
        q->back = (q->back + 1) % CAPACITY;
        q->data[q->back] = value;
    }
    q->size++;
}

int dequeue(queue *q) {
    if (q->size == 0) {
        printf("Warning: Queue empty!\n");
        q->front = EMPTY;
        q->back = EMPTY;
        return INT32_MIN;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return value;
}

int size(queue *q) {
    return q->size;
}

int front(queue *q) {
    if (q->size == 0) {
        printf("Warning: Queue empty!\n");
        return INT32_MIN;
    }
    else {
        return q->data[q->front];
    }
}

int back(queue *q) {
    if (q->size == 0) {
        printf("Warning: Queue empty!\n");
        return INT32_MIN;
    }
    else {
        return q->data[q->back];
    }
}

int isEmpty(queue *q) {
    return q->size ? 0 : 1;
}

void clear(queue *q) {
    initialise(q);
}