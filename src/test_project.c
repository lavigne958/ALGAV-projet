#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "struct_hybride.h"
#include "add_word.h"
#include "affichage.h"
#include "affiche_hybride.h"
#include "access.h"
#include "access_hybride.h"
#include "comptage.h"
#include "comptage_hybride.h"
#include "calcul_temps.h"
#include "soutenance.h"
#include "transfert.h"
#include "insertion_hybride.h"
#include "parser_hybride.h"


#define PATH_FICHIER_TEST "./patricia_tree/annexe/test.txt"

void test_alex(){
  long t_insert_p;
  long t_insert_h;

  node* racine_p = NULL;
  racine* racine_h = NULL;

  char buff[100];
  
  printf("comparaison du temps d'insertion entre patricia et hybride\n\n");
  
  t_insert_p = calcul_insertion_patricia(&racine_p);
  t_insert_h = calcul_insertion_hybride(&racine_h);

  printf("insertion shakespear\n - Patricia: %ld ms\n - Hybride: %ld ms\n", t_insert_p / 1000000, t_insert_h / 1000000);
  getc(stdin);

  printf("intertion d'un mot (non anglais) dans l'arbre contenant tout shakespear\n");

  printf("insertion du mot: bonjour\n");

  t_insert_p = calcul_ajout_mot(racine_p, "bonjour");
  t_insert_h = calcul_ajout_mot_hybride(racine_h, "bonjour");

  printf("insertion \"bonjour\"\n - Patricia: %ld ns\n - Hybride: %ld ns\n", t_insert_p, t_insert_h);
  getc(stdin);
  
  printf("Recherche d'un mot dans l'arbre\n");
  printf("Veuillez saisir un mot\n: ");
  fgets(buff, 100, stdin);

  buff[strlen(buff) - 1] = '\0';

  printf("recherche du mot: %s\n", buff);
  
  t_insert_p = calcul_recherche_mot(racine_p, buff);
  t_insert_h = calcul_recherche_mot_hybride(racine_h, buff);

  printf("recherche de \"%s\"\n - Patricia: %ld ns\n - Hybride: %ld ns\n",buff, t_insert_p, t_insert_h);
  getc(stdin);

  printf("Profondeur des deux arbes:\n");

  int prof_p;
  int prof_h;
  
  t_insert_p = calcul_profondeur(racine_p, &prof_p);
  t_insert_h = calcul_profondeur_hybride(racine_h, &prof_h);

  printf("Les profondeurs sont le suivantes:\n");
  printf("- |patricia| = %d\n- |hybride| = %d\n", prof_p, prof_h);
  printf("Temps de calcul:\n - Patricia: %ld ms\n - Hybride: %ld ms\n", t_insert_p / 1000000, t_insert_h / 1000000);
  getc(stdin);
}


void test_patricia_to_hybride(){
  racine* tree_h;
  node* tree_p = make_arbre_fichier(PATH_FICHIER_TEST);
  printf("--------------------------\n");
  affiche_noeud_simple(tree_p);
  printf("--------------------------\n");
  tree_h = patricia_to_hybride(tree_p);
  printf("--------------------------\n");
  affichage_alphabetique_hybride(tree_h);
  
}


void test_hybride_to_patricia(){

  node* tree_p;

  printf("création d'une nouvelle racine\n");
  racine* new_root = creer_racine();  
  printf(" --------- parsing ---------------\n\n");
  words_list* head = read_words(PATH_FICHIER_TEST);
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


  printf("--------------------------\n");
  affichage_alphabetique_hybride(new_root);
  printf("--------------------------\n");
  tree_p = hybride_to_patricia(new_root);
  printf("--------------------------\n");
  affiche_noeud_simple(tree_p);
 


}




int main(){
  //test_patricia_to_hybride();
  //test_hybride_to_patricia();
  //test_alex();
  soutenance();
    
  
  //test_patricia_to_hybride();
  //test_alex();
  return EXIT_SUCCESS;
}
