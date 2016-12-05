#include <string.h>
#include <stdio.h>

#include "struct_hybride.h"
#include "util_hybride.h"
#include "access_hybride.h"
#include "rotation_hybride.h"

node_h* aux_insert(node_h* nd, char* mot, int val){
  if(is_node_null_hybride(nd)){
    nd = creer_noeud_hybride();
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

  if(is_node_null_hybride(root->tree)){
    printf("le noeud à la racine vaut NULL\n");
    root->tree = creer_noeud_hybride();
    set_lettre(root->tree, mot[0]);
  }

  root->tree = aux_insert(root->tree, mot, root->counter++);
}


node_h* aux_insert_equilibre(node_h* nd, char* mot, int val){
  if(is_node_null_hybride(nd)){
    nd = creer_noeud_hybride();
    set_lettre(nd, mot[0]);
    if(strlen(mot) == 1){
      set_key(nd, val);
      return nd;
    }else{
      char* sub_str = &mot[1];
      set_eq_node(nd, aux_insert_equilibre(get_eq_node(nd), sub_str, val));
      return nd;
    }
  }else{
    char lettre = get_lettre(nd);
    if(mot[0] == lettre && strlen(mot) == 1){
      set_key(nd, val);
      return nd;
    }

    node_h* new_child;
    
    if(mot[0] == lettre && strlen(mot) > 1){
      char* sub_str = &mot[1];
      new_child = aux_insert_equilibre(get_eq_node(nd), sub_str, val);
      set_eq_node(nd, new_child);
      nd = equilibre(nd);
      
      return nd;
    }else if(mot[0] < lettre){
      new_child = aux_insert_equilibre(get_inf_node(nd), mot, val);
      set_inf_node(nd, new_child);
      nd = equilibre(nd);
      return nd;
      
    }else{
      set_supp_node(nd, aux_insert_equilibre(get_supp_node(nd), mot, val));
      nd = equilibre(nd);

      return nd;
    }
  }
}


void insert_equilibre(racine* root, char* mot){
  if(root == NULL){
    exit_failure("insert", "racine vaut NULL");
  }
  
  if(is_node_null_hybride(root->tree)){
    printf("le noeud à la racine vaut NULL\n");
    root->tree = creer_noeud_hybride();
    set_lettre(root->tree, mot[0]);
  }
  
  root->tree = aux_insert_equilibre(root->tree, mot, root->counter++);
}
