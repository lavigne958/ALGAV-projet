CC=gcc
CFLAGS=-W -Wall
LDFLAGS=

DIR=./
BIN=$(DIR)bin/
OBJ=$(DIR)obj/
OBJS=$(OBJ)util_hybride.o\
	$(OBJ)search_hybride.o\
	$(OBJ)affiche_hybride.o\
	$(OBJ)access_hybride.o\
	$(OBJ)insertion_hybride.o\
	$(OBJ)parser_hybride.o\
	$(OBJ)delete_hybride.o\
	$(OBJ)comptage_hybride.o\
	$(OBJ)rotation_hybride.o\
	$(OBJ)profondeur_hybride.o
INCLUDE=$(DIR)include/
LIB=$(DIR)lib/
SRC=$(DIR)src/

HC=
O=

.PHONY: all test clean
all: $(OBJS) $(OBJ)test_hybride.o
	$(CC) -o $(BIN)test_hybride $(OBJ)test_hybride.o $(OBJS) $(LDFLAGS)
$(OBJ)test_hybride.o: $(SRC)test_hybride.c
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


