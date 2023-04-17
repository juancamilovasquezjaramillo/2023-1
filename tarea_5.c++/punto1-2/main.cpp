#include <iostream>
#include <list>

using namespace std;

int contarOcurrencias(list<int> l, int v) {
    int count = 0;
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (*it == v) {
            ++count;
        }
    }
    return count;
}

int main() {
    list<int> l = {1, 3, 2, 1, 4, 1, 5};
    int v = 1;
    int count = contarOcurrencias(l, v);
    cout << "El número " << v << " aparece " << count << " veces en la lista." << endl;
    return 0;
}
