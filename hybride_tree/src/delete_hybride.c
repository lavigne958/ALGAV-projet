#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "struct_hybride.h"
#include "util_hybride.h"
#include "access_hybride.h"

/**
 * renvoi le node le plus a droite
 **/
node_h* get_extrem_droite(node_h* n){
  if( is_node_null_hybride(get_supp_node(n))){
    return n;
  }else{
    return get_extrem_droite(get_supp_node(n));
  }
}

/**
 * soit 2 node_h* tel que n fils de father
 * retourne 1 si n est le fils gauche, 
 * -1 si n est le fils droit,
 * 0 si n est le fils du milieu
 * exit sinon
 **/
int side_son(node_h* n, node_h* father){  
  if( is_node_null_hybride(n) )
    exit_failure("side_son", "n vaut NULL");
  if( is_node_null_hybride(father) )
    exit_failure("side_son", "father vaut NULL");
  if( get_inf_node(father) == n)
    return -1;
  else if(get_supp_node(father) == n)
    return 1;
  else if(get_eq_node(father) == n)
    return 0;
  else
    exit_failure("side_son", "father n'es pas le pere de n");  
  return -10;
}








int delete_node(node_h* n, node_h* father, int can_remove){
  int side, fg_null, fd_null;
  node_h *gauche, *droit, *min;
  printf("entree delete_node\n");
  if(can_remove == -1){
    /*dans ce cas, on doit determiner si on peut supprimer le node_h*/
    if(is_node_null_hybride(get_eq_node(n)))
      can_remove = 1;
    else
      can_remove = 0;
  }

  printf("can remove = %d\n",can_remove);
  printf("lettre(n) = %c\n",get_lettre(n));
  if(!can_remove)
    return 0;
  else{ /* on peut effacer */
    
    /* initialistation des variables */
    fg_null = is_node_null_hybride(get_inf_node(n));
    if(!fg_null)
      gauche = get_inf_node(n);
    fd_null = is_node_null_hybride(get_supp_node(n));
    if(!fd_null)
      droit = get_supp_node(n);

    if(!father){ /* le pere est la racine */
      if(fg_null && fd_null){
	free(n);
	return 1;

      }else if(!fg_null && fd_null){ 
	set_key(n,get_key(gauche));
	set_lettre(n,get_lettre(gauche));
	if( !is_node_null_hybride(get_inf_node(gauche)))
	  set_inf_node(n,get_inf_node(gauche));
	if( !is_node_null_hybride(get_supp_node(gauche)))
	  set_supp_node(n,get_supp_node(gauche));
	if( !is_node_null_hybride(get_eq_node(gauche)))
	  set_eq_node(n,get_eq_node(gauche));
	free(gauche);
	return 0;
	
      }else if(fg_null && !fd_null){ /* fg_null && !fd_null */
	set_key(n,get_key(droit));
	set_lettre(n,get_lettre(droit));
	if( !is_node_null_hybride(get_inf_node(droit)))
	  set_inf_node(n,get_inf_node(droit));
	if( !is_node_null_hybride(get_supp_node(droit)))
	  set_supp_node(n,get_supp_node(droit));
	if( !is_node_null_hybride(get_eq_node(droit)))
	  set_eq_node(n,get_eq_node(droit));
	free(droit);
	return 0;
	
      }else{ /* !fg_null && !fd_null */
	min = get_extrem_droite(gauche);
	set_inf_node(min,droit);

	set_key(n,get_key(gauche));
	set_lettre(n,get_lettre(gauche));
	if( !is_node_null_hybride(get_inf_node(gauche)))
	  set_inf_node(n,get_inf_node(gauche));
	if( !is_node_null_hybride(get_supp_node(gauche)))
	  set_supp_node(n,get_supp_node(gauche));
	if( !is_node_null_hybride(get_eq_node(gauche)))
	  set_eq_node(n,get_eq_node(gauche));
	free(gauche);
	return 0;

      } /* fin !fg_null && !fd_null */    
    }else{ /* un autre node est le pere */
      /* pour savoir quel pointeur du pere va s'attacher
	 a notre nouveau node */
      side = side_son(n, father);
      
      if(fg_null && fd_null){	
	free(n);
	if(side == 1){
	  father->supp = NULL;
	}else if(side == -1){
	  father->inf = NULL;
	}else{
	  father->eq = NULL;
	}
	return 1;

      }else if(fg_null && !fd_null){
	if(side == 1){
	  set_supp_node(father, get_supp_node(n));
	}else if(side == -1){
	  set_inf_node(father, get_supp_node(n));
	}else{
	  set_eq_node(father, get_supp_node(n));
	}
	free(n);
	return 0;
	
      }else if(!fg_null && fd_null){
	if(side == 1){
	  set_supp_node(father, get_inf_node(n));
	}else if(side == -1){
	  set_inf_node(father, get_inf_node(n));
	}else{
	  set_eq_node(father, get_inf_node(n));
	}
	free(n);
	return 0;
	
      }else{ /* !fg_null && !fd_null */
	min = get_extrem_droite(gauche);
	set_supp_node(min,droit);
	if(side == 1){
	  set_supp_node(father,gauche);	  
	}else if(side == -1){
	  set_inf_node(father,gauche);
	}else{
	  set_eq_node(father,gauche);
	}
	free(n);
	return 0;
	
      } /* fin fg_null && fd_null */
    } /* fin un autre node est le pere */
  } /* fin on peut effacer */
} /* fin fonction */
  
  
int aux_delete_word(node_h* n, char* word, node_h* father){
  printf("entree aux_delete_word: %s\n",word);
  /*
    marqueur = 1  => autorisation de supprimer le pere
    marqueur = 0  => interdiction de supprimer le pere
    marqueur = -1  => droit a determiner
  */
  int marqueur;
  
  if( word[0] == get_lettre(n)){
    printf("1\n");
    
    if( strlen(word) == 1){ /* taille_mot = 1 */
      printf("1.1\n");

      if( get_key(n) != -1){
	printf("1.1.1\n");
	
	set_key(n, -1);
	return delete_node(n,father,-1);
      }else{ /* cle != -1 */
	
	exit_failure("aux_delete_word","cle=-1 et pas de fils"); 
      }
    }else{ /* taille_mot != 1 */
      printf("1.2\n");

      if( is_node_null_hybride(get_eq_node(n)) ){
	printf("1.2.1\n");
	
	return 0;
      }else{
	printf("1.2.2\n");
	
	marqueur = aux_delete_word(get_eq_node(n), &word[1], n);
	if(get_key(n) != -1){
	  printf("on rentre ici\n");
	  marqueur = 0;
	}else{
	  printf("lettre = -1 aparemment\n");
	}
	marqueur = delete_node(n, father, marqueur);
	return marqueur;
      }
    } /* fin taille_mot != 1 */
    
    
  }else if(word[0] < get_lettre(n) ){ /* word[0] != get_lettre(n) */
      printf("2\n");
    if( is_node_null_hybride(get_inf_node(n)) ){
      printf("2.1\n");

      return 0;
    }else{
      printf("2.2\n");

      marqueur = aux_delete_word(get_inf_node(n), word, n);
      return 0;
    }
  }else{
    printf("3\n");
    
    if( is_node_null_hybride(get_supp_node(n)) ){
      printf("3.1\n");
      
      return 0;
    }else{
      printf("3.2\n");
      
      marqueur = aux_delete_word(get_supp_node(n), word, n);
      return 0;
    }
  }
  return -10;
} /* fin fonction */


int delete_word(racine* racine, char* word){
  printf("entree delete_word\n");
  if(!word)
    exit_failure("delete_word", "le mot a supprimer vaut NULL");

  if(!racine)
    exit_failure("delete_word", "l'arbre vaut NULL");

  if(is_node_null_hybride(racine->tree)){       
    return 0;
  }else{
    return aux_delete_word(racine->tree, word, NULL);
  }
}



