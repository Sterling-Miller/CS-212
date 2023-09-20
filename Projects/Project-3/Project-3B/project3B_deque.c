#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3B_deque.h"

Node *newNode(void *data, size_t dataSize)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        fprintf(stderr, "Error allocating memory for node.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = malloc(dataSize);

    if (newNode->data == NULL)
    {
        fprintf(stderr, "Error allocating memory for node data.\n");
        exit(EXIT_FAILURE);
    }

    memcpy(newNode->data, data, dataSize);
    
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Deque *createDeque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));

    if (deque == NULL)
    {
        fprintf(stderr, "Error allocating memory for deque.\n");
        exit(EXIT_FAILURE);
    }

    deque->front = NULL;
    deque->back = NULL;
    deque->count = 0;

    return deque;
}

void insertFront(Deque *deque, void *data, size_t dataSize)
{
    Node *newnode = newNode(data, dataSize);

    if (deque->front == NULL)
    {
        deque->front = newnode;
        deque->back = newnode;
    }

    else
    {
        newnode->next = deque->front;
        deque->front->prev = newnode;
        deque->front = newnode;
    }

    deque->count++;
}

void insertBack(Deque *deque, void *data, size_t dataSize)
{
    Node *newnode = newNode(data, dataSize);

    if (deque->count == 0)
    {
        deque->front = newnode;
        deque->back = newnode;
    }

    else
    {
        newnode->prev = deque->back;
        deque->back->next = newnode;
        deque->back = newnode;
    }

    deque->count++;
}

void removeFront(Deque *deque, void *data, size_t dataSize)
{
    Node *frontNode = deque->front;

    if (deque->count == 1)
    {
        deque->front = NULL;
        deque->back = NULL;
    }
    else
    {
        deque->front = frontNode->next;
        deque->front->prev = NULL;
    }

    memcpy(data, frontNode->data, dataSize);

    free(frontNode->data);
    free(frontNode);

    deque->count--;
}

void removeBack(Deque *deque, void *data, size_t dataSize)
{
    Node *backNode = deque->back;

    if (deque->count == 1)
    {
        deque->front = NULL;
        deque->back = NULL;
    }
    else
    {
        deque->back = backNode->prev;
        deque->back->next = NULL;
    }

    memcpy(data, backNode->data, dataSize);

    free(backNode->data);
    free(backNode);

    deque->count--;
}

void freeDeque(Deque *deque)
{
    Node *current = deque->front;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(deque);
}

void printDeque(Deque *deque, printData print)
{
    Node *current = deque->front;

    while (current != NULL)
    {
        print(current->data);
        current = current->next;
        }
}
