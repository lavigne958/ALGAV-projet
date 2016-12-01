#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"
#include "search.h"
#include "search_alex.h"
#include "supression.h"
#include "affichage.h"
#include "add_word.h"
#include "parser.h"
#include "comptage.h"
#include "profondeur.h"

#define PATH_FICHIER_TEST "./annexe/test.txt"


void test_alex();
int test_ajouter_mot();
void test_make_arbre_fichier();
void test_hatem_profondeur();

int main(){

  printf("==================== TEST ALEX =================\n\n");
  /* test_alex(); */
  printf("\n\n\n"); 
  
  /* test ajouter_mot */
  printf("================== TEST HATHEM =================\n\n\n");

  test_hatem_profondeur();

  return 0;
}


void test_alex(){
  printf("creation de l'arbre\n");
  node* arbre = creer_noeud();
  printf("creation de ses fils\n");
  creer_tableau_fils(arbre);

  
  char fichier[] = {"./annexe/hamlet.txt"};

  printf("parsing\n");
  words_list* mots = read_words(fichier);
  words_list* head = mots;
  int i;
  
  if(mots == NULL){
    fprintf(stderr, "erreur liste de mots vaut NULL\n");
    exit(EXIT_FAILURE);
  }

  printf("insertion\n");
  while(head != NULL && head->word != NULL){
    if( head == NULL){
      printf("le noeud vaut NUL\n");
    }

    if( head->word == NULL){
      printf("le mot vaut NULL\n");
    }

    printf("insertion de: %s\n", head->word);
    ajouter_mot(arbre, head->word);
    head = head->next;
  } 

  printf("fin parsing\n");

  printf("comptage du nombre de mots dans l'arbre\n");

  int nb_mots = comptage_mot(arbre);

  printf("%d mots trouvé(s) dans l'arbre\n", nb_mots);

  affichage_racine_alphabetique(arbre);

  printf("recherche du nombre de suffixes à partir d'un mot\n: ");
  char saisie[20];
  fgets(saisie, 19, stdin);
  saisie[strlen(saisie)-1] = '\0';

  int nb_suffixes = comptage_prefix_nb_mots(arbre, saisie);

  printf("%s est préfixe de %d mot(s)\n", saisie, nb_suffixes);

  printf("suppression de tout les mot contenu dans le fichier hamlet.txt\n");

  head = mots;

  while(head != NULL && head->word != NULL){
    if(head->word == NULL){
      printf("le mot à supprimet vaut NULL\n");
      continue;
    }
    supression(arbre, head->word);
    head = head->next;
  }

  printf("suppression terminée\n");

  affichage_racine_alphabetique(arbre);
  
  
  printf("fin\n");     
}






