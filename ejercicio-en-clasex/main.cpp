#include <iostream>
#include "cola.h"

void colaOrdenada(Cola &c){
  while(!c.vaciaCola()){
     printf(c.front());
  }
}

int maian(){
    Cola c;
    c.enqueue(1);
    c.enqueue(4);
    c.enqueue(6);
    c.enqueue(8);
}