#ifndef _ACCESS_H
#define _ACCESS_H

#include "struct.h"

racine* creer_racine();
int is_node_null(node*);
node* creer_noeud();
char get_lettre(node*);
void set_lettre(node*, char);
node* get_inf_node(node*);
node* get_eq_node(node*);
node* get_supp_node(node*);
int get_key(node*);
void set_key(node*, int);
void set_inf_node(node*, node*);
void set_eq_node(node*, node*);
void set_supp_node(node*, node*);

#endif
