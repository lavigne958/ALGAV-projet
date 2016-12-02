#include <stdio.h>

#include "util.h"
#include "struct.h"
#include "access.h"
#include "delete.h"
#include "profondeur.h"

node* rotation_gauche(node* nd){
  node* new_nd = nd->supp;

  nd->supp = new_nd->inf;
  new_nd->inf = nd;

  return new_nd;
}

node* rotation_droite(node* nd){
  node* new_nd = nd->inf;

  nd->inf = new_nd->supp;
  new_nd->supp = nd;

  return new_nd;
}

node* double_rotation_droite(node* nd){
  node* filsG = get_inf_node(nd);

  set_inf_node(nd, rotation_gauche(filsG));

  return rotation_droite(nd);
}

node* double_rotation_gauche(node* nd){
  node* filsD = get_supp_node(nd);

  set_supp_node(nd, rotation_droite(filsD));

  return rotation_gauche(nd);
}


node* equilibre(node* nd){
  node* filsG = get_inf_node(nd);
  node* filsD = get_supp_node(nd);

  int prof = profondeur_rotation(filsG) - profondeur_rotation(filsD);

  if( prof == 2){
    node* filsGG = get_inf_node(filsG);
    node* filsGD = get_supp_node(filsG);

    if( profondeur_rotation(filsGG) < profondeur_rotation(filsGD)){
      filsG = rotation_gauche(filsG);
      set_inf_node(nd, filsG);
    }

    nd = rotation_droite(nd);
  }

  if( prof == -2){
    node* filsDG = get_inf_node(filsD);
    node* filsDD = get_supp_node(filsD);

    if( profondeur_rotation(filsDG) > profondeur_rotation(filsDD)){
      filsD = rotation_droite(filsD);
      set_supp_node(nd, filsD);
    }

    nd = rotation_gauche(nd);
  }

  return nd;
}
