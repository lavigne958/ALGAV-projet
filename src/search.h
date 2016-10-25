#ifndef _SEARCH_H
#define _SEARCH_H


/* fonction qui renvoi la sous chaine de s comprise entre les indices stars et end 
 j'ai chope cette fonction sur internet (http://nicolasj.developpez.com/articles/libc/string/)
 et je ne l'ai pas verifie mais ca a l'air pas mal on retourne une chaine vide dans un certain 
 mais vu comment on l'utilise on devrait jamais tomber dans ce cas */
char* str_sub (const char *s, unsigned int start, unsigned int end);

/* fonction qui ne doit exister que dans recherche_mot
   permet de rendre la recursion de recherche_mot possible */
int sub_search(node* node,char* chaine);

/* recherche le mot chaine dans le Patricia_Tries arbre 
 retoune 1 si chaine est un mot de arbre, 0 sinon */
int recherche_mot(node* arbre,char* chaine);

#endif
