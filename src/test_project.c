#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "struct_hybride.h"
#include "add_word.h"
#include "affichage.h"
#include "affiche_hybride.h"
#include "access.h"
#include "comptage.h"
#include "comptage_hybride.h"
#include "calcul_temps.h"
#include "soutenance.h"
#include "transfert.h"

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

<<<<<<< HEAD
  int prof_p;
  int prof_h;
  
  t_insert_p = calcul_profondeur(racine_p, &prof_p);
  t_insert_h = calcul_profondeur_hybride(racine_h, &prof_h);

  printf("Les profondeurs sont le suivantes:\n");
  printf("- |patricia| = %d\n- |hybride| = %d\n", prof_p, prof_h);
  printf("Temps de calcul:\n - Patricia: %ld ms\n - Hybride: %ld ms\n", t_insert_p / 1000000, t_insert_h / 1000000);
  getc(stdin);
}  

int main(){
  //test_alex();

  soutenance();
=======
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

int main(){
  test_patricia_to_hybride();
  //test_alex();
>>>>>>> 3d987b3983e5055deb9c0cf08b6a34e490bddc33
  return EXIT_SUCCESS;
}
