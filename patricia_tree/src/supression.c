#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "access.h"
#include "util.h"

//recursive function that finds and delete a string in the dictionary
int aux_supression(node* nd, char* mot){
  //terminal case: if we found the string
  char prefix[NB_CHAR_MAX];
  int pref_size;

  strcpy( prefix, get_prefix(nd));

  if( prefix_has_epsilon(nd)){
    pref_size = nd->size - 1;
    prefix[pref_size] = '\0';
  }else{
    pref_size = nd->size;
  }
    
  if( strcmp(prefix, mot) == 0 ){
    //if the string has epsilon, it has no child we just return 1 to delete the node
    if( prefix_has_epsilon(nd)){
      return 1;
      //if the node has epsilon in its child
    }else if( node_has_epsilon(nd)){
      int nb_fils = get_nb_fils(nd);

      //if it has more than on child we just delete the epsilon child entry
      if(nb_fils > 2){
	free(nd->tab_fils[EPSILON]);
	nd->tab_fils[EPSILON] = NULL;
	//if it has only one child we append the childj
      }else if( nb_fils == 2){
	int i = 0;
	int pos = -1;
	//look for the position of the only child
	while(i < NB_CHAR_MAX || pos == -1){
	  if(nd->tab_fils[i] != NULL && nd->tab_fils[i]->prefix[0] != EPSILON){
	    pos = i;
	  }
	  i++;
	}

	free(get_fils_node(nd, EPSILON));
	nd->tab_fils[i] = NULL;

	return (long)nd->tab_fils[pos];
      }

      //return 0 so we stop deleteting in chain the nodes
      return 0;
    }
    
    return -1;
    
  }else{
    //check if prefix and mot have common letters
    int common_prefix = taille_prefixe_commun(mot, nd->prefix);
    if(strlen(mot) <= (unsigned int)nd->size || common_prefix < nd->size){
      return -1;
    }else{
      char* sub_str = &mot[common_prefix];
      node* fils = get_fils_node(nd, sub_str[0]);

      if( is_node_null(fils)){
	return -1;
      }

      int supp = aux_supression(fils, sub_str);
      if( supp == 1){
	int i;
	int nb_fils = 0;
	int last_fils = -1;
	for(i = 0; i < NB_CHAR_MAX; i++){
	  if(nd->tab_fils[i] != NULL){
	    nb_fils++;
	    //conservation de l'index du dernier fils au cas ou il n'y en as qu'un seul
	    last_fils = i;
	  }
	}

	//-- cas impossible il me semble --
	if( nb_fils == 1){
	  sprintf(nd->tab_fils[last_fils]->prefix, "%s%s", get_prefix(nd),
		  get_prefix(nd->tab_fils[last_fils]));
	  nd->size = strlen(nd->tab_fils[last_fils]->prefix);
	  node* del_node = nd;
	  free(del_node);
	//---------------------------------
	}else{
	  printf("free du fils: %c\n", sub_str[0]);
	  int index_fils = (int) sub_str[0];
	  nd->tab_fils[index_fils] = NULL;
	  free(fils);
	}

	return 0;

      }else if(supp > 1){
	node* grd_child = (node*) ((long)supp);
	char* tmp_pre = malloc(sizeof(char) * grd_child->size);
	strcpy(tmp_pre, grd_child->prefix);
	sprintf(grd_child->prefix, "%s%s", get_prefix(fils), tmp_pre);
	grd_child->size = strlen(grd_child->prefix);
	set_fils_node(nd, grd_child, grd_child->prefix[0]);
	free(tmp_pre);
	free(fils);
	return 0;
      }else{
	return 0;
      }
    }
  }

  printf("impossible d'arriver à ce point -- sinon erreur\n\n");
  return -1;
}

int supression(node* nd, char* mot){
  if(is_node_null(nd)){
    exit_failure("suppression", "noeud nd est null");
  }

  int val;

  //if it has childs
  if( has_childs(nd)){
    int i;
    
    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = get_fils_node(nd, (char)i);

      //and they are not NULL
      if( !is_node_null(fils)){
	val = aux_supression(fils, mot);

	if(val == 1){
	  free(fils);
	  nd->tab_fils[i] = NULL;
	}
      }
    }
  }
  return val;
}
