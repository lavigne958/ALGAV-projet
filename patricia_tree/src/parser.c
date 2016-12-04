#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "parser.h"
#include "util.h"

words_list* read_words(char* file){
  words_list* head;
  words_list* tail;
  FILE* fd;
  char buff[200];

  //allocation de la tête de liste
  head = (words_list*) malloc(sizeof(words_list));
  head->word = NULL;
  head->next = NULL;

  tail = head;

  fd = NULL;
  
  fd = fopen( file, "r");
  if( fd == NULL){
    perror("fopen");
    exit(errno);
  }

  int nb_match = 0;

  //lecture du fichier
  while( !feof(fd)){
    //met à zero tout les bit pour être sur de ne pas conserver la fin d'un ancien mot
    memset(buff, '\0', 200);

    //lecture d'un mot seullement (on s'arrete apres un espace)
    nb_match = fscanf(fd, "%s ", buff);

    //si on a lu, et qu'il n'y a pas d'erreur et qu'on est pas à la fin...
    if( nb_match > 0 && errno == 0 && buff[0] != EOF){
      //insertion d'un nouveau mot dans la liste chainée
      tail->word = (char*) malloc( (sizeof(char)*strlen(buff)) + 1);
      strcpy(tail->word, buff);

      if(tail->next == NULL){
	tail->next = (words_list*) malloc(sizeof(words_list));
      }
      
      tail = tail->next;
    }else{
      exit_failure("read_word", "erreur lors de la lecture du fichier");
    }
  }

  return head;  
}
