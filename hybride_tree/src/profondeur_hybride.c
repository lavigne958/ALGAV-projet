#include <stdio.h>

#include "struct_hybride.h"
#include "access_hybride.h"
#include "util_hybride.h"


/**
 * retourner le plus grend nombre entre les 3 entier passer
 * en parametre
 **/
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
	      
      

int profondeur_sous_arbre_hybride(node_h* n){

  int g=0, m=0, d=0;

  if(is_node_null_hybride(get_inf_node(n)) &&
     is_node_null_hybride(get_eq_node(n)) &&
     is_node_null_hybride(get_supp_node(n)) ){
    return 0;
    
  }else{
  
    if(!is_node_null_hybride(get_inf_node(n)))
      g = profondeur_sous_arbre_hybride(get_inf_node(n));
    if(!is_node_null_hybride(get_supp_node(n)))
      d = profondeur_sous_arbre_hybride(get_supp_node(n));
    if(!is_node_null_hybride(get_eq_node(n)))
      m = profondeur_sous_arbre_hybride(get_eq_node(n));
    
    return 1 + max_3(g,m,d);
  }
}

  



int profondeur_arbre_entier_hybride(racine* racine){

  node_h* n;
  int g=0, m=0, d=0;
  
  if(is_node_null_hybride(racine->tree)){
    return -1;
  }else{
    n = racine->tree;
  }
  
  if( is_node_null_hybride(get_inf_node(n)) &&
      is_node_null_hybride(get_eq_node(n)) &&
      is_node_null_hybride(get_supp_node(n)) ){
    return 0;
    
  }else{
    if(!is_node_null_hybride(get_inf_node(n)))
      g = profondeur_sous_arbre_hybride(get_inf_node(n));
    if(!is_node_null_hybride(get_eq_node(n)))
      m = profondeur_sous_arbre_hybride(get_eq_node(n));
    if(!is_node_null_hybride(get_supp_node(n)))
      d = profondeur_sous_arbre_hybride(get_supp_node(n));

    return 1 + max_3(g,m,d);
  }
}



int profondeur_rotation(node_h* n){
  
  if( is_node_null_hybride(n)){
    return -1;
  }else{
    node_h* inf = get_inf_node(n);
    node_h* supp = get_supp_node(n);
    return 1 + max(profondeur_rotation(inf), profondeur_rotation(supp));
  }
}
  

