CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=
EXEC=
SRC=src/
OBJ=obj/
OBJS=$(OBJ)access.o
BIN=bin/

.PHONY: all test clean


test: $(OBJS) $(OBJ)test.o
	$(CC) -o $(BIN)test-patricia $^

$(OBJ)test.o: $(SRC)test.c
	$(CC) -o $@ -c $^ $(CFLAGS)
$(OBJ)%.o: $(SRC)%.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -f $(OBJ)/* $(BIN)/*

