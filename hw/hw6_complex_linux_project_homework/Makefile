# Compiler and flags
CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

# Directories
ROOT_DIR = $(PWD)
CALC_DIR = $(ROOT_DIR)/calculator
TEXT_FORMATTER_DIR = $(ROOT_DIR)/text_formatter
STATIC_LIB_DIR = $(CALC_DIR)/static_lib
SHARED_LIB_DIR = $(TEXT_FORMATTER_DIR)/shared_library
OBJ_DIR = $(ROOT_DIR)/obj

# Libraries
STATIC_LIB = $(STATIC_LIB_DIR)/libcalculator.a
SHARED_LIB = $(SHARED_LIB_DIR)/libconvert.so

# Executables
EXECUTABLES = $(TEXT_FORMATTER_DIR)/upper $(TEXT_FORMATTER_DIR)/low $(CALC_DIR)/main

# Source files for Task 1 (Calculator)
SRC_CALC = $(CALC_DIR)/static_lib/calculator.c $(CALC_DIR)/main.c

# Source files for Task 2 (Text Formatter)
SRC_UPPER = $(TEXT_FORMATTER_DIR)/upper.c
SRC_LOW = $(TEXT_FORMATTER_DIR)/low.c
SRC_CONVERT = $(TEXT_FORMATTER_DIR)/shared_library/convert.c

# Object files for Task 1 (Calculator)
OBJ_CALC = $(OBJ_DIR)/calculator.o $(OBJ_DIR)/main.o

# Object files for Task 2 (Text Formatter)
OBJ_UPPER = $(OBJ_DIR)/upper.o
OBJ_LOW = $(OBJ_DIR)/low.o
OBJ_CONVERT = $(OBJ_DIR)/convert.o

# Targets

# Default target
all: $(STATIC_LIB) $(SHARED_LIB) $(EXECUTABLES)

# Task 1: Static Library (libcalculator.a)
$(STATIC_LIB): $(OBJ_DIR)/calculator.o
	ar rcs $(STATIC_LIB) $(OBJ_DIR)/calculator.o

# Task 2: Shared Library (libconvert.so)
$(SHARED_LIB): $(OBJ_DIR)/convert.o
	$(CC) $(LDFLAGS) -o $(SHARED_LIB) $(OBJ_DIR)/convert.o

# Task 1: Compile the main executable (Calculator program)
$(CALC_DIR)/main: $(OBJ_CALC) $(STATIC_LIB)
	$(CC) -o $(CALC_DIR)/main $(OBJ_CALC) -L$(STATIC_LIB_DIR) -lcalculator

# Task 2: Compile the upper executable (Text Formatter)
$(TEXT_FORMATTER_DIR)/upper: $(OBJ_UPPER) $(SHARED_LIB)
	$(CC) -o $(TEXT_FORMATTER_DIR)/upper $(OBJ_UPPER) -L$(SHARED_LIB_DIR) -lconvert -undefined dynamic_lookup

# Task 2: Compile the low executable (Text Formatter)
$(TEXT_FORMATTER_DIR)/low: $(OBJ_LOW) $(SHARED_LIB)
	$(CC) -o $(TEXT_FORMATTER_DIR)/low $(OBJ_LOW) -L$(SHARED_LIB_DIR) -lconvert -undefined dynamic_lookup

# Compile source files for Task 1 (Calculator) to object files
$(OBJ_DIR)/calculator.o: $(CALC_DIR)/static_lib/calculator.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Correct rule for main.c (it is located in the calculator directory, not static_lib)
$(OBJ_DIR)/main.o: $(CALC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile source files for Task 2 (Text Formatter) to object files
$(OBJ_DIR)/%.o: $(TEXT_FORMATTER_DIR)/shared_library/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEXT_FORMATTER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the compiled files, keeping only .c and .h files
clean:
	rm -rf $(OBJ_DIR) $(STATIC_LIB_DIR)/libcalculator.a $(SHARED_LIB_DIR)/libconvert.so $(EXECUTABLES)

.PHONY: all clean
