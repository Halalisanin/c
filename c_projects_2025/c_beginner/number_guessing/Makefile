# Compiler
CC = gcc

# Compiler flags
CFLAGS = `pkg-config --cflags gtk+-3.0` -Wall -Wextra -pedantic -std=c11

# Linker flags
LDFLAGS = `pkg-config --libs gtk+-3.0`

# Source file
SOURCE = number_guessing.c

# Target executable
TARGET = number_guessing

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(LDFLAGS)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
