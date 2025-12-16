# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic
LDFLAGS = -lncurses

# File names
TARGET = program
SRC = src/main.c src/snake.c src/map.c src/food.c
BIN_DIR = bin

# Default target (runs when you type 'make')
all: build

# Build the executable (compile and link in one step)
build: $(BIN_DIR)/$(TARGET)

# Create executable directly from source files
$(BIN_DIR)/$(TARGET): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Run the program
run: build
	$(BIN_DIR)/$(TARGET)

# Debug build with gdb support
debug: CFLAGS += -g
debug: build
	gdb $(BIN_DIR)/$(TARGET)

# Clean all compiled files
clean:
	rm -f $(BIN_DIR)/$(TARGET)
	find . -name "*.o" -delete

# Mark these targets as not files
.PHONY: all build run debug clean
