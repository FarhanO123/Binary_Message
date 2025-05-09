# Makefile for translator project (WSL/Linux version)

# Compiler to use (GCC in this case)
CC = gcc

# Compiler flags (enable all warnings)
CFLAGS = -Wall

# Object files to be generated during compilation
OBJS = main.o binary.o

# Target executable file name
TARGET = translator

# Default target: This will be built when 'make' is run without arguments
all: $(TARGET)

# Rule to link the object files and create the executable
$(TARGET): $(OBJS)
	# Use the GCC compiler to link object files into the executable
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.c into main.o object file
main.o: main.c binary.h
	# Compile main.c with the specified flags and generate the object file
	$(CC) $(CFLAGS) -c main.c

# Rule to compile binary.c into binary.o object file
binary.o: binary.c binary.h
	# Compile binary.c with the specified flags and generate the object file
	$(CC) $(CFLAGS) -c binary.c

# Clean up: remove object files and the executable
clean:
	# Remove object files and the target executable to clean the build environment
	rm -f $(OBJS) $(TARGET)
