#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "struct.h"
#include "access.h"
#include "affichage.h"


void sub_add_word(node* n,char* mot){
  int taille_prefix_commun; 
  char* prefix_commun =NULL;
  char* reste_prefix = NULL;
  char* reste_mot = NULL;
  char* prefix = get_prefix(n);
  int taille_prefix = n->size;
  int taille_mot = strlen(mot);  
  int prefix_avec_epsilon = 0;
  node* fils1 = NULL;
  node* fils2 = NULL;
  node** new = NULL;
  char indice_reste_prefix, indice_reste_mot;

  
  /* ----- gestions chaines et tailles chaines -------- */
  if(prefix[taille_prefix-1] == EPSILON){
    taille_prefix--;
    prefix_avec_epsilon = 1;
  }
  
  taille_prefix_commun = taille_prefixe_commun(prefix, mot);
  
  if(!taille_prefix_commun)
    exit_failure("sub_add_word","prefix et mot n'ont aucun caractere en commun");
  
  prefix_commun = str_sub(prefix,0, taille_prefix_commun-1);
  reste_prefix = str_sub(prefix, taille_prefix_commun, taille_prefix-1);
  reste_mot = str_sub(mot, taille_prefix_commun, taille_mot-1);
  

  
  /* ----- fin gestions chaines et tailles chaines -------- */

  if(prefix_avec_epsilon){ /* prefix_avec_epsilon == 1 */
    
    
    if( strncmp(mot,prefix,max(taille_prefix,taille_mot)) != 0 ) {
      


      /* creation du node fils */
      creer_tableau_fils(n);
      
      /* creation des nodes necessaire pour chaque cas
	 + ajout des nodes cree
	 + ajout des nodes EPSILON si necessaire */
      if( strncmp(prefix_commun,prefix,taille_prefix) == 0){ /* prefix == prefix_commun */

	fils2 = creer_noeud();
	set_prefix(fils2, reste_mot);
	prefix_add_epsilon(fils2);
	set_fils_node(n, fils2, reste_mot[0]);
	add_epsilon_node(n);

      }else if( strncmp(prefix_commun,mot,taille_mot) == 0 ){
	
	fils1 = creer_noeud();
	set_prefix(fils1, reste_prefix);
	prefix_add_epsilon(fils1);
	set_fils_node(n, fils1, reste_prefix[0]);
	
	add_epsilon_node(n);
      }else{
	
	
	fils1 = creer_noeud();
	set_prefix(fils1, reste_prefix);
	prefix_add_epsilon(fils1);
	set_fils_node(n, fils1, reste_prefix[0]);
	
	fils2 = creer_noeud();
	set_prefix(fils2, reste_mot);
	prefix_add_epsilon(fils2);
	set_fils_node(n, fils2, reste_mot[0]);
      }

      /* maj des attributs de n */
      set_prefix(n,prefix_commun);
      
    }
    
  }else{ /* prefix_avec_epsilon == 0 */
     
    if( strncmp(mot,prefix,max(taille_prefix,taille_mot)) == 0 ){
      
      if( !get_fils_node(n, EPSILON) ){
	add_epsilon_node(n);
      }
      
    }else if( strncmp(prefix_commun,prefix,taille_prefix) == 0 ){
      
      fils2 = get_fils_node(n, reste_mot[0]);
      if(fils2){
	sub_add_word(fils2,reste_mot);
      }else{
	fils2 = creer_noeud();
	set_prefix(fils2, reste_mot);
	prefix_add_epsilon(fils2);
	set_fils_node(n, fils2, reste_mot[0]);
      }
      
    }else if( strncmp(prefix_commun,mot,taille_mot) == 0 ){
      
      /* maj des attributs de n */
      set_prefix(n,prefix_commun);
      
      /* creation d'un nouveau tab_fils qui prendra la place de 
	 celui de n. Celui de n deviendra celui de f1 */
      new = creer_tab_sans_pere();

      fils1 = creer_noeud();
      set_prefix(fils1, reste_prefix);
      indice_reste_prefix = reste_prefix[0];
      new[(int)indice_reste_prefix] = fils1;
      
      set_tab_fils( fils1, get_tab_fils(n) );
      set_tab_fils( n, new );

      add_epsilon_node(n);
	
    }else{

            
      /* maj des attributs de n */
      set_prefix(n,prefix_commun);

      /* creation d'un nouveau tab_fils qui prendra la place de 
	 celui de n. Celui de n deviendra celui de f1 */
      new = creer_tab_sans_pere();

      fils1 = creer_noeud();
      set_prefix(fils1, reste_prefix);
      indice_reste_prefix = reste_prefix[0];
      new[(int)indice_reste_prefix] = fils1;

      fils2 = creer_noeud();

      set_prefix(fils2, reste_mot);



      prefix_add_epsilon(fils2);
      indice_reste_mot = reste_mot[0];
      new[(int)indice_reste_mot] = fils2;

      set_tab_fils( fils1, get_tab_fils(n) );
      set_tab_fils( n, new );

    }
	
  }
  return;
}




void ajouter_mot(node* arbre, char* mot){

  
  node* fils;
  int taille_mot = strlen(mot);
  
  /* test si l'arbre existe */
  if(is_node_null(arbre))
    exit_failure("ajouter_mot", "erreur arbre: NULL");
  
  /* test si le mot est une chaine vide */
  if( !taille_mot )
    exit_failure("ajouter_mot", "erreur chaine vide");
      
  /* test si le mot est trop grand */
  if(taille_mot >= NB_CHAR_MAX+1)
    exit_failure("ajouter_mot", "ajout d'un mot trop long");

  if(!arbre->tab_fils)
    creer_tableau_fils(arbre);
  
  fils = get_fils_node(arbre,mot[0]);
  
  if(fils == NULL){ /* cas ou pas de fils, creation + insertion direct */
    fils = creer_noeud();
    set_fils_node(arbre, fils, mot[0]);
    set_prefix(fils, mot);
    prefix_add_epsilon(fils);
    
  }else{ /* cas ou le fils existe, parcourt recursif et insertion progressive */
    sub_add_word(fils,mot);
  }
  return ;
}




node* make_arbre_fichier(char* path){

  node* arbre = creer_noeud();
  FILE* fic;
  int retour_lecture;
  char buff[1024];

  
  if( !(fic = fopen(path, "r")) )
    exit_failure("make_arbre_fichier", "echec d'ouverture de fichier");
  do{    
    retour_lecture = fscanf(fic, "%s ", buff);
    if(retour_lecture != EOF)
      ajouter_mot(arbre,buff);
      
  }while(retour_lecture != EOF);
  return arbre;
}

node* make_arbre_liste(char** files_list, int list_size){
  int i;
  node* root = creer_noeud();
  FILE* file = NULL;
  int lu;
  char buff[100];
  char annexe[100];

  for(i = 0; i < list_size; i++){
    
    strcpy(annexe, "shakespear/");
    strcat(annexe, files_list[i]);
    
    if( !(file = fopen(annexe, "r"))){
      sprintf(buff, "impossible d'ouvrir le fichier: %s\n", files_list[i]);
      exit_failure("make_arbre_liste", buff);
    }

    memset(buff, '\0', 100);

    lu = fscanf(file, "%s ", buff);
    
    while(lu != EOF){
      ajouter_mot(root, buff);
      
      memset(buff, '\0', 100);
      lu = fscanf(file, "%s ", buff);
    }

    fclose(file);
  }

  return root;
}
