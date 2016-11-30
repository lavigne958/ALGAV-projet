#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "access.h"
#include "util.h"

//recursive function that finds and delete a string in the dictionary
int aux_supression(node* nd, char* mot){
  //terminal case: if we found the string
  char prefix[NB_CHAR_MAX];
  int pref_size;

  strcpy( prefix, get_prefix(nd));
  printf("noeud: %s - size: %d - mot: %s\n", get_prefix(nd), nd->size, mot);

  if( prefix_has_epsilon(nd)){
    printf("has epsilon\n");
    pref_size = nd->size - 1;
    prefix[pref_size] = '\0';
  }else{
    pref_size = nd->size;
  }
    
  if( strcmp(prefix, mot) == 0 ){
    printf("le mot %s a ete trouver\n", mot);
    //if the string has epsilon, it has no child we just return 1 to delete the node
    if( prefix_has_epsilon(nd)){
      printf("le prefix contient epsilon a la fin\n");
      return 1;
      //if the node has epsilon in its child
    }else if( node_has_epsilon(nd)){
      printf("le noeud a un fils epsilon \n");
      int nb_fils = get_nb_fils(nd);

      //if it has more than on child we just delete the epsilon child entry
      if(nb_fils > 2){
	printf("le noeud a supprimer contient plus d'un fils\n");
	free(nd->tab_fils[EPSILON]);
	nd->tab_fils[EPSILON] = NULL;
	//if it has only one child we append the childj
      }else if( nb_fils == 2){
	printf("le noeud a 1 fils (+ EPSILON)\n");
	int i = 0;
	int pos = -1;
	//look for the position of the only child
	while(i < NB_CHAR_MAX || pos == -1){
	  if(nd->tab_fils[i] != NULL && nd->tab_fils[i]->prefix[0] != EPSILON){
	    pos = i;
	  }
	  i++;
	}

	return (long)nd->tab_fils[pos];
      }

      //return 0 so we stop deleteting in chain the nodes
      return 0;
    }
    printf("prefix = mot (%s), epsilon non present\n", prefix);
    return -1;
    
  }else{
    printf("prefix != mot a supprimer\n");
    //check if prefix and mot have common letters
    int common_prefix = taille_prefixe_commun(mot, nd->prefix);
    printf("prefix commun : %d\n", common_prefix);
    if(strlen(mot) <= (unsigned int)nd->size || common_prefix < nd->size){
      printf("%s <= %s ou common_prefix (%d) < pref (%d)\n", mot, get_prefix(nd), common_prefix, nd->size);
      return -1;
    }else{
      char* sub_str = &mot[common_prefix];
      node* fils = get_fils_node(nd, sub_str[0]);

      if( is_node_null(fils)){
	printf("le fils vaut NULL, suppresion imposible");
	return -1;
      }

      printf("prefix commun, sub_str: %s\n", sub_str);
      int supp = aux_supression(fils, sub_str);
      if( supp == 1){
	printf("aux_ return 1\n");
	int i;
	int nb_fils = 0;
	int last_fils = -1;
	for(i = 0; i < NB_CHAR_MAX; i++){
	  if(nd->tab_fils[i] != NULL){
	    nb_fils++;
	    //conservation de l'index du dernier fils au cas ou il n'y en as qu'un seul
	    last_fils = i;
	  }
	}

	printf("il y a %d fils, le dernier est %c\n", nb_fils, (char)last_fils);

	//-- cas impossible il me semble --
	if( nb_fils == 1){
	  printf("il y a 1 fils\n");
	  sprintf(nd->tab_fils[last_fils]->prefix, "%s%s", get_prefix(nd),
		  get_prefix(nd->tab_fils[last_fils]));
	  nd->size = strlen(nd->tab_fils[last_fils]->prefix);
	  node* del_node = nd;
	  free(del_node);
	//---------------------------------
	}else{
	  printf("il y a plus de fils\n");
	  int index_fils = (int) sub_str[0];
	  nd->tab_fils[index_fils] = NULL;
	  free(fils);
	}

	return 0;

      }else if(supp > 1){
	node* grd_child = (node*) ((long)supp);
	char* tmp_pre = malloc(sizeof(char) * grd_child->size);
	strcpy(tmp_pre, grd_child->prefix);
	printf("tmp_prefix: %s\n", tmp_pre);
	sprintf(grd_child->prefix, "%s%s", get_prefix(fils), tmp_pre);
	grd_child->size = strlen(grd_child->prefix);
	printf("resultat concat: %s\n", grd_child->prefix);
	set_fils_node(nd, grd_child, grd_child->prefix[0]);
	free(tmp_pre);
	free(fils);
	return 0;
      }else{
	printf("aux_ return 0\n");
	return 0;
      }
    }
  }

  printf("impossible d'arriver à ce point -- sinon erreur\n\n");
  return -1;
}

int supression(node* nd, char* mot){
  if(is_node_null(nd)){
    exit_failure("suppression", "noeud nd est null");
  }

  int val;

  if( has_childs(nd)){
    int i;
    for(i = 0; i < NB_CHAR_MAX; i++){
      node* fils = get_fils_node(nd, (char)i);
      if( !is_node_null(fils)){
	val = aux_supression(fils, mot);
      }
    }
  }
  return val;
  //return aux_supression(nd, mot);
}
