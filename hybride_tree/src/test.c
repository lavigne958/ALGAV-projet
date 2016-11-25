#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "struct.h"
#include "access.h"
#include "affiche.h"
#include "insertion.h"
#include "search.h"
#include "parser.h"

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
  /*
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
  */

  printf(" --------- parsing ---------------\n\n");

  words_list* head = read_words("annexe/test.txt");
  words_list* current = head;
  
  if(head == NULL){
    fprintf(stderr, "erreur liste de mots vaut NULL\n");
    exit(EXIT_FAILURE);
  }

  while(current != NULL && current->word != NULL){
    printf("lu: %s\n", current->word);
    if( current == NULL){
      printf("le noeud vaut NUL\n");
    }

    if( current->word == NULL){
      printf("le mot vaut NULL\n");
    }
    
    if( strcmp(current->word, "que") == 0){
      printf("affichage arbre\n");
      affichage_simple(new_root);
      printf("fin affichage\n");
    }
    insert(new_root, current->word);
    current = current->next;
  } 

  printf("fin parsing\n");

  printf("recherche d'un mot existant\n:");
  fgets(mot, 1024, stdin);
  mot[strlen(mot) -1] = '\0';
  
  if( search(new_root, mot)){
    printf(" le mot existe !\n");
  }else{
    printf("le mot n'existe pas.\n");
  }
  return 0;
}
  
