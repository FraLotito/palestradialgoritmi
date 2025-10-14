// includi tutte le librerie presenti
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 35;
int N, M;
vector<int> g[MAXN];

void bfs_modificata()
{
  // {nodo, distanza da nodo 0}
  queue<pair<int, int>> q;
  q.push({0, 0});

  while (true)
  {
    int node = q.front().first;
    int dist = q.front().second;
    cout << "nodo: " << node << ", distanza: " << dist << '\n';
    q.pop();

    if (node == 0 && dist != 0)
    {
      // se siamo al nodo zero in un numero pari di passi, abbiamo fatto una strada inutile
      if (dist % 2 == 0)
        continue;
      // se la strada e' dispari, abbiamo trovato la strada piu' corta
      cout << dist;
      break;
    }

    for (int u : g[node])
    {
      q.push({u, dist + 1});
    }
  }
}

void stampa_grafo()
{
  for (int i = 0; i < N; i++)
  {
    cout << i << ": ";
    for (int u : g[i])
    {
      cout << u << ' ';
    }
    cout << '\n';
  }
}

int main()
{
  // per rendere il prendere l'input piu' efficente
  ios::sync_with_stdio(0);
  cin.tie(0);
  // devia il flusso input / output nei file indicati
  freopen("input.txt", "r", stdin); // r = read, lettura
  // freopen("output.txt", "w", stdout); // w = write, scrittura

  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bfs_modificata();

  cout << '\n'
       << '\n';
  stampa_grafo();
}