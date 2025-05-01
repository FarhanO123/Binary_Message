#ifndef BINARY_H
#define BINARY_H

#include <stdio.h>

// Struct to hold a character and its binary representation
typedef struct {
    char character;      // Character to be encoded
    char binary[9];      // 8 bits + 1 null terminator
} BinaryMapping;

// Function declarations
void CharGetter(char *CG, int size);                    // Function to get input from the user
FILE *fileOpener(const char *filename, const char *mode); // Function to open a file and return FILE*
void fileCloser(FILE *fp);                              // Function to close a file
void binaryConverter(char character, char *binary);     // Function to convert a character to binary
void clearFile(const char* clearFile); // Function to clear the contents of a file

#endif // BINARY_H
