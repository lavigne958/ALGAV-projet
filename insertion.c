#include <stdio.h>


#include "struct.h"
#include "access.h"
#include "search.h"


int aux_insert_mot(node* fils, char* mot){
    if(is_node_null(fils)){
        fprintf(stderr,"insertion dans un noeud vide\n");
        exit(EXIT_FAILURE);
    }

    if(strlen(mot) <= 0){
        fprintf(stderr,"insertion d'un mot vide...\n");
        exit(EXIT_FAILURE);
    }

    

}


int insert_mot(node* noeud, char* mot){

    if(is_node_null(noeud)){
        fprintf(stderr,"insertion dans un noeud vide\n");
        exit(EXIT_FAILURE);
    }

    if(strlen(mot) <= 0){
        fprintf(stderr,"insertion d'un mot vide...\n");
        exit(EXIT_FAILURE);
    }

    node* fils = get_fils_node(noeud,mot[0]);

    return aux_insert_mot(fils,mot);
}
