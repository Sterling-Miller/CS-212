#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3B_deque.h"

/* Functions to be passed to printDeque() */
void printString(void *data)
{
    char *str = (char *)data;
    printf("%s ", str);
}
void printLong(void *data)
{
    long *num = (long *)data;
    printf("%ld ", *num);
}

int main()
{
    /* Create String and Long Deque */
    Deque *stringDeque = createDeque();
    Deque *longDeque = createDeque();

    /* Placing Each Input into Either String or Long Deque */
    char input[100];
    do
    {
        printf("Please enter an integer or a string (empty to exit): ");
        if (scanf("%99s", input) != 1)
            break;

        if (strlen(input) > 0)
        {
            char *endptr;
            long number = strtol(input, &endptr, 10);

            /* Add Input to Long Deque */
            if (*endptr == '\0')
            {
                printf("\nYou entered the number: %ld\n", number);
                if (longDeque->count % 2 == 0)
                    insertFront(longDeque, &number, sizeof(long));
                else
                    insertBack(longDeque, &number, sizeof(long));
            }

            /* Add Input to String Deque */
            else
            {
                printf("\nYou entered the string: \"%s\"\n", input);
                if (stringDeque->count % 2 == 0)
                    insertFront(stringDeque, input, strlen(input) + 1);
                else
                    insertBack(stringDeque, input, strlen(input) + 1);
            }
        }
    } while (strlen(input) > 0);

    /* Printing String Deque */
    printf("\n\nPrinting string deque\n");
    printDeque(stringDeque, printString);

    /* Printing Long Deque */
    printf("\n\nPrinting long deque\n");
    printDeque(longDeque, printLong);

    /* Removing From String Deque Using Count */
    printf("\n\nRemoving string deque data using count");
    while (stringDeque->count > 0) 
    {
        char input[100];
        if (stringDeque->count % 2 == 0)
            removeBack(stringDeque, input, 100);
        else
            removeFront(stringDeque, input, 100);
        printf("\nRemoving %s", input);
    }

    /* Removing From Long Deque Using Count */
    printf("\n\nRemoving long deque data using count");
    while (longDeque->count > 0) 
    {
        long num;
        if (longDeque->count % 2 == 0)
            removeBack(longDeque, &num, sizeof(long));
        else
            removeFront(longDeque, &num, sizeof(long));
        printf("\nRemoving %ld", num);
    }

    printf("\n");

    /* Freeing Leftover */
    freeDeque(stringDeque);
    freeDeque(longDeque);

    return 0;
}