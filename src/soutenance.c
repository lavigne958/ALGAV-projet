#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//------- Patricia ------
#include "struct.h"
#include "access.h"
#include "add_word.h"
#include "affichage.h"
#include "search.h"
#include "supression.h"
#include "fusion.h"

//-------- Hybride ------
#include "struct_hybride.h"
#include "access_hybride.h"
#include "insertion_hybride.h"
#include "affiche_hybride.h"
#include "search_hybride.h"
#include "delete_hybride.h"

void soutenance_insertion(){
  node* root_p =  NULL;
  racine* root_h = NULL;
  char saisie[50];
  
  printf("------ insertion d'un mot dans un arbre patricia ---------\n");
  printf("veuillez saisir un mot: ");
  fgets(saisie, 50, stdin);
  saisie[strlen(saisie)-1] = '\0';

  if(strlen(saisie) <= 0){
    printf("saisie d'un mot vide...\n");
    return;
  }

  root_p = creer_noeud();
  creer_tableau_fils(root_p);
  ajouter_mot(root_p, saisie);

  root_h = creer_racine();
  insert(root_h, saisie);

  printf(" ---------- insertion terminée ----------\n");

  printf("arbre Patricia\n");
  affiche_noeud_simple(root_p);
  printf("====> < ====");
  getc(stdin);

  printf("------------------------------------------------------------\n");

  printf("arbre hybride\n");
  affichage_simple(root_h);
  printf("====> < ====");
  getc(stdin);
}

void soutenance_recherche(){
  FILE* liste;
  int nb_files;
  char** liste_files;
  int i = 0;
  char saisie[50];

  liste = fopen("liste_shakespear.txt", "r");

  fscanf(liste,"%d\n", &nb_files);

  liste_files = (char**) malloc(sizeof(char*) * nb_files);
  
  while(!feof(liste)){
    liste_files[i] = (char*) malloc(sizeof(char) * 100);

    fscanf(liste,"%s ", liste_files[i]);
    i++;
  }

  node* root_p = make_arbre_liste(liste_files, nb_files);
  racine* root_h = make_arbre_liste_hybride(liste_files, nb_files);

  printf("les deux arbres contiennent tout Shakespear\n\n");

  printf("veuillez saisir un mot à rechercher: ");

  fgets(saisie, 50, stdin);
  saisie[strlen(saisie) - 1] = '\0';

  if(strlen(saisie) <= 0){
    printf("le mot saisie est vide...\n");
    return;
  }

  if( recherche_arbre(root_p, saisie)){
    printf(" [Patricia] -- Le mot existe\n");
  }else{
    printf(" [Patricia] -- Le mot n'existe pas\n");
  }

  if( search(root_h, saisie)){
    printf(" [Hybride] -- Le mot existe\n");
  }else{
    printf(" [Hybride] -- Le mot n'existe pas\n");
  }

  printf("====><====");
  getc(stdin);
}

void soutenance_suppression(){
  node* root_p = make_arbre_fichier("soutenance/suppression.txt");
  racine* root_h = make_arbre_fichier_hybride("soutenance/suppression.txt", 1);
  char saisie[50];
  
  printf("affichage des deux arbres\n\n");

  printf(" --------- Patricia ---------\n");
  affichage_racine_alphabetique(root_p);

  printf("\n\n ----------- Hybride ----------\n");
  affichage_alphabetique_hybride(root_h);

  printf("===><===");
  getc(stdin);

  printf("veuillez saisir un mot à supprimer: ");
  fgets(saisie, 50, stdin);
  saisie[strlen(saisie) - 1] = '\0';

  printf("\n\n suppression du mot: %s\n\n", saisie);

  supression(root_p, saisie);
  delete_word(root_h, saisie);

  printf(" --------- Patricia ---------\n");
  affichage_racine_alphabetique(root_p);

  printf("\n\n ----------- Hybride ----------\n");
  affichage_alphabetique_hybride(root_h);
  printf("===><===");
  getc(stdin);
}

void soutenance_fusion(){
  node* root_1_p = make_arbre_fichier("soutenance/fusion_1.txt");
  node* root_2_p = make_arbre_fichier("soutenance/fusion_2.txt");

  printf("----------- fusion de deux arbre Patricia -----------\n\n");

  affichage_racine_alphabetique(root_1_p);
  printf("\n\n");
  affichage_racine_alphabetique(root_2_p);
  printf("===><===");
  getc(stdin);

  root_1_p = fusion(root_1_p, root_2_p);

  printf(" ------- Résultat ------\n");

  affichage_racine_alphabetique(root_1_p);
  printf("===><===");
  getc(stdin);
}

void soutenance_insertion_equilibre(){
  racine* root_unbalanced = make_arbre_fichier_hybride("soutenance/equilibre.txt", 0);
  racine* root_balanced = make_arbre_fichier_hybride("soutenance/equilibre.txt", 1);

  printf(" --------- arbre Hyrbide non équilibré --------\n");

  affichage_simple(root_unbalanced);
  printf("===><===");
  getc(stdin);
  
  printf("\n\n");

  printf(" --------- arbre Hyrbide équilibré --------\n");

  affichage_simple(root_balanced);
  printf("===><===");
  getc(stdin);

}


void soutenance_comptage_mot();

  
void soutenance(){
  int choix;
  int quitter = 0;

  printf(" Dictionaires de mots - ALGAV \n\n");

  while(!quitter){
    printf("veuillez choisir une option parmis: \n");
    printf(" 1 - insertion d'un mot dans les deux arbres\n");
    printf(" 2 - recherche d'un mot dans les deux arbres\n");
    printf(" 3 - suppression d'un mot dans les deux arbres\n");
    printf(" 4 - fusion de deux arbres Patricia\n");
    printf(" 5 - insetion equilibre d'un arbre Hybride\n");
    printf(" 6 - comptage du nombre de mots dans les deux structures\n");
    printf(" 7 - affichage par ordre aphabetique des deux arbres\n");
    printf(" 0 - Quitter\n\n");
    
    printf("choix: ");
    
    scanf("%d", &choix);
    getc(stdin);
   
    switch(choix){
    case 1:
      soutenance_insertion();
      break;
    case 2:
      soutenance_recherche();
      break;
    case 3:
      soutenance_suppression();
      break;
    case 4:
      soutenance_fusion();
      break;
    case 5:
      soutenance_insertion_equilibre();
      break;/*
    case 6:
      soutenance_comptage_mot();
      break;
    case 7:
      soutenance_affichage_alphabetique();
      break;*/
    case 0:
      quitter = 1;
      break;
    default:
      printf("choix inconue... veuillez choisir un valeur entre 0 et 7\n");
    }

    printf("================================================================\n");
  }
}
    
