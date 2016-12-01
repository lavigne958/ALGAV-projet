#include <stdio.h>
#include "struct.h"
#include "access.h"
#include "util.h"

int max_3(int a, int b, int c){
  int m;
  if(a<b)
    m = b;
  else
    m = a;
  if(m < c)
    return c;
  return m;
}
	      
      

int profondeur_sous_arbre(node* n){

  int g=0, m=0, d=0;

  if(is_node_null(get_inf_node(n)) &&
     is_node_null(get_eq_node(n)) &&
     is_node_null(get_supp_node(n)) ){
    return 0;
    
  }else{
  
    if(!is_node_null(get_inf_node(n)))
      g = profondeur_sous_arbre(get_inf_node(n));
    if(!is_node_null(get_supp_node(n)))
      d = profondeur_sous_arbre(get_supp_node(n));
    if(!is_node_null(get_eq_node(n)))
      m = profondeur_sous_arbre(get_eq_node(n));
    
    return 1 + max_3(g,m,d);
  }
}

  



int profondeur_arbre_entier(racine* racine){

  node* n;
  int g=0, m=0, d=0;
  
  printf("1\n");
  if(is_node_null(racine->tree)){
    return -1;
  }else{
    n = racine->tree;
  }
  printf("2\n");
  if( is_node_null(get_inf_node(n)) &&
      is_node_null(get_eq_node(n)) &&
      is_node_null(get_supp_node(n)) ){
    printf("3\n");
    return 0;
    
  }else{
    printf("4\n");
    if(!is_node_null(get_inf_node(n)))
      g = profondeur_sous_arbre(get_inf_node(n));
    if(!is_node_null(get_eq_node(n)))
      m = profondeur_sous_arbre(get_eq_node(n));
    if(!is_node_null(get_supp_node(n)))
      d = profondeur_sous_arbre(get_supp_node(n));

    return 1 + max_3(g,m,d);
  }
}


int profondeur_rotation(node* n){

  int g=0, d=0;

  if(is_node_null(get_inf_node(n)) &&
     is_node_null(get_supp_node(n)) ){
    return 0;
    
  }else{
 
    if(!is_node_null(get_inf_node(n)))
      g = profondeur_sous_arbre(get_inf_node(n));
    if(!is_node_null(get_supp_node(n)))
      d = profondeur_sous_arbre(get_supp_node(n));
    return 1 + max(g,d);
  }
}
  
