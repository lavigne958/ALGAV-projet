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
 * vérifie si un prefix est égale à une string, 
 * si EPSILON est présent, la fonction ne le compte pas
 */
sint prefix_equals_string(node*, char*);

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
 * test si le noeud en cours ce termine par EPSILON ou contient EPSILON dans son premier noeud (le noeud est un mot mais n'est pas une feuille
 */
int prefix_has_epsilon(node*);

/**
 * creer un tableau de pointeur sur node soit un node
 */
node** creer_tab_fils(void);

/**
 * verifie qu'un noeurs possède un fils epsilon
 */
int node_has_epsilon(node*);

/**
 * test si un noeud à des fils, par défaut un noeud creer n'a pas de fils, sont tableau de fils vaut NULL
 */
int has_childs(node*);


/**
 * retourne le nombre de fils du noeud
 */
int get_nb_fils(node*);
#endif
