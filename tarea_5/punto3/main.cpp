#include "lista.h"
#include <iostream>
// punto (a)
void insertarEnListaOrdenada(Lista &l, int v){
    for(int i = 1; i <= l.longLista(); i++){            //O(n)
        if(v <= l.infoLista(i)){                        // O(k)
            v.anxLista(l.infoLista(i))                   // O(n)
        }else if(v >= l.infoLista(i)){                   // O(k)
            v.anxLista(l.infoLista(i))                    // O(n)
        }else if(v == l.infoLista(i)){                    // O(k)
            v.anxLista(l.infoLista(i))                    // O(n)
        }
    }
    return 0;                                             // +1
}
// la complejidad de este codigo seria O(n**2k) en el peor caso, ya que el ciclo "for"recorre la lista l de longitud n,
//y dentro del ciclo se realizan operaciones de complejidad O(n) con la función anxLista() en el peor caso,
// además de la operación de complejidad O(k) de la función infoLista().
int main(){
    Lista l;
    l.anxLista(1);
    l.anxLista(2);
    l.anxLista(3);
    l.anxLista(4);
    l.anxLista(5);


    return 0;
}