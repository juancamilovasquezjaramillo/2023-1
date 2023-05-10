#include <iostream>
#include <list>
#include <string>
using namespace std;


int main(){
    string texto;
    while(getline(cin, texto)){;
        list<char> cadena;
        auto it = cadena.begin();

        for(char letra : texto){
            if(letra == '['){
                it = cadena.begin();
            }else if(letra == ']'){
                it = cadena.end();
            }else{
                cadena.insert(it, letra);          // O(1)
            }
        }
        for(char letra : cadena){
            cout << letra;
        }
        cout << endl;
    }
    return 0;
}

// La complejidad computacional de este código depende del tamaño de la entrada y de la operación de inserción en la lista
// el cual tiene una complejidad de tiempo promedio de O(1) para listas doblemente enlazadas,
//ya que solo necesita ajustar los enlaces de los nodos adyacentes.
// En general, la complejidad del código es lineal, O(N), donde N es el tamaño de la entrada.