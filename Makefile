CC = gcc
OBJ_FILE = ./src/main.c
OBJ_NAME = flightSimulator

COMP_FLAGS = -Wall -pedantic -Wextra
LINK_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11


all:
	$(CC) $(OBJ_FILE) $(COMP_FLAGS) $(LINK_FLAGS) -o $(OBJ_NAME)

clean:
	rm -rf ./flightSimulator