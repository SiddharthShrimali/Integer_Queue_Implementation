#ifndef intQueue_ll_h
#define intQueue_ll_h
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

typedef struct intQueue {
    int size; //number of nodes
    node *frontNode; //first node
    node *backNode; //last node
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