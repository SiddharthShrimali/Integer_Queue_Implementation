#ifndef intQueue_Dynamic_h
#define intQueue_Dynamic_h
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

void initialise(queue *q);

void enqueue(queue *q, int value);

int dequeue(queue *q);

int size(queue *q);

int front(queue *q);

int back(queue *q);

int isEmpty(queue *q);

void clear(queue *q);

#endif