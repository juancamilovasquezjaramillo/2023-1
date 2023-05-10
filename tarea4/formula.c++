// juan camilo vasquez jaramillo 
// 8976396
// para este codigo me ayude de la sesion 14 y tambien de este pdf:http://informatica.uv.es/iiguia/FP/entrada-salida2.pdf
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numGrupos, numParticipantes;
    while (cin >> numGrupos >> numParticipantes && numGrupos != 0 && numParticipantes != 0) {
        vector<vector<int>> resultados(numGrupos, vector<int>(numParticipantes));
        for (int i = 0; i < numGrupos; i++) {
            for (int j = 0; j < numParticipantes; j++) {
                cin >> resultados[i][j];
            }
        }
        int numConsultas;
        cin >> numConsultas;
        while (numConsultas--) {
            int numGanadores;
            cin >> numGanadores;
            vector<int> ganadores(numGanadores);
            for (int i = 0; i < numGanadores; i++) {
                cin >> ganadores[i];
            }
            vector<int> puntajes(numParticipantes);
            int i = 0;
            while (i < numGrupos) {
                for (int j = 0; j < numParticipantes; j++) {
                    int lugar = resultados[i][j] - 1;
                    if (lugar < numGanadores) {
                        puntajes[j] += ganadores[lugar];
                    }
                }
                i++;
            }
int puntajeMaximo = *max_element(puntajes.begin(), puntajes.end());
int* campeones = NULL;
int numCampeones = 0; 
for (int i = 0; i < numParticipantes; i++) {
    if (puntajes[i] == puntajeMaximo) {
        numCampeones++;
        campeones = (int*) realloc(campeones, numCampeones * sizeof(int));
        campeones[numCampeones-1] = i + 1;
    }
}
sort(campeones, campeones + numCampeones);
for (int i = 0; i < numCampeones; i++) {
    if (i > 0) {
        cout << " ";
    }
    cout << campeones[i];
}
cout << endl;
free(campeones);
campeones = NULL;
        }
    }
    return 0;
}
