#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"
#include "search.h"
#include "search_alex.h"

int main(){
  
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
  printf("nd->fils[A]->prefix: %s\tfilsA->prefix: %s\n",nd->fils['A']->prefix,filsA->prefix);
  
  
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
  set_prefix(filsoaster,"oaster");
  prefix_add_epsilon(filsoaster);
  set_fils_node(filst,filsoaster,'o');
  printf("fils 'oaster' creer\n");
  node* filsester = creer_noeud();
  set_prefix(filsester, "ester");
  prefix_add_epsilon(filsester);
  set_fils_node(filst,filsester,'e');
  
  printf("recherche du mot toaster\n");
  if(recherche_mot(nd,"toaster")){
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
  
  return 0;
}
