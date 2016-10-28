#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "access.h"

int main(){
    int i;
    
    printf("creation structure\n");
    
    node* nd = creer_noeud();

    printf("le noeud est initialement vide %s\n",nd->prefix);
    
    strcpy(nd->prefix,"test phrase");
    
    printf("préfixe de racine: %s\n",nd->prefix);
    
    creer_tableau_fils(nd);
    
	
    node* filsA = get_fils_node(nd,'A');
    if(filsA == NULL){
      filsA = creer_noeud();
      set_fils_node(nd,filsA,'B');
    }

    filsA = get_fils_node(nd,'A');

    set_prefix(filsA,"BBB");
	
    printf("test des liens (pointeurs)\n");
    printf("nd->fils[A]->prefix: %s\tfilsA->prefix: %s\n",nd->fils['A']->prefix,filsA->prefix);
    

    return 0;
}
