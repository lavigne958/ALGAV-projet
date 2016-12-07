#include <stdio.h>
#include <string.h>

#include "struct_hybride.h"
#include "access_hybride.h"
#include "util_hybride.h"
#include "search_hybride.h"


int aux_comptage_hybride(node_h* nd){
  int res = 0;

  if(is_node_null_hybride(nd)){
    return res;
  }
  
  if(get_key(nd) >= 0){
    res = 1;
  }

  return res + aux_comptage_hybride(get_inf_node(nd)) +
    aux_comptage_hybride(get_eq_node(nd)) + aux_comptage_hybride(get_supp_node(nd));
}
  
int comptage_hybride(racine* root){
  if( root == NULL){
    exit_failure("comptage", "racine vaut NULL");
  }

  if(is_node_null_hybride(root->tree)){
    return 0;
  }else{
    return 0 + aux_comptage_hybride(root->tree);
  }
}

int aux_comptage_prefix_nb_mots_hybride(node_h* nd, char* mot){
  if( mot[0] == get_lettre(nd)){
    if( strlen(mot) == 1){
      //comptage
      int nb_suff =  aux_comptage_hybride(get_eq_node(nd));

      if(get_key(nd) >= 0){
	nb_suff++;
      }

      return nb_suff;
    }else{
      if( is_node_null_hybride(get_eq_node(nd))){
	return 0;
      }else{
	return aux_comptage_prefix_nb_mots_hybride(get_eq_node(nd), &mot[1]);
      }
    }
  }

  if( mot[0] < get_lettre(nd)){
    if( is_node_null_hybride(get_inf_node(nd))){
      return 0;
    }else{
      return aux_comptage_prefix_nb_mots_hybride(get_inf_node(nd), mot);
    }
  }else{
    if( is_node_null_hybride(get_supp_node(nd))){
      return 0;
    }else{
      return aux_comptage_prefix_nb_mots_hybride(get_supp_node(nd), mot);
    }
  }
}


int comptage_prefix_nb_mots_hybride(racine* root, char* mot){
  if( root == NULL){
    exit_failure("comptage_prefix_nb_mots", "racine vaut NULL");
  }

  if( is_node_null_hybride(root->tree)){
    return 0;
  }else{
    return aux_comptage_prefix_nb_mots_hybride(root->tree, mot);
  }
}
