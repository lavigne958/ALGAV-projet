#include <stdio.h>

#include "util_hybride.h"
#include "struct_hybride.h"
#include "access_hybride.h"
#include "delete_hybride.h"
#include "profondeur_hybride.h"

node_h* rotation_gauche(node_h* nd){
  node_h* new_nd = nd->supp;

  nd->supp = new_nd->inf;
  new_nd->inf = nd;

  return new_nd;
}

node_h* rotation_droite(node_h* nd){
  node_h* new_nd = nd->inf;

  nd->inf = new_nd->supp;
  new_nd->supp = nd;

  return new_nd;
}

node_h* double_rotation_droite(node_h* nd){
  node_h* filsG = get_inf_node(nd);

  set_inf_node(nd, rotation_gauche(filsG));

  return rotation_droite(nd);
}

node_h* double_rotation_gauche(node_h* nd){
  node_h* filsD = get_supp_node(nd);

  set_supp_node(nd, rotation_droite(filsD));

  return rotation_gauche(nd);
}


node_h* equilibre(node_h* nd){
  node_h* filsG = get_inf_node(nd);
  node_h* filsD = get_supp_node(nd);

  int prof = profondeur_rotation(filsG) - profondeur_rotation(filsD);

  if( prof == 2){
    node_h* filsGG = get_inf_node(filsG);
    node_h* filsGD = get_supp_node(filsG);

    if( profondeur_rotation(filsGG) < profondeur_rotation(filsGD)){
      filsG = rotation_gauche(filsG);
      set_inf_node(nd, filsG);
    }

    nd = rotation_droite(nd);
  }

  if( prof == -2){
    node_h* filsDG = get_inf_node(filsD);
    node_h* filsDD = get_supp_node(filsD);

    if( profondeur_rotation(filsDG) > profondeur_rotation(filsDD)){
      filsD = rotation_droite(filsD);
      set_supp_node(nd, filsD);
    }

    nd = rotation_gauche(nd);
  }

  return nd;
}
