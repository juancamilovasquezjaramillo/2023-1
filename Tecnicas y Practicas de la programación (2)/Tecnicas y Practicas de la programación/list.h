#ifndef __LISTA_H
#define __LISTA_H

#include "nodo.h"

/************************
* PROYECTO TECNICAS *
************************/
typedef struct list {
  Node *head;
  int size;
} List;


/* Constructoras */
List *crearLista();

/* Modificadoras */
void anxLista(List *lista, Objeto objeto);


/*Imprimir */
void imprimirLista(List *lista);

void imprimirObjeto(Node *nodo); 

#endif