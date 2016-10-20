CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=
SRC=src/
SRCS=$(SRC)access.c $(SRC)test.c
OBJ=obj/
OBJS=$(OBJ)access.o
BIN=bin

.PHONY: all test clean


test: $(OBJS) $(OBJ)test.o
	$(CC) -o test-patricia $^
	
$(OBJ)%.o: $(SRC)%.c
	$(CC) -o $@ -c $^ $(LDFLAGS)

clean:
	rm -f $(OBJ)/* $(BIN)/*

