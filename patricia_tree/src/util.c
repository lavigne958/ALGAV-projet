#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max(int a, int b){
  if(a<b)
    return b;
  return a;
}


void exit_failure(char* nom_func, char* mess){
  //fonction permetant de quiter prompement le programme
  fprintf(stderr,"!---! Erreur !---!\n");
  fprintf(stderr,"fonction: %s -- %s\n",nom_func,mess);
  exit(EXIT_FAILURE);
}


int taille_prefixe_commun(char* a, char* b){
  int i=0;

  if(a == NULL || b == NULL)
    exit_failure("taille_prefixe_commun","L'un des mots au moins n'existe pas");

  //tant que les deux caractères ne sont pas nulls
  do{
    if(a[i]=='\0' || b[i]=='\0')
      return i;
    //si ce sont les même on incrémente
    if(a[i] == b[i])
      i++;
    else
      //sinon on à trouvé la fin de la partie commune
      return i;
  }while(a[i]!='\0' || b[i]!='\0');
  return i;
}


char* str_sub (const char *s, int start,int end){
  char* new_s = NULL;

  //si s n'est pas null et que la fin est après le début :)
  if(s != NULL && start <= end){
    //alocation de la nouvelle chaine nécéssaire
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


  
