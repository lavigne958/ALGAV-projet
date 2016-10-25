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
 * verifie qu'un noeud n n'est pas null
 * et affiche un message d'erreur dans le cas vrai
 */
int is_node_null(node* n);

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
 * modifie le préfixe du noeud
 * 
*/
void set_prefix(node* node, char* prefix);


/**
 * renvoie le fils pointé par la lettre index
*/
node* get_fils_node(node* node, char index);


#endif
