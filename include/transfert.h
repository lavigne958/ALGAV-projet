#ifndef _TRANSFERT_H
#define _TRANSFERT_H

#define MOITIE_ALPHA 109

/*----- fonction don't j'ai besoin ds hybride -----*/

/**
 * fonction qui ajoute un node a droite ou a gauche de n
 **/
void add_in_side(node_h* n, node_h* new_node);


/*----- fonction don't j'ai besoin ds patricia -----*/

/**
 * renvoi le premier charactere du prefixe du node passer en parametre
 */
char get_char_zero(node* n);

/*----- fonctions permettant le passage de patricia a hybride -----*/

/**
 * fonction renvoyant un arbre hybride resultant de l'arbre patricia
 * passer en parametre
 */
racine* patricia_to_hybride(node* tree_p);


/*----- fonctions permettant le passage de patricia a hybride -----*/

/**
 * fonction renvoyant un arbre patricia resultant de l'arbre hybride
 * passer en parametre
 */
/*node_p* hybride_to_patricia(racine* tree_h);
 */
#endif
