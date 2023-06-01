#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int dato;
  struct nodo* sig;
};

typedef struct nodo* Lista;

Lista crearLista(){
  Lista lst;
  lst = NULL;
  return lst;
}

Lista anxLista(Lista lst, int elem) {
  Lista nuevo, tmp;
  nuevo = (Lista)malloc(sizeof(struct nodo));
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if (lst == NULL)
    lst = nuevo;
  else {
    tmp = lst;
    while (tmp->sig != NULL){
      tmp = tmp->sig;
    }
    tmp->sig = nuevo;
  }

  return lst;
}

int longLista(Lista lst){
  Lista tmp;
  int cont = 0;
  tmp = lst;
  
  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }
  
  return cont;
}

int busquedaBinaria(Lista lst,int valor){
    int acum = 0;
    Lista tmp;
    tmp = lst;
    while(tmp != NULL){
      tmp = tmp->sig;
      acum++;
    }
    int min = 0, max = acum - 1, mid;
    while (min <= max) {
        mid = (min + max) / 2;
        tmp = lst;
        for (int i = 0; i < mid; i++) {
            tmp = tmp->sig;
        }
        if (tmp->dato == valor) {
            return 1;
        }
        else if (tmp->dato < valor) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    return -1;
}

int main() {
    Lista list = crearLista();
    list = anxLista(list,2);
    list = anxLista(list,5);
    list = anxLista(list,6);
    list = anxLista(list,7);
    list = anxLista(list,9);
    list = anxLista(list,10);
    int x = 0;
    x = busquedaBinaria(list,2);
    if (x == 1) {
        printf("El numero si esta dentro de la lista");
    }
    else {
        printf("El elemento no esta en la lista");
    }
    return 0;
}