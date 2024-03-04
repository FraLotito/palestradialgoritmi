#include<iostream>
#include<vector>
using namespace std;

vector<int> grafo[1002];
bool vis[1002];

void dfs(int i) {
    if(!vis[i]) {
        vis[i] = true;
        for(int j = 0; j < grafo[i].size(); j++) dfs(grafo[i][j]);
    }
}

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        int C = 0;
        for(int i = 0; i < N + 1; i++) vis[i] = false;
        for(int i = 0; i < N + 1; i++) grafo[i].clear();

        for(int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                dfs(i);
                C++;
            }
        }

        cout << C - 1 << endl;
    }


    return 0;
}