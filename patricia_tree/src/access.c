#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h" 
#include "util.h"



int is_node_null(node* n){
  return n == NULL;
}

node** creer_tab_sans_pere(){
  node** tab_fils = NULL;
  int i = 0;
  tab_fils = (node**) malloc(sizeof(node*) * (NB_CHAR_MAX + 1));

  if(tab_fils == NULL){
    exit_failure("creer_tab_sans_pere","fils vaut NULL");
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
	
  n->tab_fils = creer_tab_sans_pere();
}

node* creer_noeud(){
  node* retour;
    
  if( (retour = (node*) malloc(sizeof(node))) == NULL)
    exit_failure("creer_noeud","erreur malloc dans creer_noeud");

  retour->tab_fils = NULL;
  strcpy(retour->prefix,"\0");
  retour->size = 0;

  return retour;
}



char* get_prefix(node* n){
  
  if( is_node_null(n) ){
    return NULL;
  }
    
  return n->prefix;
}

void set_prefix(node* node, char* nouv_prefix){
  if( is_node_null(node) ){
    exit_failure("set_prefix","erreur node = NULL");
  }

  if( node->prefix == NULL){
    exit_failure("set_prefix","erreur prefix = NULL");
  }

  if(strlen(nouv_prefix) > (NB_CHAR_MAX + 1)){
    exit_failure("set_prefix","erreur prefix trop grand");
  }
  
  strcpy(node->prefix, nouv_prefix);

  node->size = strlen(nouv_prefix);
}

int prefix_equals_string(node* nd, char* string){
  /* get the prefix size to iterate thru */
  unsigned int prefix_size = nd->size;
  unsigned int i=0;

  /*if the prefix has EPSILON, do not take it into count */
  if(nd->prefix[nd->size-1] == EPSILON){
    prefix_size--;
  }

  /*if the string is not exactly the same size it can not be equals*/
  if(strlen(string) != prefix_size){
    return 0;
  }

  /*iterate thru the two word if any charactere is different then return 0*/
  while(i < prefix_size){
    if(nd->prefix[i] != string[i]){
      return 0;
    }
    i++;
  }

  return 1;
}


node* get_fils_node(node* n, char index){

  node* fils;

  if(is_node_null(n))
    exit_failure("get_fils_node","node vaut NULL");

  if( n->tab_fils == NULL) 
    exit_failure("get_fils_node","fils vaut NULL");

    
  fils = n->tab_fils[(int)index];
  
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

  if(nd->tab_fils == NULL){ 
    exit_failure("set_fils_node", "tableau de fils vaut NULL");
    exit(EXIT_FAILURE);
  }

  if(is_node_null(fils)){
    exit_failure("set_fils_node", "fils vaut NULL");
    exit(EXIT_FAILURE);
  }

  nd->tab_fils[(int) index] = fils;

}


void prefix_add_epsilon(node* nd){
  if(is_node_null(nd)){
    exit_failure("prefix_add_epsilon", "nd vaut NULL");
    exit(EXIT_FAILURE);
  }

  int taille_prefix = strlen(nd->prefix);

  nd->prefix[taille_prefix] = EPSILON;
  nd->prefix[taille_prefix+1] = '\0';

  nd->size ++;
}

void add_epsilon_node(node* nd){
  if(is_node_null(nd)){
    exit_failure("add_epsilon_node", "nd vaut NULL");
    exit(EXIT_FAILURE);
  }

  if(nd->tab_fils == NULL){
    exit_failure("add_epsilon_node", "fils vaut NULL");
    exit(EXIT_FAILURE);
  }

  nd->tab_fils[(int)EPSILON] = creer_noeud();

  nd->tab_fils[(int)EPSILON]->prefix[0] = EPSILON;
  nd->tab_fils[(int)EPSILON]->prefix[1] = '\0';
  nd->tab_fils[(int)EPSILON]->size = 1;
}

int prefix_has_epsilon(node* nd){
  if(nd->prefix[nd->size-1] == EPSILON){
    return 1;
  }else{
    return 0;
  }
}

int node_has_epsilon(node* nd){
  if(prefix_has_epsilon(nd)){
    return 1;
  }else{
    node* epsilon = get_fils_node(nd,EPSILON);

    if(is_node_null(epsilon)){
      return 0;
    }
    
    if(epsilon->prefix[0] == EPSILON){
      return 1;
    }else{
      return 0;
    }
  }
}

int has_childs(node* nd){
  if(nd->tab_fils == NULL){
    return 0;
  }else{
    return 1;
  }
}

int get_nb_fils(node* nd){
  int i;
  int nb_fils = 0;

  for(i = 0; i < NB_CHAR_MAX; i++){
    if(nd->tab_fils[i] != NULL){
      nb_fils++;
    }
  }

  return nb_fils;
}


node** get_tab_fils(node*  n){
  if( is_node_null(n) ){
    return NULL;
  }
  
  return n->tab_fils;  
}

void set_tab_fils(node*  n, node** tf){

  if( is_node_null(n) ){
    exit_failure("set_prefix","erreur node = NULL");
  }
  n->tab_fils = tf;
}


void set_size(node* n, int new_size){
  if( is_node_null(n) )
    exit_failure("set_prefix","erreur node = NULL");
  
  n->size = new_size;
}
