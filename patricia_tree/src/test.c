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

#define PATH_FICHIER_TEST "./annexe/test.txt"


void test_alex();
int test_ajouter_mot();
void test_make_arbre_fichier();


int main(){


  /* tes tests sont plus bas juste apres le main */
  printf("==================== TEST ALEX =================\n\n");
  test_alex();
  printf("\n\n\n");
  
  /* test ajouter_mot */
  printf("================== TEST HATHEM =================\n\n\n");
  /*
  if(test_ajouter_mot()){
    printf(" ===== test reussi =====\n");
  }

   test make_arbre_fichier */
  //test_make_arbre_fichier();
  

  return 0;
}


void test_alex(){
  node* arbre = creer_noeud();
  creer_tableau_fils(arbre);

  /*
  char fichier[] = {"./annexe/test.txt"};

  words_list* mots = read_words(fichier);
  words_list* head = mots;
  int i;
  if(mots == NULL){
    fprintf(stderr, "erreur liste de mots vaut NULL\n");
    exit(EXIT_FAILURE);
  }

  while(head != NULL && head->word != NULL){
    printf("lu: %s\n", head->word);
    if( head == NULL){
      printf("le noeud vaut NUL\n");
    }

    if( head->word == NULL){
      printf("le mot vaut NULL\n");
    }
    
    if( strcmp(head->word, "que") == 0){
      printf("affichage arbre\n");
      affiche_noeud_simple(arbre);
      printf("fin affichage\n");
    }
    //ajouter_mot(arbre, head->word);
    head = head->next;
  } 

  printf("fin parsing\n");
  */

  node* bon = creer_noeud();
  node* jours = creer_noeud();
  node* he = creer_noeud();
  node* c = creer_noeud();
  node* ho = creer_noeud();
  node* to = creer_noeud();
  node* maman = creer_noeud();

  set_prefix(maman, "maman");
  prefix_add_epsilon(maman);

  set_prefix(to, "to");
  prefix_add_epsilon(to);
  
  set_prefix(ho, "ho");
  prefix_add_epsilon(ho);

  set_prefix(c, "c");
    creer_tableau_fils(c);
  add_epsilon_node(c);
  
  set_prefix(he, "he");
  creer_tableau_fils(he);
  
  set_prefix(bon, "bon");
  creer_tableau_fils(bon);
  add_epsilon_node(bon);
  
  set_prefix(jours, "jour");
  prefix_add_epsilon(jours);

  set_fils_node(arbre, maman, 'm');
  set_fils_node(he, to, 't');
  set_fils_node(c, ho, 'h');
  set_fils_node(he, c, 'c');
  set_fils_node(arbre, he, 'h');
  set_fils_node(bon, jours, 'j');
  set_fils_node(arbre, bon, 'b');
  
  affiche_noeud_simple(arbre);

  printf("comptage du nombre de mots dans l'arbre\n");

  int nb_mots = comptage_mot(arbre);

  printf("%d mots trouvé(s) dans l'arbre\n", nb_mots);
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
