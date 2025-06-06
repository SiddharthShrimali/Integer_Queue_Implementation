#ifndef intQueue_h
#define intQueue_h
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

void initialise(queue *q);

void enqueue(queue *q, int value);

int dequeue(queue *q);

int size(queue *q);

int front(queue *q);

int back(queue *q);

int isEmpty(queue *q);

void clear(queue *q);

#endif