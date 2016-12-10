#include <stdio.h>
#include <stdlib.h>

#include "struct_hybride.h"
#include "util_hybride.h"

racine* creer_racine(){
  racine* root = (racine*) malloc(sizeof(racine));
  if( root == NULL){
    exit_failure("creer_racine", "impossible d'allouer la racine en mémoire");
  }
  
  root->tree = NULL;
  root->counter = 0;
  
  return root;
}

int is_node_null_hybride(node_h* nd){
  return (nd == NULL);
}

node_h* creer_noeud_hybride(){
  node_h* nd = (node_h*) malloc(sizeof(node_h));

  if( is_node_null_hybride(nd)){
    exit_failure("creer_noeud", "impossible d'alouer le noeud");
  }

  nd->lettre = 0;
  nd->inf = NULL;
  nd->eq = NULL;
  nd->supp = NULL;
  nd->key = -1;

  return nd;
}



char get_lettre(node_h* nd){
  if(is_node_null_hybride(nd)){
    exit_failure("get_lettre", "le noeud vaut NULL");
  }

  return nd->lettre;
}


void set_lettre(node_h* nd, char new_lettre){
  if(is_node_null_hybride(nd)){
    exit_failure("set_lettre", "le noeud vaut NULL");
  }

  nd->lettre = new_lettre;
}


node_h* get_inf_node(node_h* nd){
  if(is_node_null_hybride(nd)){
    exit_failure("get_inf_node", "le noeud vaut NULL");
  }

  return nd->inf;
}

node_h* get_eq_node(node_h* nd){
  if(is_node_null_hybride(nd)){
    exit_failure("get_inf_node", "le noeud vaut NULL");
  }
  
  return nd->eq;
}

node_h* get_supp_node(node_h* nd){
  if(is_node_null_hybride(nd)){
    exit_failure("get_inf_node", "le noeud vaut NULL");
  }
  
  return nd->supp;
}

int get_key(node_h* nd){
  if( is_node_null_hybride(nd)){
    exit_failure("get_key", "le noeud nd vaut NULL");
  }

  return nd->key;
}

void set_key(node_h* nd, int key){
  if(is_node_null_hybride(nd)){
    exit_failure("set_key", "le noeud vaut NULL");
  }

  nd->key = key;
}

void set_inf_node(node_h* nd, node_h* new_inf){
  if(is_node_null_hybride(nd)){
    exit_failure("set_inf_node", "le noeud parent vaut NULL");
  }

  if(is_node_null_hybride(new_inf)){
    exit_failure("set_inf_node", "le nouveau noeud inf vaut NULL");
  }

  nd->inf = new_inf;
}

void set_eq_node(node_h* nd, node_h* new_eq){
  if(is_node_null_hybride(nd)){
    exit_failure("set_eq_node", "le noeud parent vaut NULL");
  }

  if(is_node_null_hybride(new_eq)){
    exit_failure("set_eq_node", "le nouveau noeud eq vaut NULL");
  }

  nd->eq = new_eq;
}

void set_supp_node(node_h* nd, node_h* new_supp){
  if(is_node_null_hybride(nd)){
    exit_failure("set_inf_node", "le noeud parent vaut NULL");
  }

  if(is_node_null_hybride(new_supp)){
    exit_failure("set_supp_node", "le nouveau noeud supp vaut NULL");
  }

  nd->supp = new_supp;
}
