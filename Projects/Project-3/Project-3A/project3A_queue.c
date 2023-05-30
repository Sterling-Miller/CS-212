#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3A_queue.h"

void initialize(Queue* q)
{
    q->arr = (char**)malloc((MAX_STRING_LEN + 1) * INITIAL_QUEUE_SIZE);
    q->front = 0;
    q->back = 0;
    q->capacity = INITIAL_QUEUE_SIZE;
    q->size = 0;
}

void cleanup(Queue* q)
{
    printf("Cleaning up queue\n");
    for (int i = 0; i < q->size; i++)
        free(q->arr[i]);
    free(q->arr);

    q->front = 0;
    q->back = 0;
    q->capacity = 0;
    q->size = 0;
}

int isFull(Queue* q)
{
    return q->size == q->capacity;
}

int isEmpty(Queue* q)
{
    return q->size == 0;
}

void resize(Queue* q)
{
    int newCapacity = q->capacity * 2;
    printf("Resizing queue to %d\n", newCapacity);

    char** newArray = (char**)malloc(newCapacity * sizeof(char*));

    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        newArray[i] = q->arr[index];
    }

    free(q->arr);
    q->arr = newArray;
    q->capacity = newCapacity;
    q->front = 0;
    q->back = q->size;
}

void enqueue(Queue* q, char* value)
{
    if (isFull(q))
        resize(q);
    
    q->arr[q->back] = (char*)malloc(MAX_STRING_LEN * sizeof(char));
    strncpy(q->arr[q->back], value, MAX_STRING_LEN);
    printf("Enqueued (%d): %s\n", q->back, value);
    q->back = (q->back + 1) % q->capacity;
    q->size++;
}

char* dequeue(Queue* q)
{
    char* value = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

void printQueue(Queue* q)
{
    for (int i = 0; i < q->size; i++)
    {
        int index = (q->front + i) % q->capacity;
        printf("%d: %s\n", index, q->arr[index]);
    }
    printf("Capacity: %d, Used: %d\n", q->capacity, q->size);
}
