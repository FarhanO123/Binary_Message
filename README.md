# COS 135 Final Project - Binary Character Converter

## Description
This program allows the user to input any ASCII character or number and converts it to its binary representation. The program writes this binary string to a file named `binary.txt`, reads it back, and displays the result.

## Features
- Binary conversion of characters
- File writing and reading
- Pointer-based traversal and string manipulation
- Memory management using `malloc` and `free`
- Uses switch statements to handle user input
- Clean memory (Valgrind verified)
- Proper use of Makefile for compiling

## Something Not Taught in Class
- Full binary string conversion of characters
- File I/O involving both read and write within the same program
- Advanced pointer usage to parse and write strings
- Use of bitwise operators to convert ASCII values to binary

## How to Run

### Requirements:
- GCC compiler
- Make
- Valgrind (for memory testing, optional)

### Compilation:
```bash
make
