#include <string.h>
#include <stdio.h>

#include "struct.h"
#include "access.h"
#include "util.h"

node** clone_tab_fils(node** tf);

node* clone(node* n){
  node* new_node;
  if(!n)
    exit_failure("clone","le node a cloner n'existe pas");

  //alloue un nouveau noeud
  new_node = creer_noeud();
  //met à jour le préfix
  set_prefix(new_node, get_prefix(n));
  //s'il existe des fils les recopies
  if(has_childs(n)){
    new_node->tab_fils = clone_tab_fils(n->tab_fils);
  }

  return new_node;
}

node** clone_tab_fils(node** tf){
  node ** new_tf;
  int i;
  
  if(!tf)
    exit_failure("clone_tab_fils","le tab de node a cloner n'existe pas");

  new_tf = creer_tab_sans_pere();
  for(i = 0; i < NB_CHAR_MAX; i++){
      if(tf[i] != NULL){
        new_tf[i] = clone(tf[i]);
      }
  }
  return new_tf;
}

