#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"
#include "util.h"
#include "search.h"

void aux_comptage(node* nd, int* counter){

  //cas simple, on à trouvé un mot.
  if( prefix_has_epsilon(nd)){
    //on augmente le compteur
    (*counter)++;
  }
  
  int i;

  //si le noeud à des fils ( donc des sous-mots possibles)
  if(has_childs(nd)){
    /* parse all the child of the node to call recursivly the counter */
    for(i = 0; i < NB_CHAR_MAX; i++){
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


void aux_comptage_prefix_nb_mots(node* nd, char* string, int* counter){
  if( prefix_equals_string(nd,string)){
    *counter = comptage_mot(nd);
    
  }else{
    int comon_prefix = taille_prefixe_commun(string, nd->prefix);
    if( strlen(string) <= (unsigned int)nd->size ||  comon_prefix < nd->size){
      if(strstr(get_prefix(nd), string)){
	*counter = comptage_mot(nd);
      }else{
	return;
      }
    }else{
      //cas ou la string est strictement plus grande que le prefixe avec le prefixe compris dedans
      char* sub_str = &string[comon_prefix];
      node* fils = get_fils_node(nd,sub_str[0]);
      //if the node doesn't have a child with the same first letter then the string is not present
      if(is_node_null(fils)){
	printf("le fils: %c vaut NULL, %s n'existe pas dans l'arbre\n",string[0],string);
	return;
      }
      aux_comptage_prefix_nb_mots(fils,sub_str, counter);
    }
  }
}


int comptage_prefix_nb_mots(node* nd, char* mot){
  if( is_node_null(nd)){
    exit_failure("comptage_prefix_nb_mots", "racine vaut NULL");
  }

  if( has_childs(nd)){
    int i;
    int counter = 0;

    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = get_fils_node(nd, (char)i);

      if(!is_node_null(fils)){
	aux_comptage_prefix_nb_mots(fils, mot, &counter);
      }
    }
    
    return counter;
  }else{
    //if the root has no child then word is prefix of no-one.
    return 0;
  }
}

int aux_comptage_null(node* nd){
  int counter = 0;

  //si il existe des fils
  if(has_childs(nd)){
    int i;

    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = get_fils_node(nd, (char)i);

      //si le fils vaut null, +1
      if( is_node_null(fils)){
	counter++;
      }else{

	//sinon on vérifie ses sous fils
	counter += aux_comptage_null(fils);
      }
    }    
  }else{
    //si aucune fils alors le noeud à NB_CHAR_MAX (127) fils à null 
    counter = NB_CHAR_MAX;
  }

  return counter;
}
  
int comptage_null(node* nd){
  if( is_node_null(nd)){
    exit_failure("comptage_null", "la racine vaut null");
  }

  int counter = 0;

  /* même fonction que celle récursive au dessus,
   * seuld détails, pour la racine il faut tester si le noeud n'est pas NULL
   * et arreter le programme promptement dans ce cas
   */
  if(has_childs(nd)){
    int i;
    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = get_fils_node(nd, (char)i);
      if(is_node_null(fils)){
	counter++;
      }else{
	counter += aux_comptage_null(fils);
      }
    }
  }else{
    counter = NB_CHAR_MAX;
  }

  return counter;
}
