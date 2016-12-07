#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "access.h"
#include "struct.h"
#include "struct_hybride.h"
#include "access_hybride.h"
#include "transfert.h"
#include "util.h"


/*----- fonction don't j'ai besoin ds hybride -----*/

/**
 * fonction qui ajoute un node a droite ou a gauche de n
 **/
void add_in_side(node_h* n, node_h* new_node){
  char lettre_n = get_lettre(n);
  char lettre_new = get_lettre(new_node);
  if(lettre_n < lettre_new){

    if( get_supp_node(n) == NULL){
      set_supp_node(n, new_node);
    }else{
      add_in_side( get_supp_node(n),new_node);
    }

  }else if(lettre_n > lettre_new){
    
    if( get_inf_node(n) == NULL)
      set_inf_node(n, new_node);
    else
      add_in_side( get_inf_node(n),new_node);

  }else{
    exit_failure("add_in_side", "lettre_n = lettre_new");
  } 
}

/*----- FIN: fonction don't j'ai besoin ds hybride -----*/

/*----- fonction don't j'ai besoin ds patricia -----*/

char get_char_zero(node* n){
  char* p = get_prefix(n);
  return p[0]; 
}

/*----- FIN: fonction don't j'ai besoin ds hybride -----*/

/*----- fonctions permettant le passage de patricia a hybride -----*/

node_h* tab_fils_p_to_hybride(node** tf, int* nb_mot);

node_h* mv_node_p_to_hybride(node* p, int* nb_mot){

  int i = 0, prefix_avec_epsilon = 0;
  char* prefix = get_prefix(p);
  node_h *new_node=NULL, *tmp=NULL, *last=NULL;

  while(prefix[i] != '\0'){
    
    if(prefix[i] == EPSILON){
      set_key(last,*nb_mot);
      (*nb_mot)++;
      
      /* maj du marqueur */
      prefix_avec_epsilon = 1;
    }else{
      tmp = creer_noeud_hybride();
      set_lettre(tmp,prefix[i]);
      if(new_node)
	set_eq_node(last,tmp);
      else
	new_node = tmp;
      last = tmp;
    }
    i++;
  }

  
  /* place la cle si tab_fils(p) contient le node EPSILON */
  if(!prefix_avec_epsilon){
    if(!is_node_null( get_fils_node(p,EPSILON) )){
      set_key(last,*nb_mot);
      (*nb_mot)++;
    }

    if(has_childs(p)){
      set_eq_node(last,
		  tab_fils_p_to_hybride(get_tab_fils(p), nb_mot));
    }
  }
 
  return new_node;
}


node_h* tab_fils_p_to_hybride(node** tf, int* nb_mot){
  int i;
  node_h *new_node = NULL, *tmp = NULL;


  /* 2 boucle for identique mais permet d'optimiser le transfert 
     pour avoir un arbre + propre */
  for(i=MOITIE_ALPHA; i<NB_CHAR_MAX; i++){
    if(!is_node_null(tf[i])){
      if(get_char_zero(tf[i]) != EPSILON){
	tmp = mv_node_p_to_hybride(tf[i],nb_mot);
	if(new_node){
	  add_in_side(new_node, tmp);
	}else{
	  new_node = tmp;
	}
      }
    }
  }
  for(i=MOITIE_ALPHA-1; i>=0; i--){
    if(tf[i] != NULL){
      if(get_char_zero(tf[i]) != EPSILON){
	tmp = mv_node_p_to_hybride(tf[i],nb_mot);
	if(new_node){
	  add_in_side(new_node, tmp);
	}else{
	  new_node = tmp;
	}
      }
    }
  }
  return new_node;
}



racine* patricia_to_hybride(node* tree_p){

  racine* tree_h=NULL;
  int nb_mot;

  if(strcmp( get_prefix(tree_p), "") != 0)
    exit_failure("patricia_to_hybride","il faut passer un patrici_tree entier");

  nb_mot = 0;
  tree_h = creer_racine();
  if(!is_node_null(tree_p) && has_childs(tree_p) ){
    tree_h->tree = tab_fils_p_to_hybride(get_tab_fils(tree_p), &nb_mot);
  }

  tree_h->counter = nb_mot;
  return tree_h;
}
    
    
/*-----fonctions permettant le passage de hybride a patricia-----*/
/*
void parcourt(node_h* h, node** tf){

  node_h* l = get_inf_node(l);
  if(is_node_null_hybride(l)){
    


void make_tab_fils(node* p, node_h* h){
  
  node_h *tmp = h, *eq = NULL, *inf=NULL, *supp=NULL;
  node** new_tf = creer_tab_sans_pere();
  int eq_null, inf_null, supp_null, l;

  eq = get_eq_node(h);
  if(is_node_null_hybride(eq))
    eq_null = 1;

  inf = get_inf_node(h);
  if(is_node_null_hybride(inf))
    inf_null = 1;

  supp = get_supp_node(h);
  if(is_node_null_hybride(supp))
    supp_null = 1;

  if(!inf_null || !supp_null){

    while(tmp){
      if(!inf_null)
      if(!eq_null){
	l = (int) get_lettre(h);
	new_tf[l] = make_node_p();
      }
    }
  }else{} // pas de node ds les cote de h 
	




node* hybride_to_patricia(racine* tree_h){

  node* tree_a = NULL;
  
  if(!tree_h)
    exit_failure("hybride_to_patricia","tree_h = NULL");
  if(tree_h->tree == NULL)
    printf("l'arbre a transferer vaut null\n");

  tree_a = creer_noeud();
  make_tab_fils(tree_a, tree_h->tree);

  return tree_a;
}
*/  
