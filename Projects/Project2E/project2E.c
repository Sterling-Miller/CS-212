#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char ch) {
    return (ch == ' ' || ch == ',' || ch == '.' || ch == '\n' || ch == '\0');
}

int main(int argc, char *argv[]) {
    
    // Declare Variables:
    FILE *file;
    int buff_size;
    char *buffer;

    // Check Command Line Arguments:
    if (argc < 3) {
        printf("Usage: %s <file> <word1> <word2> ...\n", argv[0]);
        return 1;
    }

    // Open File:
    file = fopen(argv[1], "r");

    // Check if File Exists:
    if (file == NULL) {
        printf("%s is not a valid file\n", argv[1]);
        return 1;
    }

    // Get File Size:
    fseek(file, 0, SEEK_END);
    buff_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Allocate Memory for Buffer:
    buffer = (char *) malloc((buff_size + 1) * sizeof(char));
    
    // Check if Memory Allocation was Successful
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        return 1;
    }
    
    // Read file into buffer
    fread(buffer, sizeof(char), buff_size, file);

    // Loop Through Search Terms:
    for (int i = 2; i < argc; i++) {

        // Search for the term in the buffer
        char* term = argv[i];
        int term_len = strlen(term);
        char* ptr = buffer;
        int count = 0;

        while (*ptr != '\0') {
            if (strncmp(ptr, term, term_len) == 0) {
                if ((ptr == buffer || compare(*(ptr-1))) && compare(*(ptr+term_len))) {
                    count++;
                }
            }
            ptr++;
        }
        printf("The word \"%s\" occurs %d times.\n", term, count);
    }

    // Close File and Free Memory:
    free(buffer);
    fclose(file);
    return 0;
}