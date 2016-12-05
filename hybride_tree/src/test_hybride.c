#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "struct_hybride.h"
#include "access_hybride.h"
#include "affiche_hybride.h"
#include "insertion_hybride.h"
#include "search_hybride.h"
#include "parser_hybride.h"
#include "comptage_hybride.h"
#include "delete_hybride.h"
#include "profondeur_hybride.h"
#include "rotation_hybride.h"

void testf(node_h* nd){
  if(nd == NULL){
    printf("nd vaut NULL\n");
    nd = creer_noeud_hybride();
    set_lettre(nd, 't');
  }else{
    printf("nd ne vaut pas NULL\n");
    printf("lettre: %c\n", get_lettre(nd));
  }
}

void test_alex();
void test_hatem_delete();
void test_hatem_profondeur();


int main(){
  test_alex();
  //test_hatem_profondeur();
  
  return 0;
}



void test_alex(){
  char mot[1024];
  printf("création d'une nouvelle racine\n");
  racine* new_root = creer_racine();
  
  printf(" --------- parsing ---------------\n\n");

  words_list* head = read_words("annexe/hamlet.txt");
  words_list* current = head;
  printf(" ======= fin parsing =============\n");
  printf("nouvel arbre equilibre\n");

  racine* balanced_root = creer_racine();

  while(current != NULL && current->word != NULL){
    insert_equilibre(balanced_root, current->word);
    current = current->next;
  }

  affichage_simple(balanced_root);
  getc(stdin);

  printf("fin\n");

  affichage_alpha(balanced_root);

}


void test_hatem_delete(){

  printf("création d'une nouvelle racine\n");
  racine* new_root = creer_racine();

  
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
    
    insert(new_root, current->word);
    current = current->next;
  } 

  printf("fin parsing\n");

  affichage_simple(new_root);
  printf("--------------------------------------------------\n");
  delete_word(new_root,"la");
  delete_word(new_root,"quel");
  affichage_simple(new_root);
  printf("--------------------------------------------------\n");
  

}




void test_hatem_profondeur(){

  printf("création d'une nouvelle racine\n");
  racine* new_root = creer_racine();

  
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
    
    insert(new_root, current->word);
    current = current->next;
  } 

  printf("fin parsing\n");

  printf("profondeur de l'arbre est: %d\n", profondeur_arbre_entier(new_root));
  
}
