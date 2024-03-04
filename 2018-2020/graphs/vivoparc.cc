#include<iostream>
using namespace std;

//uso una matrice di adiacenza per evitare i problemi di ridondanza nei dati
//in input
int m[102][102];
int c[102];
int N;

// controlla se il colore è safe (non ci sono adiacenti dello stesso colore)
bool isSafeColor(int color, int n) {
    for(int i=1;i<=N;i++) if(m[n][i] == 1 && color == c[i]) return false;
    return true;
}

bool solve(int n) {
    if(n == N+1) return true; //se ho assegnato tutti i nodi, ho colorato tutto
    for(int j=1;j<=4; j++) { //provo tutti i colori
        if(isSafeColor(j, n)) { 
            c[n] = j; //se il colore è safe lo assegna e prova a vedere dove arriva
            if(solve(n+1)) return true; 
        }
    }
    c[n] = 0;
    return false;
}


int main() {
    while(cin >> N) {
        for(int i=0;i<102;i++) c[i] = 0;
        for(int i=0;i<102;i++) for(int j=0;j<102;j++) m[i][j] = 0;
        int a,b;
        char tmp;
        //evito di fare parsing delle righe
        while(cin>>a>>tmp>>b) {
            m[a][b] = 1;
            m[b][a] = 1;
        }
        solve(1); //assumo che ritorni sempre vero
        for(int i=1;i<=N;i++) cout<<i<<" "<<c[i]<<endl;
        //cout<<endl;
    }
    return 0;
}
