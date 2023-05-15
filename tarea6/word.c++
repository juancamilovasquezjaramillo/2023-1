#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canFormWord(const string& word, const string& letters) {
    string availableLetters = letters;
    for (char c : word) {
        auto it = find(availableLetters.begin(), availableLetters.end(), c);
        if (it != availableLetters.end()) {
            availableLetters.erase(it);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> dictionary;

    string word;
    while (cin >> word && word != "#") {
        dictionary.push_back(word);
    }


    string line;
    getline(cin, line);
    while (getline(cin, line) && line != "#") {
        string letters;
        for (char c : line) {
            if (c != ' ') {
                letters += c;
            }
        }

        int result = 0;
        for (const string& word : dictionary) {
            if (canFormWord(word, letters)) {
                result++;
            }
        }

        cout << result << endl;
    }

    return 0;
}
// la complejidad del código proporcionado es aproximadamente O(n + m * (n * k)),
//donde n es el número de palabras en el diccionario,
//m es la longitud de las letras disponibles en cada línea y k es la longitud máxima de las palabras en el diccionario.
