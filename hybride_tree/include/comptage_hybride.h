#ifndef _COMPTAGE_HYBRIDE_H
#define _COMPTAGE_HYBRIDE_H


/**
 * compte le nombre de mot present dans l'arbre
 **/
int comptage_hybride(racine*);

/**
 * compte le nombre de mot dans l'arbre qui possede comme
 * prefix la chaine passer en parametre
 **/
int comptage_prefix_nb_mots_hybride(racine*, char*);
#endif
