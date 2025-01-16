CC = gcc
CFLAGS = -Wall -g -Wextra -Wpedantic -Werror -O2 -D_FORTIFY_SOURCE=2 -std=c99
SRC_DIR = src
SRC = $(SRC_DIR)/Main.c $(SRC_DIR)/Board.c $(SRC_DIR)/ValidCheck.c $(SRC_DIR)/PieceMovement.c $(SRC_DIR)/PieceAttack.c
OBJ = $(SRC:.c=.o)
EXEC = program

all: $(EXEC) #default run without being provided a target
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: clean run
