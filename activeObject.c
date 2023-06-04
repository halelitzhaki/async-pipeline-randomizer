#include "activeObject.h"

void createActiveObject(pActiveObject this, pActiveObject next, void *(*func)(pActiveObject, void*)) {
    this->queue = (Queue*)malloc(sizeof(Queue));
    this->function = func;
    this->next = next;
    pthread_create(&(this->threadID), NULL, runActiveObject, (void*)this);
}

void *runActiveObject(void* this) {
    pActiveObject _this = (pActiveObject)this;
    void * task = NULL;
    while((task = dequeue(_this->queue)) != NULL) {
        _this->function(_this, task);
        task = NULL;
    }
    if(_this->next != NULL) enqueue(getQueue(_this->next), NULL);
    stop(_this);
}

Queue* getQueue(pActiveObject this) {
    return this->queue;
}

void stop(pActiveObject this) {
    destroyThread(this->queue);
    free(this->queue);
    free(this);
    pthread_exit(NULL);
}