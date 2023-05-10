#include <stdio.h>
#include <stdlib.h>

void jumpers() {
    int n;
    while (scanf("%i", &n) != EOF) {
        int contador = 0;
        int arreglo[n];
        for (int i = 0; i < n; ++i) {
            scanf("%i", &arreglo[i]);
        }
        for (int i = 1; i < n; ++i) {
            int formula = abs(arreglo[i-1] - arreglo[i]);
            if (formula > 0 && formula < n) {
                ++contador;
            }
        }
        if (contador == n - 1) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
}

int main() {
    jumpers();
    return 0;
}