#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project3C_hashtable.h"

#define MAX_FILE_LEN 100

/* Convert String Array to Lowercase */
void toLowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

int main()
{
    /* Initializing the Hashtable */
    HashTable ht;
    initialize(&ht);

    /* Prompting User to Enter Filename */
    char filename[MAX_FILE_LEN];
    printf("Enter the filename (or leave blank to quit): ");
    fgets(filename, MAX_FILE_LEN, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the trailing newline character
    if (filename[0] == '\0')
    {
        printf("No file entered, exiting program...\n");
        return 0;
    }

    /* Open File. If File == NULL Prompt User for New Filename */
    FILE *file;
    while ((file = fopen(filename, "r")) == NULL)
    {
        printf("Failed to open file '%s'. Please try again.\n", filename);
        printf("Enter the filename (or leave blank to quit): ");
        fgets(filename, MAX_FILE_LEN, stdin);
        filename[strcspn(filename, "\n")] = '\0';   // Remove the trailing newline character
        if (filename[0] == '\0')
        {
            printf("No file entered, exiting program...\n");
            return 0;
        }
    }

    /* Adding Contents of File to Hash Bucket */
    printf("Tokenizing file '%s' and building hash bucket...", filename);
    char line[MAX_FILE_LEN];
    int lineNum = 1;

    while (fgets(line, MAX_FILE_LEN, file) != NULL)
    {
        char *word = strtok(line, "\n");
        while (word != NULL)
        {
            toLowercase(word);
            insert(&ht, word, lineNum);
            word = strtok(NULL, "\n");
        }
        lineNum++;
    }

    fclose(file);
    printf("done.\n");

    /* Load Factor for Hash Table */
    printf("Load factor: %.2f\n", calculateLoadFactor(&ht));

    /* Repeating Search for Desired Word */
    char searchWord[MAX_FILE_LEN];

    while (1)
    {
        printf("Enter a word to search (or leave blank to quit): ");
        fgets(searchWord, MAX_FILE_LEN, stdin);
        searchWord[strcspn(searchWord, "\n")] = '\0'; // Remove the trailing newline character

        if (searchWord[0] == '\0')
            break;

        toLowercase(searchWord);

        int *results;
        int count;
        get(&ht, searchWord, &results, &count);

        if (count > 0)
        {
            printf("Word '%s' found at line number(s): ", searchWord);
            for (int i = 0; i < count; i++)
                printf("%d ", results[i]);
            printf("\n");
        }
        else
            printf("Word '%s' not found. \n", searchWord);        
        
        free(results);
    }

    freeHashTable(&ht);

    return 0;
}
