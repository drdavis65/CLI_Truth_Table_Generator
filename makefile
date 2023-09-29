# Compiler to use
CC = gcc

# Compiler flags (e.g., -Wall enables warnings)
CFLAGS = -Wall -O2

# Name of the final executable
TARGET = truth_table

# All source files
SOURCES = main.c evaluate.c parser.c

# All object files (intermediate files)
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
