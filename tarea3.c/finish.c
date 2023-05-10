#include <stdio.h>

int finish() {
    int ejecuciones;
    scanf("%i", &ejecuciones);

    for (int g = 0; g < ejecuciones; g++) {
        int inicio = 0, n;
        scanf("%i", &n);

        int estaciones[n], consumo[n];
        for (int i = 0; i < n; i++) {
            scanf("%i", &estaciones[i]);
        }
        for (int x = 0; x < n; x++) {
            scanf("%i", &consumo[x]);
        }

        int ans = 0;
        int inicioans = 0;
        for (int i = 0; i < n; i++) {
            int tanque = 0, contador = 0;
            for (int x = 0; x < n; x++) {
                int j = (inicio + x) % n;
                tanque += estaciones[j];
                tanque -= consumo[j];
                if (tanque < 0) {
                    inicio = (inicio + x + 1) % n;
                    break;
                }
                contador++;
            }
            if (contador == n) {
                ans = 1;
                inicioans = inicio;
                break;
            }
        }

        if (ans != 1) {
             printf("Case %i: Not possible\n", g + 1);
        } else {
            printf("Case %i: Possible from station %i\n", g + 1, inicioans + 1);
        }
    }

    return 0;
}

int main() {
    finish();
    return 0;
}