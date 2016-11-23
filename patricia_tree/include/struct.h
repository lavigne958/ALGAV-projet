#ifndef STRUCT_H
#define STRUCT_H

#define PREFIX_MAX 20
#define NB_CHAR_MAX 127
#define EPSILON '_'

typedef struct node{
  char prefix[PREFIX_MAX];
  int size;
  struct node** tab_fils;
}node;

#endif