int test_ajouter_mot(){
  node* arbre = creer_noeud();
  /* test  */
  if(is_node_null(arbre)){
    printf("arbre n'est pas cree\n");
  }else{
    printf("arbre creer avec succes\n");
  }
  node *n1, *n2, *n3, *n4, *n5, *n6, *n7;
  char* mot1 = "premier";
  char* mot2 = "premiere";
  char* mot3 = "premierement";
  char* mot4 = "prem";
  char* mot5 = "progres";
  char* mot6 = "premieredeux";
  char* mot7 = "pr";

  /* test mot1 */
  printf("\n---- ajout du mot %s ----\n\n",mot1);
  ajouter_mot(arbre,mot1);

  n1 = get_fils_node(arbre,mot1[0]);
  if(!affiche_attribut_node(n1)){
    printf("n1 n existe pas\n");
    return 0;
  }

  /* test mot2 */
  printf("\n---- ajout du mot %s ----\n\n",mot2);
  ajouter_mot(arbre,mot2);
  affiche_attribut_node(n1);
  if( get_fils_node(n1,EPSILON) )
    printf("n1 possede comme fils le node EPSILON\n");
  n2 = get_fils_node(n1,'e');
  if(!affiche_attribut_node(n2)){
    printf("n2 n existe pas\n");
    return 0;
  }

  /* test mot3 */
  printf("\n---- ajout du mot %s ----\n\n",mot3);
  ajouter_mot(arbre,mot3);
  affiche_attribut_node(n1);
  if( get_fils_node(n1,EPSILON) )
    printf("n1 possede comme fils le node EPSILON\n");

  affiche_attribut_node(n2);
  if( get_fils_node(n2,EPSILON) )
    printf("n2 possede comme fils le node EPSILON\n");
 
  n3 = get_fils_node(n2,'m');
  if(!affiche_attribut_node(n3)){
    printf("n3 n existe pas\n");
    return 0;
  }
  
  /* test mot4 */
  printf("\n---- ajout du mot %s ----\n\n",mot4);
  ajouter_mot(arbre,mot4);
  affiche_attribut_node(n1);
  if( get_fils_node(n1,EPSILON) )
    printf("n1 possede comme fils le node EPSILON\n");


  n4 = get_fils_node(n1,'i');
  if(!affiche_attribut_node(n4)){
    printf("n4 n existe pas\n");
    return 0;
  }
  if( get_fils_node(n4,EPSILON) )
    printf("n4 possede comme fils le node EPSILON\n");

  affiche_attribut_node(n2);
  if( get_fils_node(n2,EPSILON) )
    printf("n2 possede comme fils le node EPSILON\n");

  affiche_attribut_node(n3);

  /* test mot5 */
  printf("\n---- ajout du mot %s ----\n\n",mot5);
  ajouter_mot(arbre,mot5);

  
  affiche_attribut_node(n1);
  if( get_fils_node(n1,EPSILON) )
    printf("n1 possede comme fils le node EPSILON\n");

  n5 = get_fils_node(n1,'o');
  if(!affiche_attribut_node(n5)){
    printf("n5 n existe pas\n");
    return 0;
  }

  n6 = get_fils_node(n1,'e');
  if(!affiche_attribut_node(n6)){
    printf("n6 n existe pas\n");
    return 0;
  }
  if( get_fils_node(n6,EPSILON) )
    printf("n6 possede comme fils le node EPSILON\n");

  if(!affiche_attribut_node(n4)){
    printf("n4 n existe pas\n");
    return 0;
  }
  if( get_fils_node(n4,EPSILON) )
    printf("n4 possede comme fils le node EPSILON\n");

  affiche_attribut_node(n2);
  if( get_fils_node(n2,EPSILON) )
    printf("n2 possede comme fils le node EPSILON\n");

  affiche_attribut_node(n3);


  /* test mot6 */
  printf("\n---- ajout du mot %s ----\n\n",mot6);
  ajouter_mot(arbre,mot6);

  
  affiche_attribut_node(n1);
  if( get_fils_node(n1,EPSILON) )
    printf("n1 possede comme fils le node EPSILON\n");


  if(!affiche_attribut_node(n5)){
    printf("n5 n existe pas\n");
    return 0;
  }

  if(!affiche_attribut_node(n6)){
    printf("n6 n existe pas\n");
    return 0;
  }
  if( get_fils_node(n6,EPSILON) )
    printf("n6 possede comme fils le node EPSILON\n");

  if(!affiche_attribut_node(n4)){
    printf("n4 n existe pas\n");
    return 0;
  }
  if( get_fils_node(n4,EPSILON) )
    printf("n4 possede comme fils le node EPSILON\n");

  affiche_attribut_node(n2);
  if( get_fils_node(n2,EPSILON) )
    printf("n2 possede comme fils le node EPSILON\n");
  
  n7 = get_fils_node(n2,'d');
  if(!affiche_attribut_node(n7)){
    printf("n7 n existe pas\n");
    return 0;
  }else{
    printf("c'etait n7\n");
  }
  
  affiche_attribut_node(n3);

  /* test mot7 */
  printf("\n---- ajout du mot %s ----\n\n",mot7);
  ajouter_mot(arbre,mot7);

  
  affiche_attribut_node(n1);
  if( get_fils_node(n1,EPSILON) )
    printf("n1 possede comme fils le node EPSILON\n");


  if(!affiche_attribut_node(n5)){
    printf("n5 n existe pas\n");
    return 0;
  }

  if(!affiche_attribut_node(n6)){
    printf("n6 n existe pas\n");
    return 0;
  }
  if( get_fils_node(n6,EPSILON) )
    printf("n6 possede comme fils le node EPSILON\n");

  if(!affiche_attribut_node(n4)){
    printf("n4 n existe pas\n");
    return 0;
  }
  if( get_fils_node(n4,EPSILON) )
    printf("n4 possede comme fils le node EPSILON\n");

  affiche_attribut_node(n2);
  if( get_fils_node(n2,EPSILON) )
    printf("n2 possede comme fils le node EPSILON\n");
  
  if(!affiche_attribut_node(n7)){
    printf("n7 n existe pas\n");
    return 0;
  }else{
    printf("c'etait n7\n");
  }
  
  affiche_attribut_node(n3);
  
  affiche_noeud_simple(arbre);

  return 1;
}


void test_make_arbre_fichier(){
  node* tree = make_arbre_fichier(PATH_FICHIER_TEST);
  affiche_noeud_simple(tree);
  return;
}


void test_hatem_profondeur(){
  node* tree = make_arbre_fichier(PATH_FICHIER_TEST);
  affiche_noeud_simple(tree);
  printf("profondeur: %d\n",profondeur_arbre_entier(tree));
}
