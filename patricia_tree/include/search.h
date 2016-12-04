#ifndef _SEARCH_H
#define _SEARCH_H

/**
 * effectue la recherche d'un mot dans l'arbre.
 * si le mot existe: retour 1
 * si le mot existe mais ne ce finit par epsilon: retourne -1
 * si le mot n'existe pas: retourne 0
 */

int search_word(node*, char*);

int recherche_arbre(node*, char*);
#endif
