#ifndef __GRAFO_H
#define __GRAFO_H

#include <stdio.h>
#include <stdlib.h>

/************************
* ESTRUCTURAS DE DATOS *
************************/

typedef struct zone {
  char name[30];
  char description[10000];
} Zone;

typedef struct grafo {
  Zone zona;
  int numeros[3];
  int size;

} Grafo;

#endif