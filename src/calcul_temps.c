#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "util.h"
#include "struct.h"
#include "access.h"
#include "add_word.h"
#include "search.h"
#include "profondeur.h"

#include "struct_hybride.h"
#include "access_hybride.h"
#include "insertion_hybride.h"
#include "search_hybride.h"
#include "profondeur_hybride.h"

long get_time(){
  
  struct timespec temps;

  clock_gettime(CLOCK_MONOTONIC, &temps);

  return (temps.tv_sec * 1000000000) + temps.tv_nsec;
  
}
  
int calcul_insertion_patricia(node** racine_p){
  printf("creation d'un arbre patricia contenant tout le dictionnaire de Shakespear...\n");
  
  FILE* liste;
  int nb_files;
  char** liste_files;
  int i = 0;
  long before, after;

  liste = fopen("liste_shakespear.txt", "r");

  fscanf(liste,"%d\n", &nb_files);

  liste_files = (char**) malloc(sizeof(char*) * nb_files);
  
  while(!feof(liste)){
    liste_files[i] = (char*) malloc(sizeof(char) * 100);

    fscanf(liste,"%s ", liste_files[i]);
    i++;
  }

  before = get_time();
  
  *racine_p = make_arbre_liste(liste_files, 37);

  after = get_time();

  long res = (after - before ) ;

  return res;
}

int calcul_insertion_hybride(racine** racine_h){
  printf("creation d'un arbre hybride contenant tout le dictionnaire de Shakespear...\n");
  
  FILE* liste;
  int nb_files;
  char** liste_files;
  int i = 0;
  long before, after;

  liste = fopen("liste_shakespear.txt", "r");

  fscanf(liste,"%d\n", &nb_files);

  liste_files = (char**) malloc(sizeof(char*) * nb_files);
  
  while(!feof(liste)){
    liste_files[i] = (char*) malloc(sizeof(char) * 100);

    fscanf(liste,"%s ", liste_files[i]);
    i++;
  }
  
  before = get_time();
  
  *racine_h = make_arbre_liste_hybride(liste_files, 37);

  after = get_time();

  long res = (after - before );

  return res;
}

int calcul_ajout_mot(node* root, char* mot){
  long before, after;

  if(is_node_null(root)){
    exit_failure("calcul_ajout_mot", "la racine vaut null");
  }

  before = get_time();

  ajouter_mot(root, mot);

  after = get_time();

  return after - before;
}

int calcul_ajout_mot_hybride(racine* root, char* mot){
  long before, after;

  if( root == NULL){
    exit_failure("calcul_ajout_mot", "la racine vaut null");
  }

  before = get_time();

  insert_equilibre(root, mot);

  after = get_time();

  return after - before;
}

int calcul_recherche_mot(node* root, char* mot){
  long before, after;
  int res;
  
  if( root == NULL){
    exit_failure("calcul_ajout_mot", "la racine vaut null");
  }
  
  before = get_time();

  res = recherche_arbre(root, mot); 

  after = get_time();
  
  if( res == 1 || res == -1){
    printf("(patricia) le mot existe\n");
  }else{
    printf("(patricia) le mot n'existe pas\n");
  }

  return after - before;
}

int calcul_recherche_mot_hybride(racine* root, char* mot){
  long before, after;
  int res;
  
  if( root == NULL){
    exit_failure("calcul_ajout_mot", "la racine vaut null");
  }
  
  before = get_time();

  res = search(root, mot); 

  after = get_time();
  
  if( res == 1){
    printf("(hybride) le mot existe\n");
  }else{
    printf("(hybride) le mot n'existe pas\n");
  }

  return after - before;
}

int calcul_profondeur(node* root, int* profondeur){
  long before, after;
  
  if(is_node_null(root)){
    exit_failure("calcul_profondeur", "la racin vaut NULL");
  }

  before = get_time();

  *profondeur = profondeur_arbre_entier(root);

  after = get_time();

  return after - before;
}

int calcul_profondeur_hybride(racine* root, int* profondeur){
  long before, after;

  before = get_time();

  *profondeur = profondeur_arbre_entier_hybride(root);

  after = get_time();

  return after - before;
}
