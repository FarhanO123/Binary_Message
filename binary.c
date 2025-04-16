#include <stdio.h>      // For printf, fgets, FILE operations
#include <stdlib.h>     // For malloc, free, exit
#include <string.h>     // For string handling

#include "binary.h"     // Custom header file, make sure this exists with function declarations

// Function to get a character or string from the user
void CharGetter(char *CG, int size) {
    printf("Enter any character or number: ");
    fgets(CG, size, stdin); // Read input from user

    // Remove newline if present
    size_t len = strlen(CG);
    if (len > 0 && CG[len - 1] == '\n') {
        CG[len - 1] = '\0';
    }

    printf("You entered: %s\n", CG);
}

// Function to open a file and return the file pointer
FILE *fileOpener(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode); // Open the file with given mode (e.g., "w+")

    if (fp == NULL) {
        printf("Cannot open file: %s\n", filename);
        exit(1); // Exit if file can't be opened
    }

    return fp;
}

// Function to safely close a file
void fileCloser(FILE *fp) {
    if (fp != NULL) {
        fclose(fp); // Close the file
        printf("Closing file\n");
    }
}

// Function to convert a character to an 8-bit binary string
void binaryConverter(char character, char *binary) {
    // Loop through 8 bits
    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = ((character >> i) & 1) ? '1' : '0';
        // Shifts character right by i, masks with 1 to get the bit
    }
    binary[8] = '\0'; // Null-terminate the string
}
