# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = -lncurses

# Use the shell command 'find' to get all .c files in current and subdirectories
SRCS = $(shell find . -name "*.c")

# Convert the list of .c files to .o files (main.c becomes main.o, etc.)
OBJS = $(SRCS:.c=.o)

# The name of your final executable
TARGET = faalz

# Default target
all: $(TARGET)

# Link all object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Pattern rule to compile any .c file into a .o file
# % matches any string (the filename)
# $< is the source file (.c)
# $@ is the target file (.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove all object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
