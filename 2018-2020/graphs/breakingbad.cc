#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<int> g[100002]; //grafo
int colors[100002]; //devo vedere se il grafo è bipartito, equivalente a 2-colorazione
bool impossible;

void dfs(int i, int c) { //mi porto dietro l'indice del nodo da visitare e il colore da assegnare
    if(colors[i] == -1) { //se non ho già assegnato un colore
        colors[i] = c; //assegno il colore
        for(int j = 0; j < g[i].size(); j++) {
            if(colors[g[i][j]] == c) impossible = true; //se a un nodo adiacente ho già assegnato un colore, verifico che non sia uguale al colore del nodo i
            else {
                dfs(g[i][j], 1 - c); //se è tutto ok, visito il nodo adiacente portandomi dietro il colore da assegnargli
            }
        }
    }
}

int main() {
    int N;
    map<string, int> m; //mappe per gestire le stringhe, nei due "versi", string to int e int to string (comodo per gli indici dei vettori di adiacenza)
    map<int, string> inv;

    cin >> N;

    for(int i = 0; i < N; i++) {
        string a;
        cin >> a;
        m[a] = i;
        inv[i] = a;
    }

    int M;
    cin >> M;

    for(int i = 0; i < M; i++) {
        string a, b;
        cin >> a >> b;
        int A = m[a];
        int B = m[b];

        g[A].push_back(B); //creazione del grafo
        g[B].push_back(A);
    }

    for(int i = 0; i < N; i++) colors[i] = -1; //colori nulli all'inizio

    for(int i = 0; i < N; i++) { //itero tutti i nodi
        if(colors[i] == -1) { //se non ho ancora assegnato un colore al nodo, assegno un colore a caso e visito i suoi adiacenti con una dfs
            dfs(i, 0);
        }
    }

    if(impossible) {
        cout << "impossible" << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        if(colors[i] == 0) {
            cout << inv[i] << " ";
        }
    }
    cout << endl;

    for(int i = 0; i < N; i++) {
        if(colors[i] == 1) {
            cout << inv[i] << " ";
        }
    }
    cout << endl;

    return 0;
}