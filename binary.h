#ifndef BINARY_H  // Header guard to prevent multiple inclusions of this file
#define BINARY_H

// Function to convert a single character to its binary representation
void binaryConverter(char ch, char* binary);

// Function to get input from the user (character, string, or number)
void CharGetter(char* buffer, int size);

// Function to open a file with the given filename and mode
FILE* fileOpener(const char* filename, const char* mode);

// Function to close an opened file and print a message 
void fileCloser(FILE* fp);

// Function to manually clear the contents of a specified file. 
void clearFileManually(const char* filename);

// Function to view the contents of the binary file (binary.txt)
void viewFile();

// Function to manage the main translation process & This includes getting user input, converting it to binary, writing to the file, and displaying results
void translator();

#endif
