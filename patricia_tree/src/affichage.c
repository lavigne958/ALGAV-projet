#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "access.h"


int affiche_attribut_node(node* n){
  printf("\n");
  if(!n){
    printf("Un node n'existe pas\n");
    return 0;
  }
  printf("prefix: %s\n",get_prefix(n));
  printf("size: %d\n",n->size);
  if(n->tab_fils == NULL)
    printf("tab_fils: NULL\n");
  else
    printf("tab_fils: present\n");
  printf("\n");
  return 1;
}




void aux_affiche_noeud_simple(node* nd, int indent){
  int i, j;

  //affiche le préfixe simplement: prefix: xxxxxx
  printf("prefix: %s\n", get_prefix(nd));

  //si des fils existent
  if(nd->tab_fils != NULL){

    //pour chacun d'entre eux
    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = get_fils_node(nd, (char)i);
      if(!is_node_null(fils)){
	int i;

	//affiche l'indentation puis recursivement sur les fils
	for(j = 0; j < indent; j++){
	  printf("\t");
	}
	aux_affiche_noeud_simple(fils, indent+1);
      }
    }
  }
}

void affiche_noeud_simple(node* nd){
  printf("affiche de l'arbre\n");

  int i;

  for(i = 0; i < NB_CHAR_MAX; i++){
    node* fils = nd->tab_fils[i];
    if(fils != NULL){
      printf("racine->%c\n", (char)i);
      aux_affiche_noeud_simple(fils,1);
    }
  }
}

void affichage_alpha(node* nd, char* buffer, int buffer_size){

  char word[128];
  int word_size;

  //make a copy of the buffer not to lose it.
  //concate the prerix to the copy of the buffer
  //adjust the new size of the buffer
  strcpy(word, buffer);
  strcat(word, get_prefix(nd)); 
  word_size = buffer_size + nd->size;

  //if the prefix has epsilon then we need to adjuste the size, the last char and pritn it.
  if( prefix_has_epsilon(nd) ){
    word[word_size-1] = '\0';
    printf("- %s\n", word);
    
  }else{
    //else it is jsute a subword of its childs
    if( node_has_epsilon(nd) ){
      printf("- %s\n", word);
      
    }

    int i;

    for(i = 0; i < NB_CHAR_MAX; i++){
      if( i != EPSILON ){
	node* fils = get_fils_node(nd, (char)i);

	if( !is_node_null(fils)){

	  //recursive case
	  affichage_alpha(get_fils_node(nd, (char)i), word, word_size);
	}
      }
    }
  }
}

void affichage_racine_alphabetique(node* racine){
  char buffer[512];
  int i;

  //initiate the buffer with a null char at the begining to make it length 0;
  buffer[0] = '\0';
  
  printf("======= Affichage de l'arbre ======\n");
  
  for(i = 0; i < NB_CHAR_MAX; i++){
    node* fils = get_fils_node(racine, (char) i);
    if( !is_node_null(fils)){
      affichage_alpha(fils, buffer, 0);
    }
  }
}

