#include<iostream>
#include<vector>
using namespace std;

vector<int> g[200003];
bool vis[200003];

void dfs(int n) {
    if(!vis[n]) {
        vis[n] = true;
        for(int i = 0; i < g[n].size(); i++) dfs(g[n][i]);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    bool conn = true;

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            cout << i << endl;
            conn = false;
        }
    }

    if(conn) cout << "Connected" << endl;
    
    return 0;
}