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
    strcpy(retour->prefix,"\0");

    return retour;
}


int is_node_null(node* n){
    if(n == NULL){
       fprintf(stderr,"erreur node = null\n");
       return 1;
    }else{
        return 0;
    }
}

int creer_fils(node* n){
    int i;

    if(is_node_null(n)){
        return -1;
    }
	
	n->fils = (node**) malloc(sizeof(node*) * (NB_CHAR_MAX + 1));
	
	if(n->fils == NULL){
		fprintf(stderr,"erreur node->fils = null , creer fils\n");
		return -1;
	}
	
    for(i = 0; i < (NB_CHAR_MAX + 1); i++){
        n->fils[i] = (node*) malloc(sizeof(node));
        if(is_node_null(n->fils[i])){
			return -1;
		}
    }
    
    return 0;
}

char* get_prefix(node* n){
	
    if( is_node_null(n) ){
        return -1;
    }
	return n->prefix;
}

node* get_fils_node(node* n, char index){
	if(is_node_null(n)){
        return -1;
    }
	
	node* fils = n->fils[(int)index];
	
	if(is_node_null(fils)){
        return -1;
	}
	
	return fils;
}
    
    
