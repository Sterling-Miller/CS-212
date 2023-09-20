#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3C_hashtable.h"

unsigned int hash(const char *key)
{
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = hash * 31 + key[i];
    }
    return hash % BUCKET_SIZE;
}

void initialize(HashTable *ht)
{
    for (int i = 0; i < BUCKET_SIZE; i++)
        ht->bucket[i] = NULL;
    
    ht->count = 0;
}

Node *createNode(const char *key, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error allocating memory for node.\n");
        exit(EXIT_FAILURE);
    }

    newNode->key = malloc((strlen(key) + 1) * sizeof(char));
    if (newNode->key == NULL)
    {
        fprintf(stderr, "Error allocating memory for node.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->key, key);
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}

void insert(HashTable *ht, const char *key, int value)
{
    unsigned int index = hash(key);
    Node *newNode = createNode(key, value);

    if (ht->bucket[index] == NULL) 
        ht->bucket[index] = newNode;

    else 
    {
        Node *current = ht->bucket[index];
        while (current->next != NULL)
            current = current->next;

        current->next = newNode;
    }
    ht->count++;
}

void get(HashTable *ht, const char *key, int **results, int *count)
{
    unsigned int index = hash(key);
    Node *current = ht->bucket[index];

    int numOccurrences = 0;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            numOccurrences++;

        current = current->next;
    }

    if (numOccurrences == 0) {
        *results = NULL;
        *count = 0;
        return;
    }

    int *lineNumbers = (int *)malloc(numOccurrences * sizeof(int));
    if (lineNumbers == NULL)
    {
        printf("Failed to allocate memory for results array.\n");
        *results = NULL;
        *count = 0;
        return;
    }

    current = ht->bucket[index];
    int currentIndex = 0;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            lineNumbers[currentIndex] = current->value;
            currentIndex++;
        }
        current = current->next;
    }

    *results = lineNumbers;
    *count = numOccurrences;
}

void freeHashTable(HashTable *ht)
{
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        Node *current = ht->bucket[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
        ht->bucket[i] = NULL;
    }
    ht->count = 0;
}

float calculateLoadFactor(HashTable *ht)
{
    if (ht->count == 0)
        return 0.0;
    
    float loadFactor = (float)ht->count / (float)BUCKET_SIZE;
    return loadFactor;
}
