#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "struct_hybride.h"
#include "add_word.h"
#include "calcul_temps.h"


void test_alex(){
  int t_insert_p;
  int t_insert_h;

  node* racine_p = NULL;
  racine* racine_h = NULL;

  char buff[100];
  
  printf("comparaison du temps d'insertion entre patricia et hybride\n\n");
  
  t_insert_p = calcul_insertion_patricia(&racine_p);
  t_insert_h = calcul_insertion_hybride(&racine_h);

  printf("insertion shakespear\n - Patricia: %d ms\n - Hybride: %d ms\n", t_insert_p, t_insert_h);
  getc(stdin);

  printf("intertion d'un mot (non anglais) dans l'arbre contenant tout shakespear\n");

  printf("insertion du mot: bonjour\n");

  t_insert_p = calcul_ajout_mot(racine_p, "bonjour");
  t_insert_h = calcul_ajout_mot_hybride(racine_h, "bonjour");

  printf("insertion \"bonjour\"\n - Patricia: %d µs\n - Hybride: %d µs\n", t_insert_p, t_insert_h);

  printf("Recherche d'un mot dans l'arbre\n");
  printf("Veuillez saisir un mot\n: ");
  fgets(buff, 100, stdin);

  buff[strlen(buff) - 1] = '\0';

  printf("recherche du mot: %s\n", buff);

  t_insert_p = calcul_recherche_mot(racine_p, buff);
  t_insert_h = calcul_recherche_mot_hybride(racine_h, buff);

  printf("recherche de \"%s\"\n - Patricia: %d ms\n - Hybride: %d ms\n",buff, t_insert_p, t_insert_h);

}

  

int main(){
  test_alex();
  return EXIT_SUCCESS;
}
