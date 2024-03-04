#include<iostream>
#include<vector>

using namespace std;

vector<int> g[10002];
bool vis[10002];

void dfs(int n) {
    if(!vis[n]) {
        vis[n] = true;
        for(int i = 0; i < g[n].size(); i++) dfs(g[n][i]);
    }
}

int main() {
    // test cases
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        // input n, m, l

        int n, m, l;
        cin >> n >> m >> l;

        // azzero i risultati dei precedenti test cases
        for(int i = 0; i < n; i++) {
            vis[i] = false;
            g[i].clear();
        }

        // input del grafo (attenzione agli indici)
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[a-1].push_back(b-1);
        }

        // input delle "partenze" del domino, faccio la dfs per trovare tutte le
        // tessere che cadono
        for(int i = 0; i < l; i++) {
            int z;
            cin >> z;
            dfs(z-1);
        }

        // conto le tessere che ho visitato
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) res++;
        }
        cout << res << endl;
    }
    return 0;
}