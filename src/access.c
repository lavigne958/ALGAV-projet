#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"



node* creer_noeud(){
    node* retour;
    
    if( (retour = (node*) malloc(sizeof(node))) == NULL){
        fprintf(stderr,"erreur malloc dans creer_noeud\n");
        exit(EXIT_FAILURE);
    }

    retour->fils = NULL;
    strcpy(retour->prefix,"\0");
    retour->size = 0;

    return retour;
}


int is_node_null(node* n){
       return n == NULL;
}

int creer_fils(node* n){
    int i;

    if(is_node_null(n)){
      fprintf(stderr,"erreur node = null , creer fils\n");
      return -1;
    }
	
    n->fils = (node**) malloc(sizeof(node*) * (NB_CHAR_MAX + 1));
    
    if(n->fils == NULL){
      fprintf(stderr,"erreur node->fils = null , creer fils\n");
      return -1;
    }
    
    for(i = 0; i < (NB_CHAR_MAX + 1); i++){
      n->fils[i] = creer_noeud();
    }
    
    return 0;
}

char* get_prefix(node* n){
  
    if( is_node_null(n) ){
      return NULL;
    }
    
    return n->prefix;
}

void set_prefix(node* node, char* prefix){
  if( is_node_null(node) ){
    fprintf(stderr,"erreur node: NULL - set_prefix");
    exit(EXIT_FAILURE);
  }

  if( node->prefix == NULL){
    fprintf(stderr,"erreur prefix: NULL - set_prefix");
    exit(EXIT_FAILURE);
  }

  if(strlen(prefix) > (NB_CHAR_MAX + 1)){
    fprintf(stderr,"erreur prefix > %d - set_prefix",(NB_CHAR_MAX + 1));
    exit(EXIT_FAILURE);
  }
  
  strcpy(node->prefix,prefix);
  node->size = strlen(prefix);
}


node* get_fils_node(node* n, char index){

  node* fils;

  if(is_node_null(n)){
    return NULL; 
  }
  
  fils = n->fils[(int)index];
  
  if(is_node_null(fils)){
    return NULL;
  }
  
  return fils;
}
