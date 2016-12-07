#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "access.h"



void free_tree(node* n){

  int i;

  //si des fils existent
  if(has_childs(n) ){
    for(i = 0; i<NB_CHAR_MAX; i++){

      //si le fils ne vaut pas null alors on appel recursivement
      if( !is_node_null(n->tab_fils[i]))
	free_tree( n->tab_fils[i] );
    }
  }

  //je suis un fils je ne vaut pas NULL, je me libère de la mémoire
  free(n);
}
