CC=gcc
CFLAGS=-W -Wall
LDFLAGS=

DIR=./
BIN=$(DIR)bin/
OBJ=$(DIR)obj/
OBJS=$(OBJ)** ************************
HYBRIDE=$(DIR)hybride_tree/
PATRICIA=$(DIR)patricia_tree/
OBJ_H=$(HYBRIDE)obj/util_hybride.o\
	$(HYBRIDE)obj/search_hybride.o\
	$(HYBRIDE)obj/affiche_hybride.o\
	$(HYBRIDE)obj/access_hybride.o\
	$(HYBRIDE)obj/insertion_hybride.o\
	$(HYBRIDE)obj/parser_hybride.o\
	$(HYBRIDE)obj/delete_hybride.o\
	$(HYBRIDE)obj/comptage_hybride.o\
	$(HYBRIDE)obj/rotation_hybride.o\
	$(HYBRIDE)obj/profondeur_hybride.o
OBJ_P=$(PATRICIA)obj/access.o\
	$(PATRICIA)obj/add_word.o\
	$(PATRICIA)obj/search.o\
	$(PATRICIA)obj/util.o\
	$(PATRICIA)obj/test.o\
	$(PATRICIA)obj/supression.o\
	$(PATRICIA)obj/affichage.o\
	$(PATRICIA)obj/parser.o\
	$(PATRICIA)obj/comptage.o\
	$(PATRICIA)obj/profondeur.o\
	$(PATRICIA)obj/free_memory.o\
	$(PATRICIA)obj/clone.o\
	$(PATRICIA)obj/fusion.o
INCLUDE=$(DIR)include/
LIB=$(DIR)lib/
SRC=$(DIR)src/

.PHONY: all test clean

all: $(OBJ_H) $(OBJ_P) $(OBJ)test_projet.o
	$(CC) -o $(BIN)test_projet $(OBJ)test_projet.o $(OBJS) $(LDFLAGS)

$(OBJ)test_projet.o: $(SRC)test_projet.c
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDE)

$(OBJ)%.o: $(SRC)%.c
	@if [ -d $(OBJ) ]; then : ; else mkdir $(OBJ); fi
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDE)

$(INCLUDE)%.h:
	@if [ -d $(INCLUDE) ]; then : ; else mkdir $(INCLUDE); fi

$(HYBRIDE)obj/%.o: $(HYBRIDE)src/%.c
	cd $(HYBRIDE) && make

$(PATRICIA)obj/%.o: $(PATRICIA)src/%.c
	cd $(PATRICIA) && make

clean:
	rm -f $(OBJ)* $(BIN)*


