#ifndef _ACCESS_H
#define _ACCESS_H

/**
 * creer un noeud vide
 * alloue l'espace pour le prefixe
 * tableau de fils vaut NULL
 *
*/
node* creer_noeud();

/**
 * creer le tableau de fils
 * creer les pointeurs et les structures
*/
int creer_fils(node* node);

/**
 * renvoie le préfixe du noeud
 * 
*/
char* get_prefix(node* node);

/**
 * renvoie le fils pointé par la lettre index
*/
node* get_fils_node(node* node, char index);

#endif
