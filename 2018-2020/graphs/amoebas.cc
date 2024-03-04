#include<iostream>
#include<vector>
using namespace std;

vector<string> m;
int N, M;
bool vis[102][102];

void dfs(int i, int j) {
    if(i < 0 || j < 0 || i >= M || j >= N) return;
    if(m[i][j] != '#') return;
    if(vis[i][j]) return;
    vis[i][j] = true;
    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i-1, j-1);
    dfs(i+1, j-1);
    dfs(i-1, j+1);
    dfs(i+1, j+1);
    dfs(i, j-1);
    dfs(i, j+1);
}

int main() {
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        string a;
        cin >> a;
        m.push_back(a);
    }

    int cont = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(m[i][j] == '#' && !vis[i][j]) {
                cont++;
                dfs(i, j);
            }
        }
    }

    cout << cont << endl;


    return 0;
}