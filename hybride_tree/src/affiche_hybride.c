#include <stdio.h>
#include <string.h>

#include "struct_hybride.h"
#include "util_hybride.h"
#include "access_hybride.h"


void aux_affichage_simple(node_h* nr, int indent){
  int i;
  
  printf("%c->", get_lettre(nr));
  
  if( is_node_null_hybride(nr->inf) &&
      is_node_null_hybride(nr->eq) &&
      is_node_null_hybride(nr->supp)){
    return;
  }
  
  if(!is_node_null_hybride(nr->supp)){
    aux_affichage_simple(nr->supp, indent+1);
  }
  
  printf("\n");
  
  if(!is_node_null_hybride(nr->eq)){
    for(i = 0; i < indent+1; i++){
      printf("   ");
    }
    aux_affichage_simple(nr->eq, indent+1);
  }
  printf("\n");
  
  if(!is_node_null_hybride(nr->inf)){
    for(i = 0; i < indent+1; i++){
      printf("   ");
    }
    aux_affichage_simple(nr->inf, indent+1);
  }
    
}


void affichage_simple(racine* root){
  if(root == NULL){
    exit_failure("affichage_simple", "la racine vaut NULL");
  }

  int indent = 0;

  aux_affichage_simple(root->tree, indent);
}

void aux_affichage_alpha(node_h* nd, char* buff, int buff_size){
  char word[128];
  int word_size = buff_size;

  strcpy(word, buff);

  node_h* inf = get_inf_node(nd);
  node_h* eq = get_eq_node(nd);
  node_h* supp = get_supp_node(nd);

  //printf("buff: %s - lettre: %c\n", buff, get_lettre(nd));

  if( !is_node_null_hybride(inf)){
    //printf("fils inff\n");
    aux_affichage_alpha(inf, buff, buff_size);
  }

  word[word_size] = get_lettre(nd);
  word[word_size+1] = '\0';
  word_size++;

  if(get_key(nd) >= 0){
    printf("- %s\n", word);
  }

  if( !is_node_null_hybride(eq)){
    //printf("fils eq\n");

    aux_affichage_alpha(eq, word, word_size);    
  }

  if( !is_node_null_hybride(supp)){
    //printf("fils supp\n");
    aux_affichage_alpha(supp, buff, buff_size);
  }
}

void affichage_alpha(racine* root){
  if(root == NULL){
    exit_failure("affichage_alpha", "la racine vaut NULL");
  }

  printf("======= affichage de l'arbre ======\n");

  char buff[512];
  buff[0] = '\0';

  aux_affichage_alpha(root->tree,buff, 0);
}
  
