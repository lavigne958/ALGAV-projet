#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "access.h"
#include "util.h"

//recursive function that finds and delete a string in the dictionary
int aux_supression(node* nd, char* mot){
  //terminal case: if we found the string
  if( prefix_equals_string(nd, mot) ){
    printf("le mot a ete trouver\n");
    //if the string has epsilon, it has no child we just return 1 to delete the node
    if( prefix_has_epsilon(nd)){
      printf("le prefix contient epsilon a la fin\n");
      return 1;
      //if the node has epsilon in its child
    }else if( node_has_epsilon(nd)){
      printf("le noeud a un fils epsilon \n");
      int nb_fils = get_nb_fils(nd);

      //if it has more than on child we just delete the epsilon child entry
      if(nb_fils > 2){
	printf("le noeud a supprimer contient plus d'un fils\n");
	free(nd->fils[EPSILON]);
	nd->fils[EPSILON] = NULL;
	//if it has only one child we append the childj
      }else if( nb_fils == 2){
	printf("le noeud a 1 fils (+ EPSILON)\n");
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
	char* tmp_pre = malloc(sizeof(char) * strlen(get_prefix(nd->fils[pos])));
	strcpy(tmp_pre, get_prefix(nd->fils[pos]));
	sprintf(nd->fils[pos]->prefix, "%s%s",get_prefix(nd), tmp_pre);
	printf("resultat nouvelle chaine: %s\n",nd->fils[pos]->prefix);
	node* del_node = nd;
	/* ---------------------------------

	il n'est pas possible de changer les pointeur dans la fonction
	car nd n'est qu'un paramètre, il faut le faire dans la fonction appelante




	//-----------------------------------*/
	nd = get_fils_node(nd,(char)pos);
	//delete the node
	free(del_node);
	free(tmp_pre);
      }

      //return 0 so we stop deleteting in chain the nodes
      return 0;
    }

    

    exit_failure("aux_suppression", "prefix = mot (%s), epsilon non present\n");
    
  }else{
    printf("prefix != mot a supprimer\n");
    //check if prefix and mot have common letters
    int common_prefix = taille_prefixe_commun(mot, nd->prefix);
    printf("prefix commun : %d\n", common_prefix);
    if(strlen(mot) <= (unsigned int)nd->size || common_prefix < nd->size){
      printf("%s <= %s ou common_prefix (%d) < pref (%d)\n", mot, get_prefix(nd), common_prefix, nd->size);
      return -1;
    }else{
      char* sub_str = &mot[common_prefix];
      node* fils = get_fils_node(nd, sub_str[0]);

      if( is_node_null(fils)){
	printf("le fils vaut NULL, suppresion imposible");
	return -1;
      }

      printf("prefix commun, sub_str: %s\n", sub_str);
      if( aux_supression(fils, sub_str) == 1){
	printf("aux_ return 1\n");
	int i;
	int nb_fils = 0;
	int last_fils = -1;
	for(i = 0; i < NB_CHAR_MAX; i++){
	  if(nd->fils[i] != NULL){
	    nb_fils++;
	    //conservation de l'index du dernier fils au cas ou il n'y en as qu'un seul
	    last_fils = i;
	  }
	}

	printf("il y a %d fils, le dernier est %c\n", nb_fils, (char)last_fils);

	//-- cas impossible il me semble --
	if( nb_fils == 1){
	  printf("il y a 1 fils\n");
	  sprintf(nd->fils[last_fils]->prefix, "%s%s", get_prefix(nd),
		  get_prefix(nd->fils[last_fils]));
	  node* del_node = nd;
	  free(del_node);
	//---------------------------------
	}else{
	  printf("il y a plus de fils\n");
	  int index_fils = (int) sub_str[0];
	  nd->fils[index_fils] = NULL;
	  free(fils);
	}

	return 0;
      }else{
	printf("aux_ return 0\n");
	return 0;
      }
    }
  }
}

int supression(node* nd, char* mot){
  if(is_node_null(nd)){
    exit_failure("suppression", "noeud nd est null");
  }
  
  return aux_supression(nd, mot);
}
