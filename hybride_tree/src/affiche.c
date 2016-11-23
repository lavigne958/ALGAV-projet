#include <stdio.h>

#include "struct.h"
#include "util.h"
#include "access.h"


void aux_affichage_simple(node* nr, int indent){
  int i;

  printf("%c->", get_lettre(nr));

  if( is_node_null(nr->inf) &&
      is_node_null(nr->eq) &&
      is_node_null(nr->supp)){
    return;
  }

  if(!is_node_null(nr->supp)){
    aux_affichage_simple(nr->supp, indent+1);
  }

  printf("\n");

  if(!is_node_null(nr->eq)){
    for(i = 0; i < indent+1; i++){
      printf("   ");
    }
    aux_affichage_simple(nr->eq, indent+1);
  }
  printf("\n");
  
  if(!is_node_null(nr->inf)){
    for(i = 0; i < indent+1; i++){
      printf("   ");
    }
    aux_affichage_simple(nr->inf, indent+1);
  }
}


void affichage_simple(racine* root){
  if(root == NULL){
    exit_failure("affichage_simple", "la racine vaut NULL");
  }

  int indent = 0;

  aux_affichage_simple(root->tree, indent);
}
