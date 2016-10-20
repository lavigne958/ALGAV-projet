#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"

int main(){
    int i;

    printf("creation structure\n");
    
    node* nd = creer_noeud();
    
    strcpy(nd->prefix,"test phrase");
    
    printf("préfixe de racine: %s\n",nd->prefix);
    
    if( creer_fils(nd) ){
		fprintf(stderr,"erreur lors de la création de mes fils\n");
		exit(1);
	}
	
	node* filsA = get_fils_node(nd,'A');
	strcpy(filsA->prefix,"A");
	
	printf("test des liens (pointeurs)\n");
	printf("nd->fils[A]->prefix: %s\tfilsA->prefix: %s\n",nd->fils['A']->prefix,filsA->prefix);
    

    return 0;
}
