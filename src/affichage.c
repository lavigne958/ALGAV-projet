#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "access.h"


void aux_affiche_noeud_simple(node* nd){
  int i;
  printf("prefix: %s\n", get_prefix(nd));

  if(nd->fils != NULL){

    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = nd->fils[i];
      if(fils != NULL){
	aux_affiche_noeud_simple(fils);
      }
    }
  }
}

void affiche_noeud_simple(node* nd){
  printf("affiche de l'arbre\n");

  int i;

  for(i = 0; i < NB_CHAR_MAX; i++){
    node* fils = nd->fils[i];
    if(fils != NULL){
      printf("racine->%c\n", (char)i);
      aux_affiche_noeud_simple(fils);
    }
  }
}
  


