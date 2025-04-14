#ifndef BINARY.H
#define BINARY.H

#include <stdio.h>



typedef struct {

    char character; // character to be encoded 
    char binary[9]; // there is only 8 bits in a byte and we need a null terminator

} BinaryMapping;


void LoadBinaryMapping(const char *filename);
void ConvertToBinary(const char *input, char *output);
void FreeBinaryMapping();














#endif // BINARY.H