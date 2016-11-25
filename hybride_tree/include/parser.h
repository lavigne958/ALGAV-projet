#ifndef _PARSER_H
#define _PARSER_H

/* structure de liste chainé de mots
 * permet de stocker les mots lu depuis un fichier
 */
typedef struct words_list{
  char* word;
  struct words_list* next;
}words_list;

words_list* read_words(char*);

#endif
