#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "util.h"



node* creer_noeud(){
    node* retour;
    
    if( (retour = (node*) malloc(sizeof(node))) == NULL){
      exit_failure("creer_noeud","erreur malloc dans creer_noeud");
    }

    retour->fils = NULL;
    strcpy(retour->prefix,"\0");
    retour->size = 0;

    return retour;
}


int is_node_null(node* n){
       return n == NULL;
}

node** creer_tab_fils(){
  node** tab_fils = NULL;
  int i = 0;
  tab_fils = (node**) malloc(sizeof(node*) * (NB_CHAR_MAX + 1));

  if(tab_fils == NULL){
    exit_failure("add_epsilon_node","fils vaut NULL");
  }

  for(i = 0; i < (NB_CHAR_MAX + 1); i++){
    tab_fils[i] = NULL;
  }

  return tab_fils;
}

void creer_tableau_fils(node* n){

    if(is_node_null(n)){
      exit_failure("creer_tableau_fils","erreur node = null");
    }
	
    n->fils = creer_tab_fils();
}

char* get_prefix(node* n){
  
    if( is_node_null(n) ){
      return NULL;
    }
    
    return n->prefix;
}

void set_prefix(node* node, char* prefix){
  if( is_node_null(node) ){
    exit_failure("set_prefix","erreur node = NULL");
  }

  if( node->prefix == NULL){
    exit_failure("set_prefix","erreur prefix = NULL");
  }

  if(strlen(prefix) > (NB_CHAR_MAX + 1)){
    exit_failure("set_prefix","erreur prefix trop grand");
  }
  
  strcpy(node->prefix,prefix);
  node->size = strlen(prefix);
}


node* get_fils_node(node* n, char index){

  node* fils;

  if(is_node_null(n)){
    exit_failure("get_fils_node","node vaut NULL");
    exit(EXIT_FAILURE);
  }

  if( n->fils == NULL){
    exit_failure("get_fils_node","fils vaut NULL");
    exit(EXIT_FAILURE);
  }
    
  fils = n->fils[(int)index];
  
  if(is_node_null(fils)){
    return NULL;
  }
  
  return fils;
}

void set_fils_node(node* nd, node* fils, char index){
  
  if(is_node_null(nd)){
    exit_failure("set_fils_node", "nd vaut NULL");
    exit(EXIT_FAILURE);
  }

  if(nd->fils == NULL){
    exit_failure("set_fils_node", "nd vaut NULL");
    exit(EXIT_FAILURE);
  }

  if(is_node_null(fils)){
    exit_failure("set_fils_node", "fils vaut NULL");
    exit(EXIT_FAILURE);
  }

  nd->fils[(int) index] = fils;
}

void prefix_add_epsilon(node* nd){
  if(is_node_null(nd)){
    exit_failure("prefix_add_epsilon", "nd vaut NULL");
    exit(EXIT_FAILURE);
  }

  int taille_prefix = strlen(nd->prefix);

  nd->prefix[taille_prefix] = EPSILON;
  nd->prefix[taille_prefix+1] = '\0';
}

void add_espilon_node(node* nd){
  if(is_node_null(nd)){
    exit_failure("add_epsilon_node", "nd vaut NULL");
    exit(EXIT_FAILURE);
  }

  if(nd->fils == NULL){
    exit_failure("add_epsilon_node", "fils vaut NULL");
    exit(EXIT_FAILURE);
  }

  nd->fils[(int)EPSILON] = creer_noeud();

  nd->fils[(int)EPSILON]->prefix[0] = EPSILON;
  nd->fils[(int)EPSILON]->prefix[1] = '\0';
}

