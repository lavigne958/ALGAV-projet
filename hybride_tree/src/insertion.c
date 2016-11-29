#include <string.h>
#include <stdio.h>

#include "struct.h"
#include "util.h"
#include "access.h"

node* aux_insert(node* nd, char* mot, int val){
  if(is_node_null(nd)){
    nd = creer_noeud();
    set_lettre(nd, mot[0]);
    if(strlen(mot) == 1){
      set_key(nd, val);
      return nd;
    }else{
      char* sub_str = &mot[1];
      set_eq_node(nd, aux_insert(get_eq_node(nd), sub_str, val));
      return nd;
    }
  }else{
    char lettre = get_lettre(nd);
    if(mot[0] == lettre && strlen(mot) == 1){
      
      set_key(nd, val);
      return nd;
    }

    if(mot[0] == lettre && strlen(mot) > 1){
      char* sub_str = &mot[1];
      set_eq_node(nd, aux_insert(get_eq_node(nd), sub_str, val));
      return nd;
    }else if(mot[0] < lettre){
      set_inf_node(nd, aux_insert(get_inf_node(nd), mot, val));
      return nd;
      
    }else{
      set_supp_node(nd, aux_insert(get_supp_node(nd), mot, val));
      return nd;
    }
  }
}

void insert(racine* root, char* mot){
  if(root == NULL){
    exit_failure("insert", "racine vaut NULL");
  }

  if(is_node_null(root->tree)){
    printf("le noeud à la racine vaut NULL\n");
    root->tree = creer_noeud();
    set_lettre(root->tree, mot[0]);
  }

  root->tree = aux_insert(root->tree, mot, root->counter++);
}
