CC = gcc
CFLAGS = -Wall -Wextra -I.
SRC_DIR = .
LIB_DIR = libstring_t libtuple_t liblist_t libiterator_t
SRC = $(wildcard $(SRC_DIR)/*.c) $(foreach dir, $(LIB_DIR), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)
TARGET = program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
