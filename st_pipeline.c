#include "activeObject.h"
#include "prime.h"

int main(int argc, char * argv[]) {
    if(argc == 1) {
        printf("Invalid Input!");
        return 0;
    }
    int seed = 0;
    if(argc == 2) {
        seed = (unsigned int)time(NULL);
    }
    else seed = atoi(argv[2]);

    int numNumbers = atoi(argv[1]), *userArguments = (int*)malloc(sizeof(int)*2);
    userArguments[0] = seed;
    userArguments[1] = numNumbers;

    pActiveObject first = (pActiveObject)malloc(sizeof(ActiveObject)), 
    second = (pActiveObject)malloc(sizeof(ActiveObject)),
    third = (pActiveObject)malloc(sizeof(ActiveObject)),
    fourth = (pActiveObject)malloc(sizeof(ActiveObject));
    
    createActiveObject(first, second, firstActiveObject);
    createActiveObject(second, third, secondActiveObject);
    createActiveObject(third, fourth, thirdActiveObject);
    createActiveObject(fourth, NULL, fourthActiveObject);
    
    enqueue(getQueue(first), (void*)userArguments);
    enqueue(getQueue(first), NULL);

    pthread_join(first->threadID, NULL);
    pthread_join(second->threadID, NULL);
    pthread_join(third->threadID, NULL);
    pthread_join(fourth->threadID, NULL);

    free(userArguments);        

    return 0;
}

void *firstActiveObject(pActiveObject this, void * args) {
    int * _args = (int*)args, *p = NULL;
    srand(_args[0]);
    
    for (int i = 0; i < _args[1]; i++) {
        p = (int*)malloc(sizeof(int));
        *p = rand() % 900000 + 100000;
        enqueue(getQueue(this->next), p);
        usleep(1000);
    }
    return NULL;
}

void *secondActiveObject(pActiveObject this, void* arg) {    
    int * _arg = (int*)arg;
    
    printf("%d\n", *_arg);
    if(isPrime(*_arg) == TRUE) printf("true\n");
    else printf("false\n");
    
    *_arg += 11;
    
    enqueue(getQueue(this->next), _arg);
    return NULL;
}

void *thirdActiveObject(pActiveObject this, void* arg) {    
    int * _arg = (int*)arg;
    
    printf("%d\n", *_arg);
    if(isPrime(*_arg) == TRUE) printf("true\n");
    else printf("false\n");
    
    *_arg -= 13;
    
    enqueue(getQueue(this->next), _arg);
    return NULL;
}

void *fourthActiveObject(pActiveObject this, void* arg) {    
    int * _arg = (int*)arg;
    
    printf("%d\n", *_arg);
    if(isPrime(*_arg) == TRUE) printf("true\n");
    else printf("false\n");
    
    *_arg += 2;
    printf("%d\n", *_arg);
    return NULL;
}