#ifndef ACTIVE_OBJECT_H
#define ACTIVE_OBJECT_H

#include "queue.h"
#include "prime.h"
#include <unistd.h>


typedef struct ActiveObject {
    Queue* queue;
    void *(*function)(struct ActiveObject*, void*);
    pthread_t threadID;
    pthread_mutex_t mutex;
    struct ActiveObject * next;
} ActiveObject, *pActiveObject;

void *runActiveObject(void*);
void createActiveObject(pActiveObject, pActiveObject, void *(*)(pActiveObject, void*));
Queue* getQueue(pActiveObject);
void stop(pActiveObject);

void *firstActiveObject(pActiveObject,void*);
void *secondActiveObject(pActiveObject,void*);
void *thirdActiveObject(pActiveObject,void*);
void *fourthActiveObject(pActiveObject,void*);

#endif