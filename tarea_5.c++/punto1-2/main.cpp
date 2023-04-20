#include <iostream>
#include "lista.h"

int contarOcurrencias(Lista &l, int v){
    int cont = 0;
    for(int i = 1; i <= l.longLista(); i++){
        if(v == l.infoLista(i));
        cont++;

    }
    return cont;
}

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
    Lista j;
    for(int n = 1; n <= l.longLista(); n++){
        if(v >= l.infoLista(n)){
            j.insLista(l.infoLista(n));
        }
    }
    return j;
}

int main(){
    Lista l;
    l.anxLista(2);
    l.anxLista(1);
    l.anxLista(4);
    l.anxLista(2);
    l.anxLista(2);

}