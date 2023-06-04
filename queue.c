#include "queue.h"

void initQueue(Queue* queue) {
    queue->front = NULL;
    pthread_mutex_init(&(queue->mutex), NULL);
    pthread_cond_init(&(queue->cond), NULL);
}

void printQueue(Queue* queue) {
    if(queue == NULL) {
        printf("queue null");
        return;
    }
    Node * temp = queue->front;
    while(temp != NULL && temp->task != NULL) {
        printf("%d\n", *(int*)temp->task);
        temp = temp->next;
    }
    printf("\n\n");
}

void enqueue(Queue* queue, void* _element) {
    if (queue == NULL) {
        printf("queue null");
        return;
    }

    pthread_mutex_lock(&(queue->mutex));

    if (queue->front == NULL) {
        queue->front = (Node*)malloc(sizeof(Node));
        queue->front->task = _element;
        queue->front->next = NULL;
    } 
    else {
        Node * temp = queue->front;
        while(temp->next != NULL) temp = temp->next;
        temp->next = (Node*)malloc(sizeof(Node));
        temp = temp->next;
        temp->task = _element;
        temp->next = NULL;
    }
    pthread_cond_signal(&(queue->cond));
    pthread_mutex_unlock(&(queue->mutex));
}

void* dequeue(Queue* queue) {
    if (queue == NULL) {
        printf("queue null");
        return NULL;
    }

    
    pthread_mutex_lock(&(queue->mutex));
    while (queue->front == NULL) {
        pthread_cond_wait(&(queue->cond), &(queue->mutex));
        if(queue->front != NULL && queue->front->task == NULL) return NULL;
    }

    Node* temp = queue->front;
    void* element = NULL;

    element = temp->task;

    if (queue->front->next == NULL) queue->front = NULL; 
    else queue->front = queue->front->next;

    free(temp);
    
    pthread_mutex_unlock(&(queue->mutex));

    return element;
}

void destroyThread(Queue* queue) {
    pthread_mutex_destroy(&(queue->mutex));
    pthread_cond_destroy(&(queue->cond));
}