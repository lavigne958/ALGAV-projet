#ifndef _DELETE_H
#define _DELETE_H



/**
 * supprime de l'arbre le mot passer en parametre
 **/
int delete_word(racine* racine, char* word);


/**
 * soit 2 node_h* tel que n fils de father retourne
 * 1 si n est le fils gauche, 
 * -1 si n est le fils droit,
 * 0 si n est le fils du milieu
 * exit sinon
 **/
int side_son(node_h* n, node_h* father);


#endif
