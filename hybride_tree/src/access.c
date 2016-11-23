#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "util.h"

/* alloue une racine en mémoire
 * renvoie un pointeur vers cette racine
 */

racine* creer_racine(){
  racine* root = (racine*) malloc(sizeof(racine));
  if( root == NULL){
    exit_failure("creer_racine", "impossible d'allouer la racine en mémoire");
  }
  
  root->tree = NULL;
  root->counter = 0;
  
  return root;
}

/* test si un noeud vaut NULL
 * donc s'il n'est pas aloué
 */

int is_node_null(node* nd){
  return (nd == NULL);
}

/* alloue un noeud en mémoire et renvoie un pointeur sur ce noeud
 * initialise les champs:
 * - lettre = 0
 * - inf, eq, supp = NULL
 * - key = -1 ( car on commence à compter à partir de 0
 */

node* creer_noeud(){
  node* nd = (node*) malloc(sizeof(node));

  if( is_node_null(nd)){
    exit_failure("creer_noeud", "impossible d'alouer le noeud");
  }

  nd->lettre = 0;
  nd->inf = NULL;
  nd->eq = NULL;
  nd->supp = NULL;
  nd->key = -1;

  return nd;
}


/* prend un noeud en argument et renvoie la lettre ascociée
 */
char get_lettre(node* nd){
  if(is_node_null(nd)){
    exit_failure("get_lettre", "le noeud vaut NULL");
  }

  return nd->lettre;
}

/* met à jour la lettre d'un noeud s'il n'est pas NULL
 */
void set_lettre(node* nd, char new_lettre){
  if(is_node_null(nd)){
    exit_failure("set_lettre", "le noeud vaut NULL");
  }

  nd->lettre = new_lettre;
}

/* retourne respectivement les noeud inférieur ou suivant, ou suppérieur
 */
node* get_inf_node(node* nd){
  if(is_node_null(nd)){
    exit_failure("get_inf_node", "le noeud vaut NULL");
  }

  return nd->inf;
}

node* get_eq_node(node* nd){
  if(is_node_null(nd)){
    exit_failure("get_inf_node", "le noeud vaut NULL");
  }
  
  return nd->eq;
}

node* get_supp_node(node* nd){
  if(is_node_null(nd)){
    exit_failure("get_inf_node", "le noeud vaut NULL");
  }
  
  return nd->supp;
}

void set_key(node* nd, int key){
  if(is_node_null(nd)){
    exit_failure("set_key", "le noeud vaut NULL");
  }

  nd->key = key;
}

/* met à jour le fils inférieur ou egale ou suppérieur
 */
void set_inf_node(node* nd, node* new_inf){
  if(is_node_null(nd)){
    exit_failure("set_inf_node", "le noeud parent vaut NULL");
  }

  if(is_node_null(new_inf)){
    exit_failure("set_inf_node", "le nouveau noeud inf vaut NULL");
  }

  nd->inf = new_inf;
}

void set_eq_node(node* nd, node* new_eq){
  if(is_node_null(nd)){
    exit_failure("set_eq_node", "le noeud parent vaut NULL");
  }

  if(is_node_null(new_eq)){
    exit_failure("set_eq_node", "le nouveau noeud eq vaut NULL");
  }

  nd->eq = new_eq;
}

void set_supp_node(node* nd, node* new_supp){
  if(is_node_null(nd)){
    exit_failure("set_inf_node", "le noeud parent vaut NULL");
  }

  if(is_node_null(new_supp)){
    exit_failure("set_supp_node", "le nouveau noeud supp vaut NULL");
  }

  nd->supp = new_supp;
}
