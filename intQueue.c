#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define EMPTY 0
#define CAPACITY 10
// #define INITIAL_CAPACITY 8

typedef struct intQueue {
    int size; //no of elements in queue
    // int capacity; //max capacity of queue
    int front; //first element of queue
    int back; //last element of queue
    int data[CAPACITY]; //pointer to array
} queue;

void initialise(queue *q) {
    q->front = EMPTY;
    q->back = EMPTY;
    q->size = 0;
    // q->capacity = INITIAL_CAPACITY;
}

void enqueue(queue *q, int value) {
    if (q->size == CAPACITY) {
        printf("Warning: Cannot push, queue is full!\n");
        return;
    }
    if (q->size == 0) {
        printf("Putting %d at %d index.\n", value, q->back);
        q->data[q->back] = value;
    }
    else {
        q->back = (q->back + 1) % CAPACITY;
        printf("Putting %d at %d index.\n", value, q->back);
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
    printf("Removing %d from %d index.\n", value, q->front);
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

int main() {
    queue Q;
    initialise(&Q);
    for (int i =0; i<8; i++) {
        enqueue(&Q, i+1);
    }
    printf("%d\n", dequeue(&Q));
    printf("%d\n", dequeue(&Q));
    for (int i=0; i<4; i++) {
        enqueue(&Q, i+9);
    }
    printf("%d\n", dequeue(&Q));
    printf("%d\n", dequeue(&Q));
    for (int i=0; i<2; i++) {
        enqueue(&Q, i+13);
    }
    while(!isEmpty(&Q)) {
        printf("%d\n", dequeue(&Q));
    }
    return 0;
}
