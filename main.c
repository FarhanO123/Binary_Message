#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

#include "binary.c" // Or include "binary.h" if separated
// CG: Character Getter

void translator() {
    // Allocate memory for user input (up to 100 characters)
    char *CG = malloc(sizeof(char) * 100);
    if (CG == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Open the file in append mode
    FILE *fp = fileOpener("binary.txt", "a"); // W overwrites, A appends to the file
    if (fp == NULL) {
        free(CG);
        printf("Failed to open file!\n");
        return;
    }

    // Get user input
    CharGetter(CG, 100);

    // Remove newline character if it exists
    CG[strcspn(CG, "\n")] = 0;

    // Allocate a buffer to store the full binary translation
    char *fullBinary = malloc(sizeof(char) * 1000); // 100 * 9 (8 bits + space) + null terminator
    if (fullBinary == NULL) {
        MessageBoxA(NULL, "Memory allocation failed for fullBinary!", "Error", MB_OK | MB_ICONERROR);
        free(CG);
        fileCloser(fp);
        return;
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
    fprintf(fp, "Input:  %s\nBinary: %s\n\n", CG, fullBinary);

    // Prompt user
    printf("Do you want to print more? (y/n): ");

    char choice = getchar(); // Read single character
    while (getchar() != '\n'); // Clear the rest of the input buffer

    switch (choice) {
        case 'y':
        case 'Y':
            free(CG);
            free(fullBinary);
            fileCloser(fp); // Close the file before restarting
            printf("Restarting Just a NanoSecond...\n");
            translator(); // Re-run translator
            return;
        case 'n':
        case 'N':
            printf("Peace \n");
            clearFile("binary.txt"); // Clear the file
            break;
        default:
            printf("Not a correct option... Exitting \n");
            clearFile("binary.txt"); // Clear the file
            break;
    }

    // Clean up
    free(CG);
    free(fullBinary);
    fileCloser(fp);
}

void viewFile() {
    FILE * fp = fileOpener("binary.txt", "r"); // Open file in read mode
    char line[256]; // Buffer for each line


    printf("\n----- Contents of binary.txt -----\n");
    while(fgets(line, sizeof(line), fp)) {
        printf("%s", line); // Print each line
    }
    printf("\n----------------------------------\n");

    fileCloser(fp); // Close the file
}

int main() {

    int choice;

    do {
        printf("\n--- English to Binary Translator ---\n");
        printf("1. Translate English to Binary\n");
        printf("2. View Binary File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
           while (getchar() != '\n'); // Clear invalid input
           printf("Invalid input. Please enter a number.\n");
           continue; // Skip to next iteration
        }

        while (getchar() != '\n'); // Clear newline after number input

        switch (choice) {
            case 1:
                translator();
                break;
            case 2:
                viewFile();
                break;
            case 3:
                printf("Goodbye!\n");
                clearFile("binary.txt"); // Clear the file
                break;
            default:
                printf("Invalid option. Please select 1, 2, or 3.\n");
        }

    } while (choice != 3); // Loop until user chooses to exit

    return 0; // Exit the program
}