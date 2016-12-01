#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "access.h"
#include "util.h"



int profondeur_sous_arbre(node* n){

  int p = 0;
  int tmp, i;
  if(is_node_null(n))
    exit_failure("profondeur_sous_arbre","appel sur un node qui vaut NULL");
  
  if(has_childs(n)){
    for(i = 0; i < NB_CHAR_MAX; i++){
      if(n->tab_fils[i] != NULL){
	tmp = profondeur_sous_arbre(n->tab_fils[i]);
	p = max(tmp,p);
      }
    }
    return 1 + p;
  }else{
    return 0;
  }
}
  




int profondeur_arbre_entier(node* n){
  int p = 0;
  int tmp,i;
  if(is_node_null(n))
    return -1;
  
  if(strcmp(get_prefix(n),""))
    exit_failure("profondeur_arbre_entier","cette fonction doit etre appelee sur une racine\n");

  if(has_childs(n)){
    for(i = 0; i < NB_CHAR_MAX; i++){
      if(n->tab_fils[i] != NULL){
	tmp = profondeur_sous_arbre(n->tab_fils[i]);
	p = max(tmp,p);
      }
    }
    return 1 + p;
  }else{
    return 0;
  }
}



			   
   
