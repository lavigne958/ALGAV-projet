#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int max(int a, int b){
  if(a<b)
    return b;
  return a;
}


void exit_failure(char* nom_func, char* mess){
  fprintf(stderr,"!---! Erreur !---!\n");
  fprintf(stderr,"fonction: %s -- %s\n",nom_func,mess);
  exit(EXIT_FAILURE);
}


int taille_prefixe_commun(char* a, char* b){
  int i=0;

  if(a == NULL || b == NULL)
    exit_failure("taille_prefixe_commun","L'un des mots au moins n'existe pas");

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

