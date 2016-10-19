





/*
descr:  insere un mot dans le Patricia_Tries
param:  char* mot -> represente le mot a ajouter dans l'arbre 'arbre'
        pt arbre  -> representre le patricia tries ou on va inserer le mot '*mot'
retour: je sais pas comment on va s organiser, en theorie vu qu on manipule des 
        pointeurs on va retourner un entier pour confirmer que l insertion s'est 
        bien deroulé. ou void si on est sur que ca se passe bien.
*/
int inserer_mot(char* mot, node* arbre);



/* 
descr:  supprime un mot dans le Patricia_Tries
param:  char* mot -> le mot à supprimer dans l'arbre 'arbre'
        pt* arbre -> le patricia tries ou on va supprimer le mot '*mot'
retour: je sais pas comment on va s organiser, en theorie vu qu on manipule des 
        pointeurs on va retourner un entier pour confirmer que la suppression s'est 
        bien deroulé. ou void si on est sur que ca se passe bien. */
int supprimer_mot(char* mot, node* arbre);



/* 
descr:  indique si un mot est present dans le Patricia_Tries
param:  char* mot -> le mot à chercher dans  l'arbre 'arbre'
        pt* arbre -> le patricia tries ou on va chercher le mot '*mot'
retour: retourne 0 si le '*mot' est present dans 'arbre' */
int mot_est_present(char* mot, node* arbre);



/* 
descr:  determine la liste de mot commencant par un certain prefixe
param:  char* prefixe -> le prefixe commun aux mots qu on recherche
        pt* arbre     -> Patricia_Tries ou on va faire notre recherche 
retour: la liste des mot possedant '*prefixe' dans le Patricia_Tries */
char** mots_avec_prefixe(char* prefixe, node* arbre);



/* 
descr:  recherche du plus grand mot parmi ceux plus petits qu'un certain 
        mot dans le Patricia_Tries  
param:  char* mot -> cette fonction recherche le mot qui precede ce parametre
        pt* arbre -> Patricia_Tries ou on va faire notre recherche  
retour: le plus grand mot parmi ceux plus petits que '*mot' 
        mot dans le Patricia_Tries ou NULL si il n'y en a pas. */
char* mot_precedent(char* mot,node* arbre);


/* FAUX
descr:  recherche du plus petit mot parmi ceux plus petits qu'un certain 
        mot dans le Patricia_Tries  
param:  char* mot -> cette fonction recherche le mot qui precede ce parametre
        pt* arbre -> Patricia_Tries ou on va faire notre recherche  
retour: le plus grand mot parmi ceux plus petits que '*mot' 
        mot dans le Patricia_Tries ou NULL si il n'y en a pas. */
char* mot_suivant(char*, node* arbre);


int possede_fils(node* arbre);


