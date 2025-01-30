CC = gcc
CFLAGS = -Wall -g -Wextra -Wpedantic -O2 -D_FORTIFY_SOURCE=2 -std=c99 #-Werror 
SRC_DIR = src
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/move_controller.c $(SRC_DIR)/piece_validation.c $(SRC_DIR)/attack_controller.c $(SRC_DIR)/board.c $(SRC_DIR)/helper_functions.c $(SRC_DIR)/bit_controller.c 
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
