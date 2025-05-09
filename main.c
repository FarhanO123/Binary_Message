#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"

// ANSI color codes for red and reset
#define RED "\033[0;31m"
#define RESET "\033[0m"

// Function to convert a character to its binary representation
void translator() {
    // Allocate memory to store user input (character string)
    char *CG = malloc(sizeof(char) * 100);
    if (CG == NULL) return;  // Check if memory allocation failed

    // Prompt the user to enter a character, string, or number
    CharGetter(CG, 100);

    // Open the file "binary.txt" for appending (adding data without overwriting)
    FILE *fp = fileOpener("binary.txt", "a");
    if (fp == NULL) {
        free(CG);  // Free allocated memory if file couldn't be opened
        printf(RED "Failed to open file for writing.\n" RESET);
        return;
    }

    // Allocate memory to store the full binary string
    char *fullBinary = malloc(sizeof(char) * 1000);
    if (fullBinary == NULL) {
        free(CG);  // Free memory if allocation for binary string fails
        fileCloser(fp);  // Close file if memory allocation fails
        return;
    }
    fullBinary[0] = '\0';  // Initialize the binary string as empty

    // Temporary storage for individual character binary representation
    char binary[9];
    // Iterate over each character in the input string
    for (int i = 0; CG[i] != '\0'; i++) {
        binaryConverter(CG[i], binary);  // Convert each character to binary
        strcat(fullBinary, binary);  // Append the binary string
        strcat(fullBinary, " ");  // Add a space between binary values
    }

    // Display the original input and its binary conversion
    printf(RED "%s -> %s\n" RESET, CG, fullBinary);

    // Write the input and binary conversion to the file
    fprintf(fp, "Input:  %s\nBinary: %s\n\n", CG, fullBinary);
    fflush(fp);  // Flush data to file immediately

    // Prompt user if they want to enter another string
    char choice;
    printf(RED "Do you want to print more? (y/n): " RESET);
    scanf(" %c", &choice);  // Read the user's decision
    while (getchar() != '\n');  // Clear the input buffer

    // Free the allocated memory for input and binary strings
    free(CG);
    free(fullBinary);
    fileCloser(fp);  // Close the file

    // If user chooses to continue, restart the translator function
    if (choice == 'y' || choice == 'Y') {
        printf(RED "Restarting...\n" RESET);
        translator();
    } else {
        // If user chooses to stop, print a goodbye message
        printf(RED "Peace\n" RESET);
    }
}

// Main function to handle user input and program flow
int main() {
    int choice;

    // Loop to display the main menu until user chooses to exit
    do {
        // Display menu with color-coded options
        printf(RED "\n--- English to Binary Translator ---\n" RESET);
        printf(RED "1. Translate English to Binary\n" RESET);
        printf(RED "2. View Binary File\n" RESET);
        printf(RED "3. Clear File Contents\n" RESET);
        printf(RED "4. Exit\n" RESET);
        printf(RED "Enter your choice: " RESET);

        // Read the user's choice, check for valid input
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  // Clear the input buffer
            printf(RED "Invalid input. Please enter a number.\n" RESET);
            continue;  // Restart the loop if input is invalid
        }

        while (getchar() != '\n');  // Clear any remaining characters in the buffer

        // Handle different choices based on user input
        switch (choice) {
            case 1:
                translator();  // Call the translator function to convert input to binary
                break;
            case 2:
                viewFile();  // View the contents of the binary file
                break;
            case 3:
                clearFileManually("binary.txt");  // Clear the contents of the file
                break;
            case 4:
                printf("Goodbye!\n");  // Exit message
                break;
            default:
                printf("Invalid choice. Try again.\n");  // Handle invalid menu choices
        }

    } while (choice != 4);  // Continue the loop until user chooses to exit (option 4)

    return 0;  // Return 0 to indicate successful program execution
}
