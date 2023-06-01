#ifndef __NODO_H
#define __NODO_H

#include <stdio.h>
#include <stdlib.h>

/************************
* PROYECTO TECNICAS *
************************/

typedef struct objeto {
  char name[30];
  int stats;
} Objeto;

typedef struct node {
  Objeto objeto;
  struct node *next;
} Node;


#endif