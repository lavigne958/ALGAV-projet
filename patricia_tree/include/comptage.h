#ifndef _COMPTAGE_H
#define _COMPTAGE_H

#include "struct.h"

/**
 * compte le nombre de mots dans l'arbre
 */
int comptage_mot(node*);

/**
 * compte le nombre de suffixes dans l'arbre qui suivent la chaine
 * donner en argument
 */
int comptage_prefix_nb_mots(node*, char*);

/**
 * compte le nombre de pointeurs vers NULL
 */
int comptage_null(node*);
#endif
