#include <iostream>
#include <queue>

using namespace std;

int main() {
    int caso_prueba = 1;
    bool salirBucle = false;

    while (!salirBucle) {
        int P, C;
        cin >> P >> C;

        if (P == 0 && C == 0) {
            salirBucle = true;
        }

        if (!salirBucle) {
            cout << "Caso " << caso_prueba << ":" << endl;

            queue<int> cola_ciudadanos;

            for (int i = 1; i <= P && i <= C; i++) {
                cola_ciudadanos.push(i);
            }

            for (int i = 0; i < C; i++) {
                char comando;
                cin >> comando;

                if (comando == 'N') {
                    cout << cola_ciudadanos.front() << endl;
                    cola_ciudadanos.push(cola_ciudadanos.front());
                    cola_ciudadanos.pop();
                } else {
                    int x;
                    cin >> x;
                    queue<int> cola_temporal;

                    while (!cola_ciudadanos.empty()) {
                        int frente = cola_ciudadanos.front();
                        cola_ciudadanos.pop();
                        if (frente != x) {
                            cola_temporal.push(frente);
                        }
                    }

                    cola_ciudadanos.push(x);
                    while (!cola_temporal.empty()) {
                        cola_ciudadanos.push(cola_temporal.front());
                        cola_temporal.pop();
                    }
                }
            }

            caso_prueba++;
        }
    }

    return 0;
}

//La complejidad de este código es O(P + C),
//donde P es el número de veces que se ejecuta el bucle exterior y C es el número de veces que se ejecuta el bucle interior.