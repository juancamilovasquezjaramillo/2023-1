#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

struct Equipo {
    string nombre;
    int puntos;
    int jugados;
    int goles_a_favor;
    int goles_en_contra;
    int diferencia_de_goles;

    bool operator<(const Equipo& otro) const {
        if (puntos != otro.puntos) {
            return puntos > otro.puntos;
        } else if (diferencia_de_goles != otro.diferencia_de_goles) {
            return diferencia_de_goles > otro.diferencia_de_goles;
        } else if (goles_a_favor != otro.goles_a_favor) {
            return goles_a_favor > otro.goles_a_favor;
        } else {
            return nombre < otro.nombre;
        }
    }
};

int main() {
    int T, G;
    while (cin >> T >> G && (T != 0 || G != 0)) {
        vector<Equipo> equipos(T);
        for (int i = 0; i < T; i++) {
            cin >> equipos[i].nombre;
            equipos[i].puntos = 0;
            equipos[i].jugados = 0;
            equipos[i].goles_a_favor = 0;
            equipos[i].goles_en_contra = 0;
            equipos[i].diferencia_de_goles = 0;
        }
        for (int i = 0; i < G; i++) {
            string local, visitante;
            int gl, gv;
            cin >> local >> gl >> gv >> visitante;
            for (int j = 0; j < T; j++) {
                if (equipos[j].nombre == local) {
                    equipos[j].jugados++;
                    equipos[j].goles_a_favor += gl;
                    equipos[j].goles_en_contra += gv;
                    if (gl > gv) {
                        equipos[j].puntos += 3;
                    } else if (gl == gv) {
                        equipos[j].puntos++;
                    }
                } else if (equipos[j].nombre == visitante) {
                    equipos[j].jugados++;
                    equipos[j].goles_a_favor += gv;
                    equipos[j].goles_en_contra += gl;
                    if (gv > gl) {
                        equipos[j].puntos += 3;
                    } else if (gl == gv) {
                        equipos[j].puntos++;
                    }
                }
            }
        }
        sort(equipos.begin(), equipos.end());
        cout << setw(4) << "Pos" << setw(16) << "Equipo" << setw(4) << "Pts" << setw(4) << "Jug" << setw(4) << "DG" << setw(4) << "%" << endl;
        for (int i = 0; i < T; i++) {
            Equipo& equipo = equipos[i];
            int porcentaje = 0;
            if (equipo.jugados > 0) {
                porcentaje = equipo.puntos * 100 / (equipo.jugados * 3);
            }
            cout << setw(4) << i + 1 << setw(16) << equipo.nombre << setw(4) << equipo.puntos << setw(4) << equipo.jugados << setw(4) << equipo.goles_a_favor - equipo.goles_en_contra << setw(4) << porcentaje << endl;
        }
        cout << endl;
    }
    return 0;
}