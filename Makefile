CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=

DIR=./
BIN=$(DIR)bin/
OBJ=$(DIR)obj/
OBJS=$(OBJ)access.o\
	$(OBJ)search.o\
	$(OBJ)util.o\
	$(OBJ)test.o
INCLUDE=$(DIR)include/
LIB=$(DIR)lib/
SRC=$(DIR)src/

HC=
O=

.PHONY: all test clean
all: $(OBJS)
	$(CC) -o $(BIN)test $(OBJS) $(LDFLAGS)
$(OBJ)%.o: $(SRC)%.c
	@if [ -d $(OBJ) ]; then : ; else mkdir $(OBJ); fi
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDE)
#
#$(OBJ)search.o: $(SRC)search.c access.h structure.h
#	$(CC) -o $@ -c $< $(CFLAGS)

$(INCLUDE)%.h:
	@if [ -d $(INCLUDE) ]; then : ; else mkdir $(INCLUDE); fi

clean:
	rm -f $(OBJ)* $(BIN)*
