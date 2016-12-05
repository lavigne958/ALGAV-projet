#ifndef _HYBRIDE_UTIL_H
#define _HYBRIDE_UTIL_H



int max(int a, int b);



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


#endif
