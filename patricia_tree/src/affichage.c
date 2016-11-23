#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "access.h"


int affiche_attribut_node(node* n){
  printf("\n");
  if(!n){
    printf("Un node n'existe pas\n");
    return 0;
  }
  printf("prefix: %s\n",get_prefix(n));
  printf("size: %d\n",n->size);
  if(n->tab_fils == NULL)
    printf("tab_fils: NULL\n");
  else
    printf("tab_fils: present\n");
  printf("\n");
  return 1;
}




void aux_affiche_noeud_simple(node* nd, int indent){
  int i, j;
  printf("prefix: %s\n", get_prefix(nd));
  
  if(nd->tab_fils != NULL){
    
    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = nd->tab_fils[i];
      if(fils != NULL){
	for(j = 0; j < indent; j++){
	  printf("\t");
	}
	aux_affiche_noeud_simple(fils, indent+1);
      }
    }
  }
}

void affiche_noeud_simple(node* nd){
  printf("affiche de l'arbre\n");

  int i;

  for(i = 0; i < NB_CHAR_MAX; i++){
    node* fils = nd->tab_fils[i];
    if(fils != NULL){
      printf("racine->%c\n", (char)i);
      aux_affiche_noeud_simple(fils,1);
    }
  }
}
  


