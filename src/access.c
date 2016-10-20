#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"



node* creer_noeud(){
    node* retour;
    
    if( (retour = (node*) malloc(sizeof(node))) == NULL){
        fprintf(stderr,"erreur malloc creer noeud\n");
        exit(EXIT_FAILURE);
    }

    retour->fils = NULL;

    return retour;
}


int creer_fils(node* n){
    int i;

	if(n == NULL){
		fprintf(stderr,"erreur node = null , creer fils\n");
        return -1;
	}
	
	n->fils = (node**) malloc(sizeof(node*) * (NB_CHAR_MAX + 1));
	
	if(n->fils == NULL){
		fprintf(stderr,"erreur node->fils = null , creer fils\n");
		return -1;
	}
	
    for(i = 0; i < (NB_CHAR_MAX + 1); i++){
        n->fils[i] = (node*) malloc(sizeof(node));
        if(n->fils[i] == NULL){
			fprintf(stderr,"erreur node->fils[%d] = null , creer fils\n",i);
			return -1;
		}
    }
    
    return 0;
}

char* get_prefix(node* n){
	if(n == NULL){
		fprintf(stderr,"erreur node = null , creer fils\n");
        return -1;
	}
	
	return n->prefix;
}

node* get_fils_node(node* n, char index){
	if(n == NULL){
		fprintf(stderr,"erreur node = null , creer fils\n");
        return -1;
	}
	
	node* fils = n->fils[(int)index];
	
	if(fils == NULL){
		fprintf(stderr,"erreur node = null , creer fils\n");
        return -1;
	}
	
	return fils;
}
    
    
