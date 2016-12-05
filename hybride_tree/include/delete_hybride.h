#ifndef _DELETE_H
#define _DELETE_H



int delete_node(node_h* n, node_h* father, int can_remove);

int aux_delete_word(node_h* n, char* word, node_h* father);

int delete_word(racine* racine, char* word);

int side_son(node_h* n, node_h* father);


#endif
