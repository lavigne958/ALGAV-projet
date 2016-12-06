#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"
#include "search.h"
#include "search.h"
#include "supression.h"
#include "affichage.h"
#include "add_word.h"
#include "parser.h"
#include "comptage.h"
#include "profondeur.h"
#include "clone.h"
#include "free_memory.h"
#include "fusion.h"

#define PATH_FICHIER_TEST "./annexe/test.txt"


void test_alex();
int test_ajouter_mot();
void test_make_arbre_fichier();
void test_hatem_profondeur();
void test_hatem_clone_free();
void test_hatem_fusion();

int main(){

  printf("==================== TEST ALEX =================\n\n");
  test_alex();
  printf("\n\n\n"); 
  
  /* test ajouter_mot */
  printf("================== TEST HATHEM =================\n\n\n");

  /*test_hatem_clone_free();*/
  //test_hatem_fusion();
  
  return 0;
}


void test_alex(){
  /*
  printf("creation de l'arbre\n");
  node* arbre = creer_noeud();
  printf("creation de ses fils\n");
  creer_tableau_fils(arbre);

  
  char fichier[] = {"./annexe/test.txt"};

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

  node* nulls = creer_noeud();
  creer_tableau_fils(nulls);

  int nb_nulls = comptage_null(nulls);

  printf("l'arbre contient %d pointeurs vers null\n", nb_nulls);

  getc(stdin);

  ajouter_mot(nulls, "bonjour");

  nb_nulls = comptage_null(nulls);
  printf("l'arbre contient %d pointeurs vers null\n", nb_nulls);

  ajouter_mot(nulls, "bonto");
  nb_nulls = comptage_null(nulls);
  printf("l'arbre contient %d pointeurs vers null\n", nb_nulls);
  */

  FILE* liste;
  int nb_files;
  char** liste_files;
  int i = 0;
  
  liste = fopen("liste_shakespear.txt", "r");

  fscanf(liste,"%d\n", &nb_files);

  liste_files = (char**) malloc(sizeof(char*) * nb_files);
  
  while(!feof(liste)){
    liste_files[i] = (char*) malloc(sizeof(char) * 100);

    fscanf(liste,"%s ", liste_files[i]);
    i++;
  }
    
  node* racine;

  racine = make_arbre_liste(liste_files, 37);

  nb_files = comptage_mot(racine);

  printf("racine contient: %d mots\n",nb_files);
  getc(stdin);

  affichage_racine_alphabetique(racine);
  
  printf("fin\n");     
}


void test_hatem_fusion(){
  
  node* treeA = make_arbre_fichier("./annexe/for_fusion1.txt");
  /*printf("----- affichage de treeA -----\n");
  affiche_noeud_simple(treeA);  
  */
  printf("\n");
  
  node* treeB = make_arbre_fichier("./annexe/for_fusion2.txt");
  printf("----- affichage de treeB -----\n");
  affiche_noeud_simple(treeB);  
  
  printf("\n");
  
  node* treeAB = fusion(treeA,treeB);
  /*printf("----- affichage de treeAB -----\n");
  affiche_noeud_simple(treeAB);
  c est ok pour ca */

  printf("----- affichage de treeB -----\n");
  affiche_noeud_simple(treeB);  

}



void test_hatem_clone_free(){

  node* tree = make_arbre_fichier(PATH_FICHIER_TEST);
  printf("----- affichage de tree -----\n");
  affiche_noeud_simple(tree);
  node* c = clone(tree);
  printf("----- affichage du clone -----\n");
  affiche_noeud_simple(c);
  printf("----- free clone -----\n");
  free(c);
  if(!c)
    printf("le clone n'existe plus\n");
  else{
    printf("le clone existe toujours\n");
    printf("----- affichage du clone -----\n");
    affiche_noeud_simple(c);
  }
  return;
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
