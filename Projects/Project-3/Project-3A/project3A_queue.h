#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#define INITIAL_QUEUE_SIZE 8
#define MAX_STRING_LEN 256

typedef struct
{
    char** arr;     // Queue array - pointer to a pointer to a char data type
    int front;      // Queue front index, initially 0
    int back;       // Queue rear index, initially 0
    int capacity;   // Queue capacity, initially 8
    int size;       // Queue array populated count, initially 0
} Queue;

void initialize(Queue* q);

void cleanup(Queue* q);

int isFull(Queue* q);

int isEmpty(Queue* q);

void resize(Queue* q);

void enqueue(Queue* q, char* value);

char* dequeue(Queue* q);

void printQueue(Queue* q);

#endif /* DYNAMIC_QUEUE_H */
