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




#define PATH_FICHIER_TEST "./annexe/test.txt"


void test_alex();
int test_ajouter_mot();
void test_make_arbre_fichier();


int main(){


  /* tes tests sont plus bas juste apres le main */
  test_alex();

  
  /* test ajouter_mot */
  if(test_ajouter_mot()){
    printf(" ===== test reussi =====\n");
  }

  /* test make_arbre_fichier */
  test_make_arbre_fichier();
  

  return 0;
}


void test_alex(){



    printf("creation structure\n");
  
  node* nd = creer_noeud();
  
  printf("le noeud est initialement vide %s\n",nd->prefix);
  
  strcpy(nd->prefix,"test phrase");
  
  printf("préfixe de racine: %s\n",nd->prefix);
  
  creer_tableau_fils(nd);
  
  
  node* filsA = get_fils_node(nd,'A');
  if(filsA == NULL){
    filsA = creer_noeud();
    set_fils_node(nd,filsA,'A');
  }
  
  filsA = get_fils_node(nd,'A');
  
  set_prefix(filsA,"BBB");
  
  printf("test des liens (pointeurs)\n");
  printf("nd->fils[A]->prefix: %s\tfilsA->prefix: %s\n",nd->tab_fils['A']->prefix,filsA->prefix);
  
  
  nd = creer_noeud();
  creer_tableau_fils(nd);
  printf("racine creer\n");
  node* filst = get_fils_node(nd,'t');
  filst = creer_noeud();
  creer_tableau_fils(filst);
  set_prefix(filst,"t");
  set_fils_node(nd,filst,'t');
  printf("fils 't' creer\n");
  node* filsoaster = creer_noeud();
  set_prefix(filsoaster,"oast");
  creer_tableau_fils(filsoaster);
  add_epsilon_node(filsoaster);
  node* er = creer_noeud();
  set_prefix(er, "er");
  prefix_add_epsilon(er);
  set_fils_node(filsoaster, er, 'e');
  set_fils_node(filst,filsoaster,'o');
  printf("fils 'oaster' creer\n");
  node* filsester = creer_noeud();
  set_prefix(filsester, "ester");
  prefix_add_epsilon(filsester);
  set_fils_node(filst,filsester,'e');
  
  printf("recherche du mot toaster\n");
  /* if(recherche_mot(nd,"toaster")){ */
  if(search_word(nd,"toaster")){
  printf("mot trouvé\n");
  }else{
    printf("pas trouvé\n");
  }

  if(recherche_arbre(nd,"toaster")){
    printf("alex à trouver\n");
  }else{
    printf("alex à pas trouvé\n");
  }

  if(recherche_arbre(nd,"tester")){
    printf("alex à trouvé tester\n");
  }else{
    printf("alex à pas trouvé tester\n");
  }

  printf("nd: %s->%s\n",get_prefix(get_fils_node(nd,'t')),get_prefix(get_fils_node(get_fils_node(nd,'t'),'o')));

  printf("arbre avant suppression:\n");
  affiche_noeud_simple(nd);
  
  printf("test de suppression dans l'arbre\n");

  int res = supression(nd, "toast");

  printf("suppresion: %d\n", res);

  affiche_noeud_simple(nd);
 

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
