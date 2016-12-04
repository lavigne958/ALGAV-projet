#include <string.h>
#include <stdio.h>

#include "struct.h"
#include "util.h"
#include "access.h"

int search_word(node* nd, char* string){
  //terminal case: the prefix equal the string
  if( prefix_equals_string(nd,string)){
    //if it has epsilon then we found it
    if( prefix_has_epsilon(nd) ){
      printf("le mot %s est dans l'arbre\n",string);
      return 1;
    }else{
      //else the word is there but not a full word
      printf("le mot %s est dans l'arbre mais n'a pas epsilon\n",string);
      return -1;
    }
  }else{
    //recursive case
    printf("prefix: %s != string: %s\n",nd->prefix, string);
    int comon_prefix = taille_prefixe_commun(string, nd->prefix);

    /*
     * if the length of the string is smaler than the prefix
     * then the prefix can not be a sub word of the string
     * or if the comon prefix is smaller than the prefix 
     * same problem prefix is not a sub word of the string
     */
    if( strlen(string) <= (unsigned int)nd->size ||  comon_prefix < nd->size){
      printf("%s <= pref ou comon_prefix < pref\n",string);
      return 0;
    }else{
      //we found a common prefix so get the right child and recurse
      printf("%s à un préfixe commun\n",string);
      
      //cas ou la string est strictement plus grande que le prefixe avec le prefixe compris dedans
      char* sub_str = &string[comon_prefix];
      node* fils = get_fils_node(nd,sub_str[0]);
      
      //if the node doesn't have a child with the same first letter then the string is not present
      if(is_node_null(fils)){
	printf("le fils: %c vaut NULL, %s n'existe pas dans l'arbre\n",string[0],string);
	return 0;
      }
      
      printf("perfix egaux recherche %s dans le fils\n",sub_str);

      //recursive case
      return search_word(fils,sub_str);
    }
  }
}

int recherche_arbre(node* nd, char* string){
  return search_word(get_fils_node(nd,string[0]), string);
}
