#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "util.h"
#include "access.h"


void aux_affichage_simple(node* nr, int indent){
  int i;
  
  printf("%c->", get_lettre(nr));
  
  if( is_node_null(nr->inf) &&
      is_node_null(nr->eq) &&
      is_node_null(nr->supp)){
    return;
  }
  
  if(!is_node_null(nr->supp)){
    aux_affichage_simple(nr->supp, indent+1);
  }
  
  printf("\n");
  
  if(!is_node_null(nr->eq)){
    for(i = 0; i < indent+1; i++){
      printf("   ");
    }
    aux_affichage_simple(nr->eq, indent+1);
  }
  printf("\n");
  
  if(!is_node_null(nr->inf)){
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

void aux_affichage_alpha(node* nd, char* buff, int buff_size){
  char word[128];
  int word_size = buff_size;

  strcpy(word, buff);

  node* inf = get_inf_node(nd);
  node* eq = get_eq_node(nd);
  node* supp = get_supp_node(nd);

  //printf("buff: %s - lettre: %c\n", buff, get_lettre(nd));

  if( !is_node_null(inf)){
    //printf("fils inff\n");
    aux_affichage_alpha(inf, buff, buff_size);
  }

  word[word_size] = get_lettre(nd);
  word[word_size+1] = '\0';
  word_size++;

  if(get_key(nd) >= 0){
    printf("- %s\n", word);
  }

  if( !is_node_null(eq)){
    //printf("fils eq\n");

    aux_affichage_alpha(eq, word, word_size);    
  }

  if( !is_node_null(supp)){
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
  
