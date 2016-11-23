#include <stdio.h>
#include <stdlib.h>


#include "struct.h"
#include "access.h"
#include "affiche.h"
#include "insertion.h"

void testf(node* nd){
  if(nd == NULL){
    printf("nd vaut NULL\n");
    nd = creer_noeud();
    set_lettre(nd, 't');
  }else{
    printf("nd ne vaut pas NULL\n");
    printf("lettre: %c\n", get_lettre(nd));
  }
}

int main(){
  racine* root = creer_racine();
  /*
  node* nl = creer_noeud();
  node* no = creer_noeud();
  node* nu = creer_noeud();
  node* np = creer_noeud();
  node* ns = creer_noeud();
  node* nr = creer_noeud();
  node* nd = creer_noeud();

  set_lettre(nl, 'l');
  set_lettre(no, 'o');
  set_lettre(nu, 'u');
  set_lettre(np, 'p');
  set_lettre(ns, 's');
  set_lettre(nr, 'r');
  set_lettre(nd, 'd');
  
  root->tree = nl;
  set_eq_node(nl, no);
  set_eq_node(no, nu);
  set_eq_node(nu, np);
  set_supp_node(np, nr);
  set_eq_node(nr, nd);
  set_eq_node(np, ns);
  
  affichage_simple(root);
  */

  printf("création d'une nouvelle racine\n");
  racine* new_root = creer_racine();
  printf("insertion du mot: tata\n");
  insert(new_root, "tata");
  insert(new_root, "toto");
  insert(new_root, "the");
  affichage_simple(new_root);
  
  return 0;
}
  
