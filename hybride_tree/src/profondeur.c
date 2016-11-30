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
  
  if(!is_node_null(get_inf_node(n)))
    g = profondeur_sous_arbre(get_inf_node(n));
  if(!is_node_null(get_supp_node(n)))
    d = profondeur_sous_arbre(get_supp_node(n));
  if(!is_node_null(get_eq_node(n)))
    m = profondeur_sous_arbre(get_eq_node(n));

  return 1 + max_3(g,m,d);
}

  



int profondeur_arbre_entier(racine* racine){

  if(racine){

    if(is_node_null(racine->tree)){
      return -1;
    }else{
      //si les 3 fils de la racine sont NULL alors hauteur 0
      node* inf = get_inf_node(racine->tree);
      node* eq = get_eq_node(racine->tree);
      node* supp = get_supp_node(racine->tree);
      
      if( is_node_null(inf) && is_node_null(eq) && is_node_null(supp)){
	return 0;
      }else{
	//sinon calcul de la hauteur
	return (profondeur_sous_arbre(racine->tree) - 1);
      }
    }
  }else{
    exit_failure("profondeur_sous_arbre","l'arbre n'existe pas");
    return -10;
  }
}
