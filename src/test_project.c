#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "struct_hybride.h"
#include "add_word.h"
#include "affichage.h"
#include "access.h"
#include "comptage.h"
#include "comptage_hybride.h"
#include "calcul_temps.h"


void test_alex(){
  long t_insert_p;
  long t_insert_h;

  node* racine_p = NULL;
  racine* racine_h = NULL;

  char buff[100];
  
  printf("comparaison du temps d'insertion entre patricia et hybride\n\n");
  
  t_insert_p = calcul_insertion_patricia(&racine_p);
  t_insert_h = calcul_insertion_hybride(&racine_h);

  printf("insertion shakespear\n - Patricia: %ld ms\n - Hybride: %ld ms\n", (t_insert_p / 1000000), (t_insert_h / 1000000));
  printf("nb_mot_patricia = %d\n", comptage_mot(racine_p));
  printf("nb_mot_hybride = %d\n", comptage_hybride(racine_h));
  getc(stdin);

  printf("intertion d'un mot (non anglais) dans l'arbre contenant tout shakespear\n");

  printf("insertion du mot: bonjour\n");

  t_insert_p = calcul_ajout_mot(racine_p, "bonjour");
  t_insert_h = calcul_ajout_mot_hybride(racine_h, "bonjour");

  printf("insertion \"bonjour\"\n - Patricia: %ld nano secondes\n - Hybride: %ld nano secondes\n", t_insert_p, t_insert_h);
  getc(stdin);
  
  printf("Recherche d'un mot dans l'arbre\n");
  printf("Veuillez saisir un mot\n: ");
  fgets(buff, 100, stdin);

  buff[strlen(buff) - 1] = '\0';

  printf("recherche du mot: %s\n", buff);
  /*
  node* n_test =get_fils_node(racine_p, 'h');
  if( n_test == NULL){
    printf("le noeud h vaut NULL");
  }else{
    printf("prefix de n_test: %s\n", get_prefix(n_test));
    n_test = get_fils_node(n_test, 'o');
    printf("prefix de n_test: %s\n", get_prefix(n_test));
    n_test = get_fils_node(n_test, 'n');
    printf("prefix de n_test: %s\n", get_prefix(n_test));
    n_test = get_fils_node(n_test, 'o');
    printf("prefix de n_test: %s\n", get_prefix(n_test));
    n_test = get_fils_node(n_test, 'r');
    if(has_childs(n_test)){
      printf("n_test:r a des fils\n");
    }
    
    printf("prefix de n_test: %s\n", get_prefix(n_test));
    n_test = get_fils_node(n_test, 'i');
    char* prefix_test = get_prefix(n_test);
    int i;
    for(i = 0; i < strlen(prefix_test); i++){
      printf("%x-", prefix_test[i]);
    }

    printf("\n");
  }
  */
  t_insert_p = calcul_recherche_mot(racine_p, buff);
  t_insert_h = calcul_recherche_mot_hybride(racine_h, buff);

  printf("recherche de \"%s\"\n - Patricia: %ld nano secondes\n - Hybride: %ld nano secondes\n",buff, t_insert_p, t_insert_h);

}

  

int main(){
  test_alex();
  return EXIT_SUCCESS;
}
