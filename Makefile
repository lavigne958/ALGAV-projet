CC=gcc
CFLAGS=-W -Wall
LDFLAGS=

DIR=./
BIN=$(DIR)bin/
OBJ=$(DIR)obj/
OBJS=$(OBJ)transfert.o\
	$(OBJ)parser.o\
	$(OBJ)util_project.o
HYBRIDE=$(DIR)hybride_tree/
PATRICIA=$(DIR)patricia_tree/
OBJ_H=$(HYBRIDE)obj/search_hybride.o\
	$(HYBRIDE)obj/affiche_hybride.o\
	$(HYBRIDE)obj/access_hybride.o\
	$(HYBRIDE)obj/insertion_hybride.o\
	$(HYBRIDE)obj/delete_hybride.o\
	$(HYBRIDE)obj/comptage_hybride.o\
	$(HYBRIDE)obj/rotation_hybride.o\
	$(HYBRIDE)obj/profondeur_hybride.o
OBJ_P=$(PATRICIA)obj/access.o\
	$(PATRICIA)obj/add_word.o\
	$(PATRICIA)obj/search.o\
	$(PATRICIA)obj/supression.o\
	$(PATRICIA)obj/affichage.o\
	$(PATRICIA)obj/comptage.o\
	$(PATRICIA)obj/profondeur.o\
	$(PATRICIA)obj/free_memory.o\
	$(PATRICIA)obj/clone.o\
	$(PATRICIA)obj/fusion.o
INCLUDE=$(DIR)include/
INC_P=$(HYBRIDE)include/
INC_H=$(PATRICIA)include/
LIB=$(DIR)lib/
SRC=$(DIR)src/

.PHONY: all test clean clean-patricia clean-hybride clean-project

all: $(OBJ_H) $(OBJ_P) $(OBJS) $(OBJ)test_project.o
	$(CC) -o $(BIN)test_project $(OBJ)test_project.o $(OBJS) $(OBJ_H) $(OBJ_P) $(LDFLAGS)

$(OBJ)test_project.o: $(SRC)test_project.c
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDE) -I$(INC_P) -I$(INC_H)

$(OBJ)%.o: $(SRC)%.c
	@if [ -d $(OBJ) ]; then : ; else mkdir $(OBJ); fi
	$(CC) -o $@ -c $^ $(CFLAGS) -I$(INCLUDE) -I$(INC_P) -I$(INC_H)

$(INCLUDE)%.h:
	@if [ -d $(INCLUDE) ]; then : ; else mkdir $(INCLUDE); fi

$(HYBRIDE)obj/%.o: $(HYBRIDE)src/%.c
	cd $(HYBRIDE) && make

$(PATRICIA)obj/%.o: $(PATRICIA)src/%.c
	cd $(PATRICIA) && make

clean-patricia:
	rm -f $(OBJ_P)* $(PATRICIA)bin/*

clean-hybride:
	rm -ff $(OBJ_H)* $(HYBRIDE)bin/*

clean-project:
	rm -f $(OBJ)* $(BIN)*

clean:
	make clean-hybride && make clean-patricia && make clean-project
