#ifndef _CALCUL_TEMPS_H
#define _CALCUL_TEMPS_H

#include "struct.h"
#include "struct_hybride.h"

int get_time();
int calcul_insertion_hybride(racine**);
int calcul_insertion_patricia(node**);
int calcul_ajout_mot(node*, char*);
int calcul_ajout_mot_hybride(racine*, char*);
int calcul_recherche_mot(node*, char*);
int calcul_recherche_mot_hybride(racine*, char*);

#endif
