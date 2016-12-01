#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "access.h"
#include "util.h"
#include "search.h"


int aux_comptage(node* nd){
  int res = 0;

  if(is_node_null(nd)){
    return res;
  }
  
  if(get_key(nd) >= 0){
    res = 1;
  }

  return res + aux_comptage(get_inf_node(nd)) +
    aux_comptage(get_eq_node(nd)) + aux_comptage(get_supp_node(nd));
}
  
int comptage(racine* root){
  if( root == NULL){
    exit_failure("comptage", "racine vaut NULL");
  }

  if(is_node_null(root->tree)){
    return 0;
  }else{
    return 0 + aux_comptage(root->tree);
  }
}

int aux_comptage_prefix_nb_mots(node* nd, char* mot){
  if( mot[0] == get_lettre(nd)){
    if( strlen(mot) == 1){
      //comptage
      int nb_suff =  aux_comptage(get_eq_node(nd));

      if(get_key(nd) >= 0){
	nb_suff++;
      }

      return nb_suff;
    }else{
      if( is_node_null(get_eq_node(nd))){
	return 0;
      }else{
	return aux_comptage_prefix_nb_mots(get_eq_node(nd), &mot[1]);
      }
    }
  }

  if( mot[0] < get_lettre(nd)){
    if( is_node_null(get_inf_node(nd))){
      return 0;
    }else{
      return aux_comptage_prefix_nb_mots(get_inf_node(nd), mot);
    }
  }else{
    if( is_node_null(get_supp_node(nd))){
      return 0;
    }else{
      return aux_comptage_prefix_nb_mots(get_supp_node(nd), mot);
    }
  }
}


int comptage_prefix_nb_mots(racine* root, char* mot){
  if( root == NULL){
    exit_failure("comptage_prefix_nb_mots", "racine vaut NULL");
  }

  if( is_node_null(root->tree)){
    return 0;
  }else{
    return aux_comptage_prefix_nb_mots(root->tree, mot);
  }
}
