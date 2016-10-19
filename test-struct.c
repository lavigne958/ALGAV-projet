#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PREFIX_MAX 20
#define NB_CHAR_MAX 127
#define EPSILON '_'

typedef struct node{
    char prefix[PREFIX_MAX];
    struct node** fils;
}node;

int main(){
    int i;

    printf("creation structure\n");
    
    printf("code de b: %d\n",'b');

    //creation d'un tableau qui sera le noeud racie avec au max 127 characteres + epsilon
    node* racine = (node*) malloc(sizeof(node));

    for(i = 0
    
    printf("racine est creer\n");
    //creation d'un tableau de fils pouvant contenir tout les caracteres une fois + epsilon
    racine->fils[(int)'a']->fils = (node**) malloc(sizeof(node*) * (NB_CHAR_MAX + 1));

    printf("le tableau de fils est declarer\n");

    for(i = 0; i < (NB_CHAR_MAX + 1); i++){
        racine[(int)'a']->fils[i] = (node*) malloc(sizeof(node));
    }

    printf("le tableau de fils est creer\n");
    
    strcpy(racine[(int)'a']->prefix,"aa");
    printf("copie de aa dans dans racine[a]\n");

    printf("adr racine[a]: %x fils: %x *fils: %x \n",&racine[(int)'a'],&(racine[(int)'a']->fils),racine[(int)'a']->fils);


    strcpy(racine[(int)'a']->fils[(int)'b']->prefix,"b"); 
   
    printf("arbre: %s->%s\n",racine[(int)'a']->prefix,racine[(int)'a']->fils[(int)'b']->prefix);
    printf("copie de b dans racine[a].fils[b]\n");
    

    return 0;
}
