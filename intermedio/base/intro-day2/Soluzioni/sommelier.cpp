#include <fstream>

using namespace std;

int a[100];
int n;

int assaggia(int i, int assaggiati, int ultimo) {
    if (i>=n) {
        return assaggiati;
    } else {
        if (a[i] >= ultimo) {
            // MAX tra assaggio questo vino e non assaggio questo vino
            return max(assaggia(i+2,assaggiati+1,a[i]),assaggia(i+1,assaggiati,ultimo));
        } else {    // non posso assaggiare questo vino in questa combinazione
            return assaggia(i+1,assaggiati,ultimo);
        }
    }
}

int main () {
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n;
    for (int i=0; i<n; i++) {
        in >> a[i];
    }

    out << assaggia(0,0,0);
    return 0;
}