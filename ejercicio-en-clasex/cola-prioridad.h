
#ifndef  COLA_H
#define COLA_H

#include <vector>

typedef int Elemento;
using namespace std;

class Cola{
   vector<Elemento> vec;

   public:
      Cola(); // crearCola
      Elemento front();
      void deque();
      void enqueue(Elemento);
      bool vaciaCola();
};

#endif