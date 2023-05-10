// juan camilo vasquez jaramillo 
// 8976396
// para este me ayude de https://www.electroniclinic.com/c-vector-and-vector-bool-with-examples/ y el pdf http://informatica.uv.es/iiguia/FP/entrada-salida2.pdf
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> codigos;

void generar_todas_las_codificaciones() {
    int i = 0, j = 0, k = 0, l = 0;
    while (i <= 9) {
        while (j <= 9) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    string codificacion = to_string(i) + to_string(j) + to_string(k) + to_string(l);
                    codigos.push_back(codificacion);
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
}

bool coherente_con_suposicion(string codificacion, string suposicion, int digitos_correctos, int incorrectos_correctos) {
    int frecuencia_codificacion[10] = {0};
    int frecuencia_suposicion[10] = {0};
    int incorrectos_correctos_count = 0;
    int i = 0;
    while (i < 4) {
        if (codificacion[i] == suposicion[i]) {
            digitos_correctos--;
        } else {
            frecuencia_codificacion[codificacion[i] - '0']++;
            frecuencia_suposicion[suposicion[i] - '0']++;
        }
        i++;
    }
    int j = 0;
    while (j < 10) {
        incorrectos_correctos_count += min(frecuencia_codificacion[j], frecuencia_suposicion[j]);
        j++;
    }
    return (digitos_correctos == 0 && incorrectos_correctos_count == incorrectos_correctos);
}

bool coherente_con_todas_las_suposiciones(string codificacion, vector<pair<string, pair<int, int>>>& suposiciones) {
    for (auto suposicion : suposiciones) {
        if (!coherente_con_suposicion(codificacion, suposicion.first, suposicion.second.first, suposicion.second.second)) {
            return false;
        }
    }
    return true;
}

string resultado(vector<pair<string, pair<int, int>>>& suposiciones) {
    vector<string> posibles_codificaciones;
    for (auto codificacion : codigos) {
        if (coherente_con_todas_las_suposiciones(codificacion, suposiciones)) {
            posibles_codificaciones.push_back(codificacion);
        }
    }
    if (posibles_codificaciones.size() == 0) {
        return "impossible";
    } else if (posibles_codificaciones.size() == 1) {
        return posibles_codificaciones[0];
    } else {
        return "indeterminate";
    }
}

int main() {
    generar_todas_las_codificaciones();
    int numPruebas;
    cin >> numPruebas;
    for (int i = 0; i < numPruebas; i++) {
        int numSuposiciones;
        cin >> numSuposiciones;
        vector<pair<string, pair<int, int>>> suposiciones;
        for (int j = 0; j < numSuposiciones; j++) {
            string suposicion;
            int Lcorrectos, malUbiCorregido;
            cin >> suposicion >> Lcorrectos;
            cin.ignore();
            cin >> malUbiCorregido;
            suposiciones.push_back(make_pair(suposicion, make_pair(Lcorrectos, malUbiCorregido)));
        }
        cout << resultado(suposiciones) << endl;
    }
    return 0;
}