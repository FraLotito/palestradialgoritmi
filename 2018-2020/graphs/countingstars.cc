#include<iostream>
#include<vector>
using namespace std;


// array dei visitati
bool vis[105][105];


// DFS su una griglia, mi porto dietro in maniera ricorsiva la posizione che sto visitando (e la griglia m)
void dfs(vector<string> &m, int i, int j) {
    // se non ho già visitato, allora visito
    // ignoro le celle che non mi servono '#'
    if(!vis[i][j] && m[i][j] == '-') {
        vis[i][j] = true;

        // visito le quattro direzioni
        dfs(m, i-1, j); 
        dfs(m, i+1, j);
        dfs(m, i, j+1);
        dfs(m, i, j-1);
    }
}

int main() {
    int N, M;

    int T = 1;

    while(cin >> M >> N) {
        // griglia m
        vector<string> m;

        // azzero i visitati
        for(int i = 0; i < M + 3; i++) for(int j = 0; j < N+3; j++) vis[i][j] = false;

        // metto un bordo alla griglia in modo da non sforare nelle visite
        string border = "";
        for(int i = 0; i < N+2; i++) border += '#';

        m.push_back(border);

        // input griglia

        for(int i = 0; i < M; i++) {
            string a;
            cin >> a;
            a = '#' + a + '#';
            m.push_back(a);
        }

        m.push_back(border);

        int res = 0;

        // itero su tutte le celle
        // se è una cella utile, e non l'ho visitata, incremento il numero di componenti connesse e faccio partire una visita
        // per trovare tutte le celle collegate e segnarle come visitate

        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                if(m[i][j] != '#' && !vis[i][j]) {
                    res++;
                    dfs(m, i, j);
                }
            }
        }

        cout << "Case " << T++ << ": " << res << endl;
    }

    return 0;
}