#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "access.h"


int recherche_mot(node* arbre,char* chaine){
  if(is_nod_null(arbre)){
    fprintf(stderr,"erreur arbre: NULL - recherche_mot\n");
    exit(EXIT_FAILURE);
  }

  if( !strlen(chaine) ){
    fprintf(stderr,"erreur chaine vide - recherche_mot\n");
    exit(EXIT_FAILURE);
  }

  node* fils = get_fils_node(arbre,chaine[0]);

  if(fils == NULL){
    fprintf(stderr,"erreur fils:NULL - recherche_mot\n");
    exit(EXIT_FAILURE);
  }

  return sub_search(fils,chaine);
}

int sub_search(node* node,char* chaine){
  int taille_chaine = strlen(chaine);
  int taille_prefix = node.size;
  char* prefix = get_prefix(node);
  node* fils;
  
  /* verifier que le prefixe ne se termine pas par EPSILON 
   si oui reduit la taille de 1 pour ne pas le prendre en compte dans la comparaison des tailles*/
  if(prefix[taille_prefix-1] == EPSILON)
    taille_prefix--;
 
  if(taille_prefix==taille_chaine){ 
    if( strncmp(chaine, prefix, taille_prefix) ==0 ){
      /* bon en fait ici il faut traiter le cas ou le prefix ne se finit pas
	 par EPSILON je fai ca en rentrant */
      return 1;
    }else{
      return 0;
    }
  }else if(taille_prefix > taille_chaine){
    return 0;
  }else{ /* cas ou taille_prefix < taille_chaine */

    /* verifie que chaine et prefix sont egaux: si non le mot n'est pas dans l'arbre */
    if( strncmp(chaine, prefix, taille_prefix) ==0 ){
      
      /* verifie que le node a un fils: si oui recursion, sinon chaine n'est pas dans l'arbre */  
      fils = get_fils_node(node);
      if(fils == NULL){
	return 0;
      }else{
	return sub_search(node* node, str_sub(chaine, (taille_chaine-taille_prefix), taille_chaine ));
      }
      
    }else{ 
      return 0;
    }
  }   
}


/* fonction qui renvoi la sous chaine de s comprise entre les indices stars et end 
 j'ai chope cette fonction sur internet (http://nicolasj.developpez.com/articles/libc/string/)
 et je ne l'ai pas verifie mais ca a l'air pas mal on retourne une chaine vide dans un certain 
 mais vu comment on l'utilise on devrait jamais tomber dans ce cas */
char* str_sub (const char *s, unsigned int start, unsigned int end){
  char* new_s = NULL;
  if(s != NULL && start < end){
    new_s = malloc (sizeof (*new_s) * (end - start + 2));
    if(new_s != NULL){
      int i;
      for (i = start; i <= end; i++){
	new_s[i-start] = s[i];
      }
      new_s[i-start] = '\0';
    }else{
      fprintf (stderr, "Memoire insuffisante\n");
      exit (EXIT_FAILURE);
    }
  }
  return new_s;
}
