#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "access.h"
#include "util.h"
#include "clone.h"
#include "free.h"

    

node* fusion_aux(node* a, node* b){

  int i, ta_null, tb_null, ai_null, bi_null, taille_prefix_commun;
  node *ai, *bi, *fils_b, *fils_a, *new_node, *tmp;
  node **new_tf;
  char* prefix_commun;
  char* reste_a;
  char* reste_b;
  ta_null = !has_childs(a);
  tb_null = !has_childs(b);

  if(strcmp(get_prefix(a),get_prefix(b)) == 0){

    new_node = creer_noeud();
    set_prefix(new_node, get_prefix(a));
    
    /* gestion en fonction des x->tab_fils */
    if(ta_null && !tb_null)
      new_tf = clone_tab_fils(b-> tab_fils);
    if(!ta_null && tb_null)
      new_tf = clone_tab_fils(a-> tab_fils);
    if(!ta_null && !tb_null){
      new_tf = creer_tab_sans_pere();
    
      /* gestion en fonction des x->tab_fils[i] */
      for(i = 0; i < NB_CHAR_MAX; i++){

	if(a->tab_fils[i] != NULL){
	  ai = a->tab_fils[i];
	  ai_null = 0;
	}else
	  ai_null = 1;
      
	if(b->tab_fils[i] != NULL){
	  bi = b->tab_fils[i];
	  bi_null = 0;
	}else
	  bi_null = 1;

	if(ai_null && !bi_null)
	  new_tf[i] = clone(bi);
	if(!ai_null && bi_null)
	  new_tf[i] = clone(ai);
	if(!ai_null && !bi_null)
	  new_tf[i] = fusion_aux(ai,bi);
  
      }

      set_tab_fils(new_node,new_tf);
    }
  }else{

    /* ----- gestion chaines ----- */
    taille_prefix_commun = taille_prefixe_commun(get_prefix(a),
						 get_prefix(b));
    prefix_commun = str_sub(get_prefix(a),0, taille_prefix_commun-1);
    reste_a = str_sub(get_prefix(a),
		      taille_prefix_commun, a->size-1);
    reste_b = str_sub(get_prefix(b),
		      taille_prefix_commun, b->size-1);

    /* creation du new_node */
    new_node = creer_noeud();
    set_prefix(new_node, prefix_commun);
    
    if(!reste_a){ /* forcement pas de EPSILON a la fin de pref(a) */

      /* creation du node avec reste_b */
      fils_b = creer_noeud();
      set_prefix(fils_b, reste_b);
      if(!tb_null)
	set_tab_fils(fils_b, clone_tab_fils(get_tab_fils(b)));

      /* fusion du sous arbre fils_b et du sous arbre a */
      new_tf = clone_tab_fils( get_tab_fils(a) );
      if( new_tf[ (int) reste_b[0] ] == NULL )
	new_tf[ (int) reste_b[0] ] = fils_b;
      else{
	tmp = fusion_aux(fils_b, new_tf[ (int) reste_b[0] ]);
	free_tree(fils_b);
	fils_b = NULL;
	free_tree(new_tf[ (int) reste_b[0] ]);
	new_tf[ (int) reste_b[0] ] = tmp;
      }
      set_tab_fils(new_node,new_tf);

    }else if(!reste_b){

      /* creation du node avec reste_a */
      fils_a = creer_noeud();
      set_prefix(fils_a, reste_a);
      if(!ta_null)
	set_tab_fils(fils_a, clone_tab_fils(get_tab_fils(a)));

      /* fusion du sous arbre fils_a et du sous arbre b */
      new_tf = clone_tab_fils( get_tab_fils(b) );
      if( new_tf[ (int) reste_a[0] ] == NULL )
	new_tf[ (int) reste_a[0] ] = fils_a;
      else{
	tmp = fusion_aux(fils_a, new_tf[ (int) reste_a[0] ]);
	free_tree(fils_a);
	fils_a = NULL;
	free_tree(new_tf[ (int) reste_a[0] ]);
	new_tf[ (int) reste_a[0] ] = tmp;
      }
      set_tab_fils(new_node,new_tf);
      
    }else{

      /* creation du node avec reste_a */
      fils_a = creer_noeud();
      set_prefix(fils_a, reste_a);
      if(!ta_null)
	set_tab_fils(fils_a, clone_tab_fils(get_tab_fils(a)));

      /* creation du node avec reste_b */
      fils_b = creer_noeud();
      set_prefix(fils_b, reste_b);
      if(!tb_null)
	set_tab_fils(fils_b, clone_tab_fils(get_tab_fils(b)));

      new_tf = creer_tab_sans_pere();
      new_tf[(int) reste_a[0] ] = fils_a;
      new_tf[(int) reste_b[0] ] = fils_b;

      set_tab_fils(new_node,new_tf);
    }
  }

  return new_node;
}


node* fusion(node* treeA, node* treeB){

  int a_null, b_null;
  a_null = is_node_null(treeA);
  b_null = is_node_null(treeB);
  
  if( a_null && b_null )
    exit_failure("fusion","les deux arbres sont vide");
  if( strcmp( get_prefix(treeA),"") && strcmp(get_prefix(treeB),""))
    exit_failure("fusion","au moins l'un des arbres est un sous arbre");

  if( a_null )
    return treeB;
  if( b_null)
    return treeA;
  return fusion_aux(treeA,treeB);
  }


  
