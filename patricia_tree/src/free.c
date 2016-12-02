#include <stdlib.h>

#include "struct.h"
#include "access.h"



void free_tree(node* n){

  int i;
  
  if(has_childs(n) ){
    for(i = 0; i<NB_CHAR_MAX; i++){
      if(n->tab_fils[i] != NULL)
	free_tree( n->tab_fils[i] );
    }
  }
  free(n);
  
}
