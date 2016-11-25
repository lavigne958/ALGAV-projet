#include <string.h>
#include <stdio.h>

#include "struct.h"
#include "util.h"
#include "access.h"


/**
 * je sais pas si le node je le laisse si inf_node 
 * ou supp_node !NULL. Tout va dependre de ca 
 * cette fonction renvoie 1 si n vaut NULL 
 * a la fin de cette fonction
 */
int delete_node(node* n, node* father){

  if(father){ /* cas ou le pere n'est pas la racine */


  }else{ /* cas ou le pere est la racine */
  
  } /* fin de cas ou le pere est la racine */
}

int aux_delete_word(node* n, char* word, node* father){

  if( word[0] == get_lettre(n)){
    if( strlen(word) == 1){
      if( get_key(n) != -1){
	if( is_node_null(get_eq_node(n)) ){
	  delete_node(n,father);


  }else{ /* word[0] != get_lettre(tree) */

    
  } /* fin word[0] != get_lettre(tree) */


} /* fin fonction */


int delete_word(racine* racine, char* word){

  if(!word)
    exit_failure("delete_word", "le mot a supprimer vaut NULL");

  if(!racine)
    exit_failure("delete_word", "l'arbre vaut NULL");
  
  if(is_node_null(racine->tree)){       
    return 0;
  }else{
    return aux_delete_word(racine->tree, word, NULL);
  }
}


			    
