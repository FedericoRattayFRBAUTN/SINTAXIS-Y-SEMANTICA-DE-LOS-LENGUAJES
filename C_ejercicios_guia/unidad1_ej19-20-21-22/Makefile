SOURCE = cstrings.c
BIN = cstrings.exe
OBJ = cstrings.o
CC = gcc
CFLAGS = -std=c11
$(BIN): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(BIN)
	run: $(BIN)
	$(BIN)
	$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) -o $(OBJ) $(CFLAGS)