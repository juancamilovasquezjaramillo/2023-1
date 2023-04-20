/*
 * Autor: Carlos Ramírez
 * Fecha de creación: 30 de Octubre
 * Fecha última modificación: 30 de Octubre
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Lista
 * Representación Estructuras Encadenadas Simples
 */

#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>

using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/
typedef int Elemento;

class Nodo{
   public:
     Elemento dato;
     Nodo* sig;
};

class Lista{
  private:
    Nodo* act;

  public:
    /************************
    * OPERACIONES DEL TAD *
    ************************/

    /* Constructoras */
    Lista();

    /* Modificadoras */
    void anxLista(Elemento elem);
    void insLista(Elemento elem, int pos);
    void elimLista(int pos);

    /* Analizadoras */
    Elemento infoLista(int pos);
    int longLista();
    bool vaciaLista();
};

#endif
