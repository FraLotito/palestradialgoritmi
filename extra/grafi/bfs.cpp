#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 8;

bool visited[N] = { false };
vector<vector<int> > graph;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // Visita u qui
        for (int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    // Costruiamo il grafo
    graph.resize(N);
    graph[0].push_back(1);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(5);
    graph[5].push_back(7);
    graph[7].push_back(6);
    graph[6].push_back(4);

    bfs(0);

    return 0;
}
