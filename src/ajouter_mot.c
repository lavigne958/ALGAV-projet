#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "access.h"


int taille_prefixe_commun(char* a, char* b){
  int i=0;
  if(a == NULL || b == NULL){
    fprintf(stderr,"indice_char_diff: L'un des mots au moins n'existe pas\n");
    exit(EXIT_FAILURE);
  }
  do{
    if(a[i]=='\0' || b[i]=='\0')
      return i;
    if(a[i] == b[i])
      i++;
    else
      return i;
  }while(a[i]!='\0' || b[i]!='\0');
  return i;
}




void sub_add_word(node* n,char* mot){
  
  char* prefix = get_prefix(n);
  int nb_lettre_commun;
  int taille_prefix = n->size;
  int prefix_avec_epsilon = 0;
  
  if(prefix[taille_prefix-1] == EPSILON){
    taille_prefix--;
    prefix_avec_epsilon = 1;
  }

  if(taille_prefix == 0){ 
    /* si prefixe vide: ajouter mot + EPSILON et c est fini  */
  }else if(taille_mot == taille_prefixe){

    /* si le mot est le prefix: gerer EPSILON */
    if(!strncmp(mot, prefix, taille_prefix)){

      if(prefix_avec_epsilon){
	/* le mot est deja dans l'arbre */
	return ;
      }else{ /*regarder si le noeud a des fils, si oui verifier qu il y a epsilon ds fils ou l ajouter */
	fils = get_fils_node(n,mot[EPSILON]);

	if(fils = NULL){
	  /* arbre mal forme, on gere le delire comme tu veux */
	}else{
	  /* regarder si epsilon dans le fils si oui dire que le mot est deja ds l'arbre*/
	  if(get_prefixe(fils) == EPSILON){
	    printf("le mot que vous voulez ajouter est deja dans l'arbre\n");
	    return;
	  }else{
	    /* ici fonction ajouter EPSILON */
	    set_prefixe(fils,EPSILON);
	  }
	}
      }
    }else{ /* le mot n'est pas le prefix */
      nb_lettre_commun = taille_prefixe_commun(mot, prefix);
      if(nb_lettre_commun < n->size){ /* si mot plus petit que prefix */
	fils = get_fils_node(n,mot[]);
      }else{ /* si mot plus grand que prefix */

      }




void ajouter_mot(node* arbre, char* mot){

  node* fils;
  char* chaine_Epsilon;
  char* prefix_fils;
  int taille_mot = strlen(mot);
  /* test si l'arbre existe */
  if(is_node_null(arbre)){
    fprintf(stderr,"erreur arbre: NULL - ajouter_mot\n");
    exit(EXIT_FAILURE);
  }

    /* test si le mot est une chaine vide */
  if( !taille_mot ){
    fprintf(stderr,"erreur chaine vide - ajouter_mot\n");
    exit(EXIT_FAILURE);
  }

  /* test si le mot est trop grand */
  if(taille_mot >= NB_CHAR_MAX+1){
    fprintf(stderr,"ajout d'un mot trop long - ajouter_mot\n");
    exit(EXIT_FAILURE);
  }
  
  fils = get_fils_node(arbre,chaine[0]);

  if(fils == NULL){ /* cas ou pas de fils, creation + insertion direct */
    if(creer_fils(arbre)){
        fils = get_fils_node(arbre,chaine[0]);
	set_prefix(fils, mot);
	prefix_fils = get_prefix(fils);
	prefix_fils[taille_mot] = EPSILON;
	prefix_fils[taille_mot+1] = '\0';
	fils->size = strlen(get_prefix(fils));
	/* je sens qu il va y avoir un souci ac chaine_Epsilon */
    }else{
      fprintf(stderr,"Impossible d'ajouter le mot, probleme lors de la creation d'un fils\n");
      exit(EXIT_FAILURE);
    }
  }else{ /* cas ou le fils existe, parcourt recursif et insertion progressive */
  return sub_add_word(fils,chaine);
}

