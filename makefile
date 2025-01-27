CC = gcc
CFLAGS = -Wall -Wextra
INCLUDE_DIRS = . libstring_t libtuple_t libiterator_t libnode_t 
INCLUDES = $(foreach dir, $(INCLUDE_DIRS), -I$(dir))
SRC_DIR = .
LIB_DIRS = libstring_t libtuple_t liblist_t libiterator_t libnode_t 
SRC = $(wildcard $(SRC_DIR)/*.c) $(foreach dir, $(LIB_DIRS), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)
TARGET = program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
