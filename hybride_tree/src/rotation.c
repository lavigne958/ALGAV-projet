#include <stdio.h>

#include "util.h"
#include "struct.h"
#include "access.h"
#include "profondeur.h"

void rotation_gauche(node* nd){
  node* filsD = get_supp_node(nd);
  node* filsGfilsD = get_inf_node(get_supp_node(nd));

  set_supp_node(nd, filsGfilsD);
  set_inf_node(filsD, nd);

  return filsD;
}

void rotation_droite(node* nd){
  node* filsG = get_inf_node(nd);
  node* filsDfilsg = get_supp_node(get_inf_node(nd));

  set_inf_node(nd, filsDfilsg);
  set_supp_node(filsG, nd);

  return filsG;
}


void equilibre(node* nd, node* father){

  int prof = profondeur(get_inf_node(nd)) - profondeur(get_supp_node(nd));

  if( prof == 2){
    node* filsG = get_inf_node(nd);

    if(profondeur(get_inf_node(filsG)) < profondeur(get_supp_node(filsG))){
      filsG = rotation_gauche(filsG);
      set_inf_node(nd, filsG);
    }

    node* new_nd = rotation_droite(nd);
    if( side_son(nd, father) == 1){
      set_supp_node(father, new_nd);
    }else if( side_son(nd, father) == -1){
      set_inf_node(father, new_nd);
    }else{
      printf("impossible car ca serait le fils du milieur\n");
    }
  }

  if( prof == -2){
    node* filsD = get_supp_node(nd);

    if( profondeur(get_inf_node(filsD)) < profondeur(get_supp_node(filsD)))
  
