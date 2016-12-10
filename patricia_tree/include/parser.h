#ifndef _PARSER_H
#define _PARSER_H


#include "struct.h"

/**
 * structure de liste chainé de mots
 * permet de stocker les mots lu depuis un fichier
 */
typedef struct words_list{
  char* word;
  struct words_list* next;
}words_list;


/**
 * permet de lire tout les mots d'un fichier dont
 * le nom est passé en paramtètre
 */
words_list* read_words(char*);

#endif
