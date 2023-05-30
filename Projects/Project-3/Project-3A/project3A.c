#include <stdio.h>
#include <string.h>
#include "project3A_queue.h"

int main(int argc, char *argv[]) 
{
    /* Check if Sufficent Command Line Arguments are Provided */
    if (argc < 3)
    {
        printf("Please provide a file name and a delimiter\n");
        return 0;
    }
    
    /* Create Constants for Filename & Delimiter */
    const char* filename = argv[1];
    const char* delimiter = argv[2];

    /* Create Queue */
    Queue q;
    initialize(&q);

    /* Open File and Queue Values */
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    printf("\n=> First enqueuing pass\n");
    char line[MAX_STRING_LEN];
    while (fgets(line, sizeof(line), file))
    {
        char* token = strtok(line, delimiter);
        while (token != NULL)
        {
            enqueue(&q, token);
            token = strtok(NULL, delimiter);
        }
    }
    fclose(file);

    /* Dequeue All Values */
    printf("\n=> Dequeuing all elements\n");
    int index = 0;
    while (isEmpty(&q) == 0) {
        char* value = dequeue(&q);
        printf("Dequeued (%d): %s\n", index, value);
        index++;
    }

    /* Open File and Queue Values */
    printf("\n=> Second enqueuing pass\n");
    file = fopen(filename, "r");    
    while (fgets(line, sizeof(line), file))
    {
        char* token = strtok(line, delimiter);
        while (token != NULL)
        {
            enqueue(&q, token);
            token = strtok(NULL, delimiter);
        }
    }
    fclose(file);

    /* Print Queue */
    printf("\n=> Printing queue\n");
    printQueue(&q);

    /* Free Memory of Queue */
    printf("\n=> Calling Queue cleanup\n");
    cleanup(&q);
}
