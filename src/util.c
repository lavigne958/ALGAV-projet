#include <stdlib.h>
#include <stdio.h>

void exit_failure(char* nom_func, char* mess){
  fprintf(stderr,"!---! Erreur !---!\n");
  fprintf(stderr,"fonction: %s -- %s\n",nom_func,mess);
  exit(EXIT_FAILURE);
}
