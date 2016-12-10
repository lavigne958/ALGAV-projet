#ifndef _HYBRIDE_ACCESS_H
#define _HYBRIDE_ACCESS_H

#include "struct_hybride.h"


/**
 * alloue une racine en mémoire
 * renvoie un pointeur vers cette racine
 **/
racine* creer_racine();


/**
 * test si un noeud vaut NULL
 * donc s'il n'est pas aloué
 **/
int is_node_null_hybride(node_h*);


/**
 * alloue un noeud en mémoire et renvoie un pointeur sur ce noeud
 * initialise les champs:
 * - lettre = 0
 * - inf, eq, supp = NULL
 * - key = -1 ( car on commence à compter à partir de 0
 **/
node_h* creer_noeud_hybride();


/**
 * prend un noeud en argument et renvoie la lettre ascociée
 **/
char get_lettre(node_h*);


/**
 * met à jour la lettre d'un noeud s'il n'est pas NULL
 **/
void set_lettre(node_h*, char);


/**
 * retourne le fils gauche 
 **/
node_h* get_inf_node(node_h*);



/**
 * retourne le fils du milieu
 **/
node_h* get_eq_node(node_h*);


/**
 * retourne le fils droit
 **/
node_h* get_supp_node(node_h*);


/**
 * retourne la cle du node passer en parametre
 **/
int get_key(node_h*);


/**
 * met a jour la cle du node avec l'entier passer
 * en parametre
 **/
void set_key(node_h*, int);


/**
 * met a jour le fils gauche du node pere avec 
 * le node passer en parametre
 **/
void set_inf_node(node_h* pere, node_h* fils);


/**
 * met a jour le fils du milieu du node pere avec 
 * le node passer en parametre
 **/
void set_eq_node(node_h*, node_h*);


/**
 * met a jour le fils droit du node pere avec 
 * le node passer en parametre
 **/
void set_supp_node(node_h*, node_h*);

#endif
