#include <string.h>
#include <stdio.h>

#include "struct.h"
#include "util.h"
#include "access.h"

int aux_search(node* nd, char* mot){
  if( mot[0] == get_lettre(nd)){
    if( strlen(mot) == 1){
      if( get_key(nd) != -1){
	return 1;
      }else{
	return 0;
      }
    }else{
      if( is_node_null(get_eq_node(nd))){
	return 0;
      }else{
	return aux_search(get_eq_node(nd), &mot[1]);
      }
    }
  }

  if( mot[0] < get_lettre(nd)){
    if( is_node_null(get_inf_node(nd))){
      return 0;
    }else{
      return aux_search(get_inf_node(nd), mot);
    }
  }else{
    if( is_node_null(get_supp_node(nd))){
      return 0;
    }else{
      return aux_search(get_supp_node(nd), mot);
    }
  }
}

int search(racine* racine, char* mot){
  if(racine == NULL){
    exit_failure("search", "racine NULL");
  }

  if(is_node_null(racine->tree)){
    return 0;
  }else{
    return aux_search(racine->tree, mot);
  }
}
