#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "access.h"
#include "struct.h"
#include "struct_hybride.h"
#include "access_hybride.h"
#include "transfert.h"



/*----- fonction don't j'ai besoin ds hybride -----*/

/**
 * fonction qui ajoute un node a droite ou a gauche de n
 **/
void add_in_side(node_h* n, node_h* new_node){
  int lettre_n = (int) get_lettre(n);
  int lettre_new = (int) get_lettre(new_node);
  
  if(lettre_n < lettre_new){
    
    if( get_supp_node(n) == NULL)
      set_supp_node(n, new_node);
    else
      add_in_side( get_supp_node(n),new_node);
    
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
  int i = 0;
  char* prefix = get_prefix(p);
  node_h *new_node, *tmp, *last;

  while(prefix[i] != '\0'){

    if(prefix[i] == EPSILON){
      set_key(last,*nb_mot);
      (*nb_mot)++;
    }else{
      tmp = creer_noeud_hybride();
      set_lettre(tmp,prefix[i]);
      if(last)
	set_eq_node(last,tmp);
      else
	new_node = tmp;
      last = tmp;
    }
    i++;
  }

  /* place la cle si tab_fils(p) contient le node EPSILON */
  if( !is_node_null(get_fils_node(p,EPSILON)) ){
    set_key(last,*nb_mot);
    (*nb_mot)++;
  }


  if(has_childs(p))
    set_eq_node(last,tab_fils_p_to_hybride(get_tab_fils(p), nb_mot));

  return new_node;
}


node_h* tab_fils_p_to_hybride(node** tf, int* nb_mot){

  int i;
  node_h *new_node, *tmp;

  for(i=MOITIE_ALPHA; i<NB_CHAR_MAX; i++){
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
  for(i=0; i<MOITIE_ALPHA-1; i++){
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

  racine* tree_h;
  int* nb_mot;

  if(strcmp( get_prefix(tree_p), "") == 0)
    exit_failure("patricia_to_hybride","il faut passer un patrici_tree entier");

  *nb_mot = 0;
  tree_h = creer_racine();
  if(!is_node_null(tree_p) && has_childs(tree_p) ){
    tree_h->tree = tab_fils_p_to_hybride(get_tab_fils(tree_p), nb_mot);
  }

  tree_h->counter = *nb_mot;
  return tree_h;
}
    
    
/*-----fonctions permettant le passage de hybride a patricia-----*/   
