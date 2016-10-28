#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "structure.h"
#include "access.h"





void sub_add_word(node* n,char* mot){

  
  

  int nb_lettre_commun;
  char* 
  char* prefix = get_prefix(n);
  int taille_prefix = n->size;
  int taille_mot = strlen(mot);  
  int prefix_avec_epsilon = 0;  /* marqueur permettant de savoir si fils existe */
  
  if(prefix[taille_prefix-1] == EPSILON){
    taille_prefix--;
    prefix_avec_epsilon = 1;
  }
}



void ajouter_mot(node* arbre, char* mot){

  node* fils;
  int taille_mot = strlen(mot);
  
  /* test si l'arbre existe */
  if(is_node_null(arbre))
    exit_failure("ajouter_mot", "erreur arbre: NULL");
  
    /* test si le mot est une chaine vide */
  if( !taille_mot )
    exit_failure("ajouter_mot", "erreur chaine vide");
      
  /* test si le mot est trop grand */
  if(taille_mot >= NB_CHAR_MAX+1)
    exit_failure("ajouter_mot", "ajout d'un mot trop long");

  if(!arbre->tab_fils)
    creer_tableau_fils(arbre);
  
  fils = get_fils_node(arbre,mot[0]);
  
  if(fils == NULL){ /* cas ou pas de fils, creation + insertion direct */
    fils = creer_noeud();
    set_fils_node(arbre, fils, mot[0]);
    set_prefix(fils, mot);
    prefix_add_epsilon(fils);
    fils->size = taille_mot+1; /* +1 pour le EPSILON */
  }else{ /* cas ou le fils existe, parcourt recursif et insertion progressive */
    return sub_add_word(fils,chaine);
 }
      
