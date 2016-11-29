#include <stdio.h>

#include "struct.h"
#include "access.h"
#include "util.h"


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
