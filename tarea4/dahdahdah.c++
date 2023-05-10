// juan camilo vasquez jaramillo 
// 8976396
// esta pagina me salvo la vida :] :https://www2.eii.uva.es/fund_inf/cpp/index.html
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> caracteres_morse = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?', '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '"','\'','@'};

vector<string> codigo_morse = {
    ".-",     // A
    "-...",   // B
    "-.-.",   // C
    "-..",    // D
    ".",      // E
    "..-.",   // F
    "--.",    // G
    "....",   // H
    "..",     // I
    ".---",   // J
    "-.-",    // K
    ".-..",   // L
    "--",     // M
    "-.",     // N
    "---",    // O
    ".--.",   // P
    "--.-",   // Q
    ".-.",    // R
    "...",    // S
    "-",      // T
    "..-",    // U
    "...-",   // V
    ".--",    // W
    "-..-",   // X
    "-.--",   // Y
    "--..",   // Z
    "-----",  // 0
    ".----",  // 1
    "..---",  // 2
    "...--",  // 3
    "....-",  // 4
    ".....",  // 5
    "-....",  // 6
    "--...",  // 7
    "---..",  // 8
    "----.",  // 9
    ".-.-.-", // .
    "--..--", // ,
    "..--..", // ?
    "-.-.--", // !
    "-..-.",  // /
    "-.--.",  // (
    "-.--.-", // )
    ".-...",  // &
    "---...", // :
    "-.-.-.", // ;
    "-...-",  // =
    ".-.-.",  // +
    "-....-", // -
    "..--.-", // _
    ".-..-.", // "
    ".----.",
    ".--.-.", // @
};

string decodificar_morse(string morse_msg) {
    string mensaje_decodificado = "";
    string letra_morse = "";
    int num_espacios = 0; 

    for (int i = 0; i < morse_msg.length(); i++) {
        if (morse_msg[i] == ' ') {
            if (letra_morse != "") {
                int j = 0;
                while (j < codigo_morse.size() && codigo_morse[j] != letra_morse) {
                    j++;
                }
                if (j < caracteres_morse.size()) {
                    mensaje_decodificado += caracteres_morse[j];
                }
                letra_morse = "";
            }
            num_espacios++;
        } else {
            if (num_espacios > 1) {
                mensaje_decodificado += " ";
            }
            num_espacios = 0; 
            letra_morse += morse_msg[i];
        }
    }

    int j = 0;
    while (j < codigo_morse.size() && codigo_morse[j] != letra_morse) {
        j++;
    }
    if (j < caracteres_morse.size()) {
        mensaje_decodificado += caracteres_morse[j];
    }
    
    return mensaje_decodificado;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    for (int i = 1; i <= T; i++) {
        string mensaje = "";
        string linea;
        getline(cin, linea);
        mensaje += linea + " ";
        
        mensaje.pop_back();
        
        string mensaje_decodificado = decodificar_morse(mensaje);
        
        cout << "Message #" << i << endl;
        cout << mensaje_decodificado << endl;
        if (i < T) {
            cout << endl;
        }
    }
    return 0;
}