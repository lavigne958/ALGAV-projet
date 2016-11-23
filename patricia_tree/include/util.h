#ifndef UTIL_H
#define UTIL_H


/**
 * affiche un message dans le flux d'erreur
 * prend un nom de fonction (celle qui à déclenché l'erreur
 * prend un message pour spécifier l'erreur
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ATTENTION: cette fonction quitte le programme
 */
void exit_failure(char* , char* );


/**
 * renvoie la taille du prefix commun aux chaines de caracteres passe en parametre
 */
int taille_prefixe_commun(char*  , char*);

/**
 * renvoi la sous chaine qui commence a l'indice start 
 * et qui se termine a l'indice end
 */
char* str_sub (const char *s, int start,int end);

/**
 * renvoie le max de deux nombre
 */
int max(int x, int y);



#endif
