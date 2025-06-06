#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define INITIAL_CAPACITY 8
#define DOUBLING_THRESHOLD 0.9
#define SHIFTING_THRESHOLD 0.25

typedef struct intQueue {
    int size; //no of elements in queue
    int capacity; //max capacity of queue
    int front; //first element of queue
    int back; //last element of queue
    int *data; //pointer to array
} queue;

void initialise(queue *q) {
    q->capacity = INITIAL_CAPACITY;
    q->size = EMPTY;
    q->front = EMPTY;
    q->back = EMPTY;
    q->data = (int *)calloc(INITIAL_CAPACITY, sizeof(int));
}

void shiftData(queue *q, int decrement) {
    for (int i = 0; i < q->size; i++) {
        q->data[i] = q->data[(q->front + i)];
    }
    q->front = 0;
    q->back = q->size - decrement;
}

void halveCapacity(queue *q) {
    int *tempMemory = (int *)realloc(q->data, q->capacity/2 * sizeof(int));
    q->data = tempMemory;
    q->capacity /= 2;
}

void doubleCapacity(queue *q) {
    int *tempMemory = (int *)realloc(q->data, 2 * q->capacity * sizeof(int));
    q->data = tempMemory;
    q->capacity *= 2;
}

void enqueue(queue *q, int value) {
    if (q->size == 0) {
        q->data[q->back] = value;
        q->size++;
    }
    else {
        q->size++;
        if ((float)q->front / (float)q->capacity >= SHIFTING_THRESHOLD) {
            shiftData(q, 2);
        }
        else if (q->size >= (float)(DOUBLING_THRESHOLD * (float)q->capacity)) {
            doubleCapacity(q);
        }
        q->back++;
        q->data[q->back] = value;
    }
}

int dequeue(queue *q) {
    if (q->size == 0) {
        printf("Warning: Queue empty!\n");
        q->front = EMPTY;
        q->back = EMPTY;
        return INT32_MIN;
    }
    int value = q->data[q->front];
    q->size--;
    q->front++;
    if ((float)q->front / (float)q->capacity >= SHIFTING_THRESHOLD) {
        shiftData(q, 1);
    }
    if  (q->size < (0.5 * q->capacity) && (q->capacity * 0.5) >= INITIAL_CAPACITY) {
        if (q->back >= q->capacity / 2) {
            shiftData(q, 1);
        }
        halveCapacity(q);
    }
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
    int *tempMemory = (int *)realloc(q->data, INITIAL_CAPACITY * sizeof(int));
    q->data = tempMemory;
    q->capacity = INITIAL_CAPACITY;
    q->size = EMPTY;
    q->front = EMPTY;
    q->back = EMPTY;
}