CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=

DIR=./
BIN=$(DIR)bin/
OBJ=$(DIR)obj/
OBJS=$(OBJ)util.o\
	$(OBJ)search.o\
	$(OBJ)affiche.o\
	$(OBJ)access.o\
	$(OBJ)insertion.o\
	$(OBJ)parser.o\
	$(OBJ)comptage.o
INCLUDE=$(DIR)include/
LIB=$(DIR)lib/
SRC=$(DIR)src/

HC=
O=

.PHONY: all test clean
all: $(OBJS) test.o
	$(CC) -o $(BIN)test test.o $(OBJS) $(LDFLAGS)
test.o: $(SRC)test.c
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDE)
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
