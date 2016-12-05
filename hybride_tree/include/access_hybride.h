#ifndef _HYBRIDE_ACCESS_H
#define _HYBRIDE_ACCESS_H

#include "struct_hybride.h"


racine* creer_racine();
int is_node_null_hybride(node_h*);
node_h* creer_noeud_hybride();
char get_lettre(node_h*);
void set_lettre(node_h*, char);
node_h* get_inf_node(node_h*);
node_h* get_eq_node(node_h*);
node_h* get_supp_node(node_h*);
int get_key(node_h*);
void set_key(node_h*, int);
void set_inf_node(node_h*, node_h*);
void set_eq_node(node_h*, node_h*);
void set_supp_node(node_h*, node_h*);

#endif
