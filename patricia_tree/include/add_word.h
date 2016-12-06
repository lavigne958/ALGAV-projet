#ifndef _ADD_WORD_H
#define _ADD_WORD_H

/**
 * construit un arbre à partir d'un fichier
 */
node* make_arbre_fichier(char* path);


/**
 * fonction recursive permettant d'ajouter un mot a un arbre
 * ne doit etre utilise que dans ajouter_mot()
 */
void sub_add_word(node* n,char* mot);


/**
 * ajoute un mot dans l'arbre arbre
 */
void ajouter_mot(node* arbre, char* mot);

node* make_arbre_liste(char** files_list, int list_size);

#endif
