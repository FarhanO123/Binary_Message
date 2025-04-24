#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "binary.c" // Or include "binary.h" if separated

int main() {
    // Allocate memory for user input (up to 100 characters)
    char *CG = malloc(sizeof(char) * 100);
    if (CG == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Open the file in write mode
    FILE *fp = fileOpener("binary.txt", "w");
    if (fp == NULL) {
        free(CG);
        return 1;
    }

    // Get user input
    CharGetter(CG, 100);

    // Remove newline character if it exists
    CG[strcspn(CG, "\n")] = 0;

    // Allocate a buffer to store the full binary translation
    // 9 chars per binary (8 bits + space), 100 chars max input = 900+1 bytes
    char *fullBinary = malloc(sizeof(char) * 1000);
    if (fullBinary == NULL) {
        printf("Memory allocation failed for fullBinary!\n");
        free(CG);
        fileCloser(fp);
        return 1;
    }
    fullBinary[0] = '\0'; // Initialize empty string

    char binary[9]; // Buffer for each character's binary representation

    // Loop through input and build full binary string
    for (int i = 0; CG[i] != '\0'; i++) {
        binaryConverter(CG[i], binary);        // Convert char to binary
        strcat(fullBinary, binary);            // Append binary to final string
        strcat(fullBinary, " ");               // Add space after each binary
    }

    // Print result
    printf("%s -> %s\n", CG, fullBinary);

    // Save result to file
    
    fprintf(fp, "%s -> %s\n", CG, fullBinary);

   
    // Clean up
    free(CG);
    free(fullBinary);
    

    // Close the file
    fileCloser(fp);

    return 0;
}
