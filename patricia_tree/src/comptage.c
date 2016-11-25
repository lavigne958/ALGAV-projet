#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "access.h"
#include "util.h"

void aux_comptage(node* nd, int* counter){
  if( prefix_has_epsilon(nd)){
    (*counter)++;
  }
  
  int i;
  
  if(has_childs(nd)){
    /* parse all the child of the node to call recursivly the counter */
    for(i = 0; i < NB_CHAR_MAX; i++){
      //printf("verifie fils %d-[%c]\n", i, (char)i);
      node* fils = get_fils_node(nd, (char)i);
      
      /* if the node is not null a child has a prefix */
      if(! is_node_null(fils)){
	aux_comptage(fils, counter);
      }
    }
  }
}

int comptage_mot(node* nd){
  if (is_node_null(nd)){
    exit_failure("comptage_mot", "la racine vaut NULL");
  }

  int counter = 0;
  int i;

  if( has_childs(nd)){
    /* parse all the child of the root to call recursivly the counter */
    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = get_fils_node(nd, (char)i);
      
      /* if the node is not null a child has a prefix */
      if(! is_node_null(fils)){
	aux_comptage(fils, &counter);
      }
    }
  }

  return counter;
}
