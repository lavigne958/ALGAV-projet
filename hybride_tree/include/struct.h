#ifndef _STRUCT_H
#define _STRUCT_H


/* structure d'un arbre binaire:
 * contient:
 * - char lettre: le caractère du noeud
 * - node* inf: le fils dont la lettre est inférieur à lettre
 * - node* eq: le fils qui continue le mot commencé par lettre
 * - node* supp: le fils dont la lettre est supérieur à lettre
 * - int val: une valeur si le noeud est la fin d'un mot
 */

typedef struct node{
  char lettre;
  struct node* inf;
  struct node* eq;
  struct node* supp;
  int key;
}node;

  

/*
 * structure de la racine de l'arbre
 * contient:
 * - un pointeur vers l'arbre
 * - un compteur pour les ajouts.
 */
typedef struct racine{
  node* tree;
  int counter;
}racine;


#endif
