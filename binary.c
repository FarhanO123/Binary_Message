#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"

// ANSI color codes for red and reset (used for colored console output)
#define RED "\033[0;31m"
#define RESET "\033[0m"

// Function to convert a single character to its binary representation
void binaryConverter(char ch, char* binary) {
    // Loop through each bit (from 7 to 0) and extract each bit
    for (int i = 7; i >= 0; i--) {
        // Use bit-shifting and bitwise AND to get each bit (1 or 0)
        // 'binary[7-i]' places each bit in the correct order (left to right)
        binary[7-i] = ((ch >> i) & 1) ? '1' : '0';
    }
    binary[8] = '\0'; // Null-terminate the binary string
}

// Function to open a file with a given filename and mode (e.g., "a" for append, "r" for read)
FILE* fileOpener(const char* filename, const char* mode) {
    return fopen(filename, mode);  // Return a pointer to the opened file
}

// Function to close the file and print a message
void fileCloser(FILE* fp) {
    if (fp != NULL) {  // Check if the file pointer is not NULL
        fclose(fp);  // Close the file
        printf(RED "Closing file\n" RESET);  // Print a message indicating file closure
    }
}

// Function to clear the contents of a specified file
void clearFileManually(const char* filename) {
    // Open the file in write mode to clear its contents
    FILE* fp = fileOpener(filename, "w");
    if (fp != NULL) {
        // Print a message indicating the file has been cleared
        printf(RED "binary.txt has been cleared manually.\n" RESET);
        fileCloser(fp);  // Close the file after clearing
    }
}

// Function to get a character, string, or number from the user
void CharGetter(char* buffer, int size) {
    printf(RED "Enter any character, string or number: " RESET);
    fgets(buffer, size, stdin);  // Get user input and store it in 'buffer'
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove the newline character from the input
    printf(RED "You entered: %s\n" RESET, buffer);  // Print the user's input
}

// Function to view the contents of the binary file
void viewFile() {
    // Open the file "binary.txt" in read mode
    FILE *fp = fileOpener("binary.txt", "r");
    if (fp == NULL) {  // Check if the file could not be opened
        printf(RED "File does not exist or cannot be opened.\n" RESET);
        return;
    }

    // Print a header for the file contents
    printf(RED "\n----- Contents of binary.txt -----\n" RESET);
    char line[256];
    // Read each line from the file and print it to the console
    while (fgets(line, sizeof(line), fp)) {
        printf(RED "%s" RESET, line);  // Print each line with red color
    }
    // Print a footer after displaying the file contents
    printf(RED "\n----------------------------------\n" RESET);

    fileCloser(fp);  // Close the file after reading
}
