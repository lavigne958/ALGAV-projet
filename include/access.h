#ifndef _ACCESS_H
#define _ACCESS_H

/**
 * creer un noeud vide
 * alloue l'espace pour le prefixe
 * tableau de fils vaut NULL
 *
*/

node* creer_noeud();

/**
 * verifie qu'un noeud n n'est pas null
 * et affiche un message d'erreur dans le cas vrai
 */
int is_node_null(node* );

/**
 * creer le tableau de fils
 * creer les pointeurs et les structures
*/
void creer_tableau_fils(node*);

/**
 * renvoie le préfixe du noeud
 * 
*/
char* get_prefix(node*);

/**
 * modifie le préfixe du noeud
 * 
*/
void set_prefix(node*, char*);


/**
 * renvoie le fils pointé par la lettre index
x*/

node* get_fils_node(node*, char);

/**
 * ajoute le fils 'fils' au tablea de nd à l'index 'index'
 */

void set_fils_node(node*,node*,char);


/**
 * ajoute le caractère ESPILON à la fin d'un prefix
 */
void prefix_add_epsilon(node*);

/**
 * ajoute le noeud espilon au tableau de fils d'un noeud
 */

void add_espilon_node(node*);

/**
 * creer un tableau de pointeur sur node soit un node
 */
node** creer_tab_fils(void);

#endif
