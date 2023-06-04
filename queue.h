#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node {
    void* task;
    struct Node* next;
} Node;


typedef struct Queue {
    Node* front;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Queue;

void initQueue(Queue*);
void enqueue(Queue*, void*);
void* dequeue(Queue*);
void destroyThread(Queue*);
void printQueue(Queue*);


#endif