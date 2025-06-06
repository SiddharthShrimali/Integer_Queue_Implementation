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

void initialise(queue *q) {
    q->size = 0;
    q->frontNode = NULL;
    q->backNode = NULL;
}

void enqueue(queue *q, int value) {
    node *temp;
    temp = (node *) malloc(sizeof(node));
    if (q->size == 0) {
        temp->data = value;
        temp->next = q->frontNode;
        q->frontNode = temp;
        q->backNode = temp;
    }
    else {
        temp->data = value;
        q->backNode->next = temp;
        q->backNode = temp;
        q->backNode->next = NULL;
    }
    q->size++;
}

int dequeue(queue *q) {
    if (q->size == 0) {
        printf("Warning: Trying to dequeue from an empty queue!\n");
        return INT32_MIN;
    }
    if (q->size == 1) {
        q->backNode = NULL;
    }
    node *temp;
    temp = q->frontNode;
    q->frontNode = q->frontNode->next;
    int tempValue = temp->data;
    free(temp);
    q->size--;
    return tempValue;
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
        return q->frontNode->data;
    }
}

int back(queue *q) {
    if (q->size == 0) {
        printf("Warning: Queue empty!\n");
        return INT32_MIN;
    }
    else {
        return q->backNode->data;
    }
}

int isEmpty(queue *q) {
    return q->size ? 0 : 1;
}

void clear(queue *q) {
    for(int i = q->size; i > 0; i--) {
        dequeue(q);
    }
}