#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "struct.h"
#include "access.h"
#include "affiche.h"
#include "insertion.h"
#include "search.h"
#include "parser.h"
#include "comptage.h"
#include "delete.h"
#include "profondeur.h"

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

void test_alex();
void test_hatem_delete();
void test_hatem_profondeur();


int main(){
<<<<<<< HEAD
  test_hatem_profondeur();
=======
  test_alex();
  //test_hatem();
>>>>>>> 2120168a1a2f83f39eea97e66abcd24f9e7e1b01
  return 0;
}



void test_alex(){
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

  words_list* head = read_words("annexe/hamlet.txt");
  words_list* current = head;
  
  if(head == NULL){
    fprintf(stderr, "erreur liste de mots vaut NULL\n");
    exit(EXIT_FAILURE);
  }

  while(current != NULL && current->word != NULL){
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

  printf("recherche d'un mot existant\n:");
  fgets(mot, 1024, stdin);
  mot[strlen(mot) -1] = '\0';
  
  if( search(new_root, mot)){
    printf(" le mot existe !\n");
  }else{
    printf("le mot n'existe pas.\n");
  }

  printf("comptage du nombre de mots dans l'arbre\n");

  int nb_mots = comptage(new_root);

  printf("%d mots dans l'arbre\n", nb_mots);

  printf("combien de suffixes complètes un mot, veuillez saisir un mot\n: ");
  fgets(mot, 1024, stdin);
  mot[strlen(mot) - 1] = '\0';

  nb_mots = comptage_prefix_nb_mots(new_root, mot);

  printf("%s est prefixe de %d mots\n", mot, nb_mots);
  getc(stdin);

  affichage_alpha(new_root);

  return 0;
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
  //delete_word(new_root,"quel");
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
