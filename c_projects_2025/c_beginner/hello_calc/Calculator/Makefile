# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Source files and targets
SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=)

# Default target
all: $(TARGETS)

# Rule to build each target
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up build files
clean:
	rm -f $(TARGETS)

# Phony targets
.PHONY: all clean
