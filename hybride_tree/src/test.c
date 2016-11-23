#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "struct.h"
#include "access.h"
#include "affiche.h"
#include "insertion.h"
#include "search.h"

void testf(node* nd){
  if(nd == NULL){
    printf("nd vaut NULL\n");
    nd = creer_noeud();
    set_lettre(nd, 't');
  }else{
    printf("nd ne vaut pas NULL\n");
    printf("lettre: %c\n", get_lettre(nd));
  }
}

int main(){
  char mot[1024];
  printf("création d'une nouvelle racine\n");
  racine* new_root = creer_racine();
  printf("insertion du mot: tata\n");
  insert(new_root, "tata");
  insert(new_root, "toto");
  insert(new_root, "the");
  insert(new_root, "tb");
  insert(new_root, "tba");
  
  affichage_simple(new_root);

  printf("recherche d'un mot dans l'arbre\n: ");
  fgets(mot, 1024, stdin);
  mot[strlen(mot)-1] = '\0';
  int res = search(new_root, mot);

  if( res ){
    printf("le mot existe\n");
  }else{
    printf("le mot n'existe pas\n");
  }
  
  return 0;
}
  
