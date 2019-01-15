using namespace std;

#include <fstream>

int a[30];

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    int n,m;

    in >> n >> m;
    // leggo le posizioni di partenza
    for (int i=0; i<n; i++) {
        in >> a[i];
    }
    // per ogni sorpasso simulo la nuova classifica
    int sorpassante,sorpassato;
    int x,y,tmp; // indici del sorpassante e del sorpassato, variabile temporanea per lo swap
    for (int i=0; i<m; i++) {
        in >> sorpassante >> sorpassato;
        for (int j=0; j<n; j++) {
            if (a[j] == sorpassante) {
                x = j;
            } else if (a[j] == sorpassato) {
                y = j;
            }
        }
        tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }
    out << a[0];
    return 0;
}