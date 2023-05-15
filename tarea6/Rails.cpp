#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool railPermutation(const vector<int>& permutation) {
    stack<int> coach;
    int required = 1;

    for (int i = 0; i < permutation.size(); i++) {//--------------------------------------
        if (permutation[i] == required) {                                               //
            required++;                                                                 //
        } else {                                                                        //
            while (!coach.empty() && coach.top() == required) {                         //
                coach.pop();                                                            //--- O(n)
                required++;                                                             //
            }                                                                           //
            coach.push(permutation[i]);                                                 //
        }                                                                               //
    }//------------------------------------------------------------------------------------

    while (!coach.empty() && coach.top() == required) {
        coach.pop();
        required++;
    }

    return coach.empty();
}

int main() {
    int ans;
    while (cin >> ans && ans != 0) {
        vector<int> permutation;
        permutation.push_back(ans);

        int N = ans;
        for (int i = 1; i < N; i++) {
            cin >> ans;
            permutation.push_back(ans);
        }

        if (railPermutation(permutation)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        cin >> ans;
        cout << endl;
    }

    return 0;
}
//la complejidad del algoritmo está dominada por el bucle principal en la función railPermutation,
//que tiene una complejidad de O(N).
//Los otros bucles y operaciones dentro del código tienen complejidad constante o no afectan significativamente la complejidad general del algoritmo.
//
//Aunque ya le alla sacado la complejidad el codigo me sigue presentando problemas a la hora de leer el input 