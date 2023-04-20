#include <iostream>
#include "lista.h"

int contarOcurrencias(Lista &l, int v){
    int cont = 0;                                          // + 1
    for(int i = 1; i <= l.longLista(); i++){               // O(n)
        if(v == l.infoLista(i));                           // O(k)
        cont++;                                            // + 1

    }
    return cont;                                           // + 1
}
// la complejidad de este codigo es O(n*k) en el peor de los caso, osea si la lista contiene muchos elementos iguales a "v".
// si no esta seria de O(n) ya que el tiempo de comparación es constante.

int main(){
    Lista l;
    l.anxLista(2);
    l.anxLista(1);
    l.anxLista(4);
    l.anxLista(2);
    l.anxLista(2);


    return 0;
}

Lista obtenerMenores(Lista &l, int v){
    Lista j;                                         // +1
    for(int n = 1; n <= l.longLista(); n++){         // O(n)
        if(v >= l.infoLista(n)){                     // O(k)
            j.insLista(l.infoLista(n));              // O(n*k)
        }
    }
    return j;                                        //  +1
}
// la complejidad de este caso seria O(nk+n^2k) = O(n^2*k) 
// En el peor caso, si todos los elementos de la lista son menores que "v",
//se insertarán todos los elementos en la lista "j", por lo que la complejidad sería cuadrática.

int main(){
    Lista l;
    l.anxLista(2);
    l.anxLista(1);
    l.anxLista(4);
    l.anxLista(2);
    l.anxLista(2);

}