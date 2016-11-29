#ifndef _DELETE_H
#define _DELETE_H



int delete_node(node* n, node* father, int can_remove);

int aux_delete_word(node* n, char* word, node* father);

int delete_word(racine* racine, char* word);


#endif
