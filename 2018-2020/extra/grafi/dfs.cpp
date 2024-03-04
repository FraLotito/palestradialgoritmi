#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

bool visited[N] = { false };
vector<vector<int> > graph;

void dfs(int node) {
    visited[node] = true;
    // Visita "node" in pre-ordine
    for (int i=0; i<graph[node].size(); i++) {
        int dest = graph[node][i];
        // visita l'arco da "node" a "dest"
        if (!visited[dest]) {
            dfs(dest);
        }
    }
    // Visita "node" in post-ordine
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

    dfs(0);

    return 0;
}