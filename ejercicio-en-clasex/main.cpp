#include <iostream>
#include "cola.h"

void colaOrdenada(Cola &c){
  while(!c.vaciaCola()){
     printf(c.front());
  }
}
// aun me faltaaaaaaaaaa
// aun no lo coloca en orden
int maian(){
    Cola c;
    c.enqueue(8);
    c.enqueue(4);
    c.enqueue(7);
    c.enqueue(1);
}
