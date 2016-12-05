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
  while( !feof(fd)){
    memset(buff, '\0', 200);

    nb_match = fscanf(fd, "%s ", buff);
    if( nb_match > 0 && errno == 0 && buff[0] != EOF){
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
