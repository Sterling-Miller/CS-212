#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Declare variables
    FILE *f_in, *f_out;
    int buff_size;
    char *buffer;

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input file in read mode
    f_in = fopen(argv[1], "r");

    // Check if input file exists
    if (f_in == NULL) {
        printf("Error opening input file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Set file position to end of file to get file size
    fseek(f_in, 0, SEEK_END);

    // Get file size and set buffer size to file size
    buff_size = ftell(f_in);

    // Set file position to beginning of file to prepare for reading
    fseek(f_in, 0, SEEK_SET);

    // Allocate memory for buffer
    // Option #1 using sizeof and explicit cast
    buffer = (char *) malloc(buff_size * sizeof(char));

    // Option #2 using buffer size and implicit cast
    // buffer = malloc(buff_size);

    // Check if memory allocation was successful
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        exit(EXIT_FAILURE);
    }

    // Read file into buffer
    fread(buffer, sizeof(char), buff_size, f_in);

// Print copying status message
printf("Copying %d bytes from %s to %s\n", buff_size, argv[1], argv[2]);

// Open output file in write mode
f_out = fopen(argv[2], "w");

// Check if output file exists
if (f_out == NULL) {
    printf("Error opening output file %s\n", argv[2]);
    exit(EXIT_FAILURE);
}

// Write buffer to output file
fwrite(buffer, sizeof(char), buff_size, f_out);

// Free buffer memory
free(buffer);

// Close files
fclose(f_in);
fclose(f_out);

return EXIT_SUCCESS;
}
