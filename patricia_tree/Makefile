CC=gcc
CFLAGS=-W -Wall 

DIR=./
BIN=$(DIR)bin/
OBJ=$(DIR)obj/
OBJS=$(OBJ)access.o\
	$(OBJ)add_word.o\
	$(OBJ)search.o\
	$(OBJ)util.o\
	$(OBJ)test.o\
	$(OBJ)supression.o\
	$(OBJ)affichage.o\
	$(OBJ)parser.o\
	$(OBJ)comptage.o\
	$(OBJ)profondeur.o\
	$(OBJ)free.o\
	$(OBJ)clone.o\
	$(OBJ)fusion.o
INCLUDE=$(DIR)include/
LIB=$(DIR)lib/
SRC=$(DIR)src/


.PHONY: all test clean
all: $(OBJS)
	$(CC) -o $(BIN)test $(OBJS) $(LDFLAGS)
$(OBJ)%.o: $(SRC)%.c
	@if [ -d $(OBJ) ]; then : ; else mkdir $(OBJ); fi
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDE)

$(INCLUDE)%.h:
	@if [ -d $(INCLUDE) ]; then : ; else mkdir $(INCLUDE); fi

clean:
	rm -f $(OBJ)* $(BIN)*
