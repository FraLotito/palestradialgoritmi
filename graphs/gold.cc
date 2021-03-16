#include<iostream>
using namespace std;

int N, M;

char m[56][56]; //mappa
int G = 0; //risultato
bool vis[56][56]; //visitati

void dfs(int i, int j) {
    if(vis[i][j]) return; //già visitato
    vis[i][j] = true; // visito la cella
    if(m[i][j] == 'G') G++; //se gold, incremento
    if(m[i][j] == '#') return; // se muro esco
    if(m[i-1][j] == 'T' || m[i+1][j] == 'T' || m[i][j-1] == 'T' || m[i][j+1] == 'T') return; //se c'è una trappola nei paraggi mi fermo
    else { //visito le quattro direzioni
        dfs(i, j-1);
        dfs(i-1, j);
        dfs(i+1, j);
        dfs(i, j+1);
    }
}

int main() {
    cin >> M >> N;
    int ip, jp;

    // input e mi salvo la posizione del giocatore
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> m[i][j];
            if(m[i][j] == 'P') {
                ip = i;
                jp = j;
            }
        }
    }

    //DFS dalla posizione del giocatore
    dfs(ip, jp);

    cout<<G<<endl;
    return 0;
}
