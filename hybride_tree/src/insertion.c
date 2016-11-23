#include <string.h>
#include <stdio.h>

#include "struct.h"
#include "util.h"
#include "access.h"

node* aux_insert(node* nd, char* mot, int val){
  if(is_node_null(nd)){
    printf("le noeud vaut NULL, donc création d'un noeud\n");
    nd = creer_noeud();
    set_lettre(nd, mot[0]);
    if(strlen(mot) == 1){
      printf("il ne reste plus qu'un char, fin d'insertion\n");
      set_key(nd, val);
      return nd;
    }else{
      printf("il reste plusieur char à ajouter\n");
      char* sub_str = &mot[1];
      set_eq_node(nd, aux_insert(get_eq_node(nd), sub_str, val));
      return nd;
    }
  }else{
    char lettre = get_lettre(nd);
    printf("le noeud ne vaut pas null, verification ou ajouter (eq, inf, supp) lettre: %c\n", lettre);
    if( strlen(mot) == 1){
      printf("il ne reste qu'un char à ajouter\n");
      if(mot[0] == lettre){
	printf("insertion d'un mot qui existe déjà\n");
	return NULL;
      }else if(mot[0] < lettre){
	printf("%c < %c insertion dans inff\n", mot[0], lettre);
	node* ndd = creer_noeud();
	set_lettre(ndd, mot[0]);
	set_key(ndd, val);
	set_inf_node(nd, ndd);
	return nd;
      }else{
	printf("%c > %c insertion dans supp\n", mot[0], lettre);
	node* ndd = creer_noeud();
	set_lettre(ndd, mot[0]);
	set_key(ndd, val);
	set_supp_node(nd, ndd);
	return nd;
      }
    }else{
      if(mot[0] == lettre){
	printf("%c == %c insertion dans eq\n", mot[0], lettre);
	char* sub_str = &mot[1];
	set_eq_node(nd, aux_insert(get_eq_node(nd), sub_str, val));
	return nd;
      }else if(mot[0] > lettre){
	printf("%c > %c insertion dans supp\n", mot[0], lettre);
	set_supp_node(nd, aux_insert(get_supp_node(nd), mot, val));
	return nd;
      }else{
	printf("%c < %c insertion dans inff\n", mot[0], lettre);
	set_inf_node(nd, aux_insert(get_inf_node(nd), mot, val));
	return nd;
      }
    }
  }
}

void insert(racine* root, char* mot){
  if(root == NULL){
    exit_failure("insert", "racine vaut NULL");
  }

  if(is_node_null(root->tree)){
    printf("le noeud à la racine vaut NULL\n");
    root->tree = creer_noeud();
    set_lettre(root->tree, mot[0]);
  }

  printf("insertion du mot: %s\n", mot);
  root->tree = aux_insert(root->tree, mot, root->counter++);
}
