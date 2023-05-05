##
## EPITECH PROJECT, 2023
## Makefile for lem-in
## File description:
## file for lem-in compilation
##

CFLAGS   += -O3 -fno-builtin -W -Wall -Wextra -Werror
CPPFLAGS += -Iinclude

SRC    = $(shell find src -name "*.c")
OBJ    = $(SRC:.c=.o)
TARGET = lem_in

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
