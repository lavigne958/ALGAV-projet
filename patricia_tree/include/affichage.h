#ifndef _AFFICH_H
#define _AFFICH_H

/**
 * permet d'afficher les attributs d'un noeud
 * - prefix, ...
 */
int affiche_attribut_node(node* );

/**
 * affichage simple de l'arbre
 * ATTENTION: n'est pas pratique pour des grands arbres
 * affiche le prefixe, puis tout ses fils récursivement
 */
void affiche_noeud_simple(node*);

/**
 * affichage en ordre alphabétique de tout les mots de l'arbre
 * pratique, ordoné et facile à lire
 */
void affichage_racine_alphabetique(node*);
#endif
