#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"



node* creer_noeud(){
    node* node;
    
    if( (node = (node*) malloc(sizeof(node))) == NULL){
        fprintf(stderr,"erreur malloc creer noeud\n");
        exit(EXIT_FAILURE);
    }

    retour->fils = NULL;

    return retour;
}


int creer_fils(node* node){
    int i;

    for(i = 0; i < (NB_CHAR_MAX + 1); i++){
        node->
    }
