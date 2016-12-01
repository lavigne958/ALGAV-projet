#include <stdio.h>

#include "util.h"
#include "struct.h"
#include "access.h"
#include "delete.h"
#include "profondeur.h"

node* rotation_gauche(node* nd){
  node* filsD = get_supp_node(nd);

  set_supp_node(nd, get_inf_node(filsD));
  set_inf_node(filsD, nd);

  return filsD;
}

node* rotation_droite(node* nd){
  node* filsG = get_inf_node(nd);

  set_inf_node(nd, get_supp_node(filsG));
  set_supp_node(filsG, nd);

  return filsG;
}


void equilibre(node* nd, node* father){
  node* new_nd;
  int prof = profondeur_rotation(get_inf_node(nd)) - profondeur_rotation(get_supp_node(nd));

  if( prof == 2){
    node* filsG = get_inf_node(nd);

    if(profondeur_rotation(get_inf_node(filsG)) < profondeur_rotation(get_supp_node(filsG))){
      filsG = rotation_gauche(filsG);
      set_inf_node(nd, filsG);
    }

    new_nd = rotation_droite(nd);
    if( side_son(nd, father) == 1){
      set_supp_node(father, new_nd);
    }else if( side_son(nd, father) == -1){
      set_inf_node(father, new_nd);
    }else{
      printf("impossible car ca serait le fils du milieur\n");
    }
  }

  //prof = profondeur(get_inf_node(nd)) - profondeur(get_supp_node(nd));
  if( prof == -2){
    node* filsD = get_supp_node(nd);

    if( profondeur_rotation(get_inf_node(filsD)) > profondeur_rotation(get_supp_node(filsD))){
      filsD = rotation_droite(filsD);
      set_supp_node(nd, filsD);
    }

    new_nd = rotation_gauche(nd);
    
    if( side_son(nd, father) == 1){
      set_supp_node(father, new_nd);
    }else if( side_son(nd, father) == -1){
      set_inf_node(father, new_nd);
    }else{
      printf("impossible car ca serait le fils du milieur\n");
    }
  }
}  
