#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void binaryConverter(char ch, char* binary) {
    for (int i = 7; i >= 0; i--) {
        binary[7-i] = ((ch >> i) & 1) ? '1' : '0';
    }
    binary[8] = '\0';
}

FILE* fileOpener(const char* filename, const char* mode) {
    return fopen(filename, mode);
}

void fileCloser(FILE* fp) {
    if (fp != NULL) {
        fclose(fp);
        printf("Closing file\n");
    }
}

// Only called when user chooses "Clear File"
void clearFileManually(const char* filename) {
    FILE* fp = fileOpener(filename, "w");
    if (fp != NULL) {
        printf("binary.txt has been cleared manually.\n");
        fileCloser(fp);
    }
}

void CharGetter(char* buffer, int size) {
    printf("Enter any character or number: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Strip newline
    printf("You entered: %s\n", buffer);
}

void translator() {
    char *CG = malloc(sizeof(char) * 100);
    if (CG == NULL) return;

    CharGetter(CG, 100);

    FILE *fp = fileOpener("binary.txt", "a"); // Append mode
    if (fp == NULL) {
        free(CG);
        printf("Failed to open file for writing.\n");
        return;
    }

    char *fullBinary = malloc(sizeof(char) * 1000);
    if (fullBinary == NULL) {
        free(CG);
        fileCloser(fp);
        return;
    }
    fullBinary[0] = '\0';

    char binary[9];
    for (int i = 0; CG[i] != '\0'; i++) {
        binaryConverter(CG[i], binary);
        strcat(fullBinary, binary);
        strcat(fullBinary, " ");
    }

    printf("%s -> %s\n", CG, fullBinary);
    fprintf(fp, "Input:  %s\nBinary: %s\n\n", CG, fullBinary);
    fflush(fp);

    char choice;
    printf("Do you want to print more? (y/n): ");
    scanf(" %c", &choice);
    while (getchar() != '\n'); // flush stdin

    free(CG);
    free(fullBinary);
    fileCloser(fp);

    if (choice == 'y' || choice == 'Y') {
        printf("Restarting...\n");
        translator();
    } else {
        printf("Peace\n");
    }
}

void viewFile() {
    FILE *fp = fileOpener("binary.txt", "r");
    if (fp == NULL) {
        printf("File does not exist or cannot be opened.\n");
        return;
    }

    printf("\n----- Contents of binary.txt -----\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("\n----------------------------------\n");

    fileCloser(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- English to Binary Translator ---\n");
        printf("1. Translate English to Binary\n");
        printf("2. View Binary File\n");
        printf("3. Clear File Contents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        while (getchar() != '\n'); // flush newline

        switch (choice) {
            case 1:
                translator();
                break;
            case 2:
                viewFile();
                break;
            case 3:
                clearFileManually("binary.txt");
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
