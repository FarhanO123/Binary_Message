
# COS 135 Final Project - Binary Character Converter

FARHAN OMANE COS 135 FINAL PROJECT

## Description
This program allows the user to input any ASCII character or number and converts it to its binary representation. The result is written to a file (`binary.txt`) and then read back and displayed. The terminal output is shown in red to improve visibility — this use of ANSI escape codes for color was not explicitly taught in class.

## How to Run

### Requirements (for WSL or Linux):
Install these with:

```bash
sudo apt update
sudo apt install build-essential
```

- `gcc` – to compile the code
- `make` – to build the project
- `valgrind` – *(optional)* to check for memory leaks — note: **Valgrind does not work reliably on WSL**

### Compilation:
From inside the project folder:

```bash
make
```

This will compile the program into an executable named `translator`.

### Running the Program:
Once compiled, run the program with:

```bash
./translator
```

The program will prompt you to enter an ASCII character. It will:
1. Convert the character to binary
2. Write the result to `binary.txt`
3. Read it back
4. Display it in red in the terminal

### Optional: Check for Memory Leaks (only works on real Linux systems):
```bash
valgrind ./translator
```

## Features
- Binary conversion of ASCII characters
- File writing and reading
- Pointer-based string traversal
- Dynamic memory management with `malloc` and `free`
- User interaction via `switch` statements
- Output styled in red text using ANSI color codes

## Something Not Explicitly Taught in Class
The terminal output color is set to **red** using ANSI escape codes (` [1;31m`), which was not covered in class but adds a visual flair to the output.

