#include <string.h>

#include "struct.h"
#include "access.h"

//recursive function that finds and delete a string in the dictionary
int aux_suppression(node* nd, char* mot){
  //terminal case: if we found the string
  if( prefix_equals_string(nd, mot) ){
    //if the string has epsilon, it has no child we just return 1 to delete the node
    if( prefix_has_epsilon(nd)){
      return 1;
      //if the node has epsilon in its child
    }else if( node_has_epsilon(nd)){
      int nb_fils = get_fils_node(nd);

      //if it has more than on child we just delete the epsilon child entry
      if(nb_fils > 1){
	free(nd->fils[EPSILON]);
	nd->fils[EPSILON] = NULL;
	//if it has only one child we append the childj
      }else if( nb_fils == 1){
	int i = 0;
	int pos = -1;
	//look for the position of the only child
	while(i < NB_CHAR_MAX || pos == -1){
	  if(nd->fils[i] != NULL){
	    pos = i;
	  }
	  i++;
	}

	//concat the actual prefix and the child prefix
	sprintf(nd->fils[pos]->prefix, "%s%s",get_prefix(nd), get_prefix(nd->fils[pos]));
	node* del_node = nd;
	nd = get_fils_node(nd,(char)pos);
	//delete the node
	free(del_node);	
      }

      //return 0 so we stop deleteting in chain the nodes
      return 0;
    }
    
  }else{
    //check if prefix and mot have common letters
    int common_prefix = taille_prefixe_commun(mot, nd->prefix);
    if(strlen(mot) <= (unsigned int)nd->size || common_prefix < nd->size){
      printf("%s <= %s ou common_prefix (%d) < pref (%d)\n", string, get_prefix(nd), common_prefix, nd->size);
      return -1;
    }else{
      char* sub_str = &mot[common_prefix];
      node* fils = get_fils_node(nd, sub_str[0]);

      if( is_node_null(fils)){
	printf("le fils vaut NULL, suppresion imposible");
	return -1;
      }

      if( aux_suppression(fils, sub_str) == 1){
	//END
      }
    }
  }
}

int suppression(node* nd, char* mot){
  if(is_node_null(nd)){
    exit_failure("suppression", "noeud nd est null");
  }

  
  
  return aux_suppression(nd, mot);
}
